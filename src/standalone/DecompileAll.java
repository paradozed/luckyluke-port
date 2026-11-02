/*
 * Standalone Ghidra-based decompiler for Lucky.exe (Game.run).
 * Uses the full Ghidra classpath (not the restricted headless-script classpath).
 *
 * Compile:
 *   CP=$(find /opt/ghidra -name "*.jar" | tr '\n' ':')
 *   javac -cp "$CP" -d /tmp/decompile src/standalone/DecompileAll.java
 *
 * Run:
 *   java -cp "$CP:/tmp/decompile" standalone.DecompileAll \
 *       /mnt/dev/decomp-luckyluke/orig/Game.run \
 *       /mnt/dev/decomp-luckyluke/src/ghidra_c
 */

package standalone;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.util.importer.MessageLog;
import ghidra.app.util.importer.Reporter;
import ghidra.framework.options.SaveOptions;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Program;
import ghidra.util.task.TaskMonitor;
import ghidra.app.util.opinion.CompilerSpecID;
import ghidra.app.util.importer.ImportResult;
import ghidra.app.util.importer.ImportManager;
import ghidra.app.util.importer.AbstractAnalyzer;
import ghidra.program.model.lang.CompilerSpec;
import ghidra.program.model.lang.Language;
import ghidra.program.model.lang.LanguageRegistry;
import ghidra.program.model.listing.CodeUnit;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.section.Section;
import ghidra.program.model.symbol.SymbolTable;
import ghidra.app.services.Analyzer;
import ghidra.app.plugin.analyzer.AutoAnalysisManager;
import ghidra.app.cmd.function.AutoFunctionCmd;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;

import java.io.File;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

/**
 * Standalone decompiler: imports a PE, runs Ghidra analysis, decompiles every
 * function to C, and writes one .c file per function plus an index.
 */
public class DecompileAll {

    private static final int DECOMPILE_TIMEOUT_SECONDS = 120;

    public static void main(String[] args) throws Exception {
        if (args.length < 2) {
            System.err.println("usage: DecompileAll <pe-file> <output-dir>");
            System.exit(2);
        }
        File peFile = new File(args[0]);
        File outDir = new File(args[1]);
        if (!outDir.exists()) {
            outDir.mkdirs();
        }

        System.out.println("Importing: " + peFile.getAbsolutePath());

        // --- Import the PE into a Ghidra Program ---
        MessageLog log = new MessageLog();
        Reporter reporter = new Reporter() {
            public void setProgress(int i, int i1) {}
            public boolean isCancelled() { return false; }
            public void checkCancelled() {}
            public String getMessage() { return null; }
        };
        SaveOptions saveOptions = new SaveOptions();

        ImportResult result = ImportManager.importFiles(
                new File[]{peFile}, null, log, reporter, saveOptions);
        if (!result.isSuccess() || result.getProgram() == null) {
            System.err.println("Import failed: " + result.getMessages());
            System.exit(1);
        }
        Program program = result.getProgram();
        System.out.println("Imported: " + program.getName() +
                "  imageBase=0x" + Long.toHexString(program.getImageBase().getOffset()) +
                "  size=" + program.getMemory().getSize());

        // --- Run auto-analysis ---
        System.out.println("Running auto-analysis...");
        AutoAnalysisManager analysisMgr = AutoAnalysisManager.getAnalysisManager(program);
        analysisMgr.reanalyzeAll(null, TaskMonitor.DUMMY);
        System.out.println("Analysis complete.");

        // --- Decompile every function ---
        File indexFile = new File(outDir, "_index.tsv");
        PrintWriter index = new PrintWriter(new BufferedWriter(
                new OutputStreamWriter(Files.newOutputStream(indexFile.toPath()), StandardCharsets.UTF_8)));
        index.println("name\taddress\tnamespace\tretval\tfile\tstatus");

        DecompInterface iface = new DecompInterface();
        if (!iface.openProgram(program)) {
            System.err.println("DecompInterface openProgram failed: " + iface.getLastMessage());
            System.exit(1);
        }

        FunctionManager fm = program.getFunctionManager();
        int count = 0;
        int failed = 0;

        for (Function f : fm.getFunctions(true)) {
            String name = f.getName();
            Address entry = f.getEntryPoint();
            String safe = safeName(name, entry);
            String ret = (f.getReturnType() != null) ? f.getReturnType().toString() : "void";
            String ns = f.getParentNamespace().getName();

            DecompileResults res = iface.decompileFunction(f, DECOMPILE_TIMEOUT_SECONDS, TaskMonitor.DUMMY);
            if (res == null || !res.decompileCompleted()) {
                failed++;
                String err = (res == null) ? "null" : res.getErrorMessage() +
                        " (timeout=" + res.isTimedOut() + ")";
                System.out.println("FAIL " + name + "@" + entry + ": " + err);
                emitStub(outDir, safe, name, entry, ret, ns, err);
                index.println(name + "\t" + entry + "\t" + safe + ".c\t" + ns + "\t" + ret + "\tFAILED");
                continue;
            }

            String c = res.getDecompiledFunction().getC();
            File cf = new File(outDir, safe + ".c");
            try (PrintWriter pw = new PrintWriter(new BufferedWriter(
                    new OutputStreamWriter(Files.newOutputStream(cf.toPath()), StandardCharsets.UTF_8)))) {
                pw.println("/* " + name + " @ " + entry + " */");
                pw.println("/* decompiled from Lucky.exe (Game.run) */");
                pw.println();
                pw.print(c);
            }
            index.println(name + "\t" + entry + "\t" + safe + ".c\t" + ns + "\t" + ret + "\tOK");
            count++;
            if (count % 100 == 0) {
                System.out.println("decompiled " + count + " functions...");
            }
        }
        index.close();
        iface.closeProgram();
        program.close();

        System.out.println("DONE: decompiled " + count + " functions, " + failed + " failed -> " + outDir);
    }

    private static String safeName(String name, Address entry) {
        String base = name.replaceAll("[^A-Za-z0-9_.]", "_");
        return Long.toHexString(entry.getOffset()) + "__" + base;
    }

    private static void emitStub(File outDir, String safe, String name, Address entry,
                                 String ret, String ns, String err) {
        File cf = new File(outDir, safe + ".c");
        try (PrintWriter pw = new PrintWriter(new BufferedWriter(
                new OutputStreamWriter(Files.newOutputStream(cf.toPath()), StandardCharsets.UTF_8)))) {
            pw.println("/* FAILED: " + name + " @ " + entry + " */");
            pw.println("/* " + err + " */");
            pw.println(ret + " " + name + "(void);");
        } catch (Exception e) {
            // ignore
        }
    }
}
