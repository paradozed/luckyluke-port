/* ###
 * IP: GHIDRA
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
// Export all decompiled functions to C files.
// Obtains the program from the GhidraState (works in -postScript context),
// then decompiles every function to one .c file each.
// @category Scripts

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.app.script.GhidraState;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Program;
import ghidra.util.task.TaskMonitor;

import java.io.File;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.io.PrintWriter;

public class DecompileAllFunctions extends GhidraScript {

    @Override
    public void run() throws Exception {
        File outDir = new File("/mnt/dev/decomp-luckyluke/src/ghidra_c");
        if (!outDir.exists()) {
            outDir.mkdirs();
        }

        File indexFile = new File(outDir, "_index.tsv");
        PrintWriter index = new PrintWriter(new BufferedWriter(
                new OutputStreamWriter(Files.newOutputStream(indexFile.toPath()), StandardCharsets.UTF_8)));
        index.println("name\taddress\tnamespace\tretval\tfile\tstatus");

        Program prog = getProgram();
        if (prog == null) {
            println("ERROR: no program available from state");
            index.close();
            return;
        }
        println("Program: " + prog.getName() +
                " imageBase=0x" + Long.toHexString(prog.getImageBase().getOffset()));

        DecompInterface iface = new DecompInterface();
        if (!iface.openProgram(prog)) {
            println("ERROR: DecompInterface openProgram failed: " + iface.getLastMessage());
            index.close();
            return;
        }

        FunctionManager fm = prog.getFunctionManager();
        int count = 0;
        int failed = 0;

        for (Function f : fm.getFunctions(true)) {
            String name = f.getName();
            Address entry = f.getEntryPoint();
            String safe = safeName(name, entry);
            String ret = (f.getReturnType() != null) ? f.getReturnType().toString() : "void";
            String ns = f.getParentNamespace().getName();

            DecompileResults res = iface.decompileFunction(f, 120, monitor);
            if (res == null || !res.decompileCompleted()) {
                failed++;
                String err = (res == null) ? "null" :
                        res.getErrorMessage() + " (timeout=" + res.isTimedOut() + ")";
                println("FAIL " + name + "@" + entry + ": " + err);
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
                println("decompiled " + count + " functions...");
            }
        }
        index.close();
        iface.closeProgram();
        println("DONE: decompiled " + count + " functions, " + failed + " failed -> " + outDir);
    }

    private Program getProgram() {
        Program p = currentProgram;
        if (p != null) return p;
        GhidraState st = getState();
        if (st != null) return st.getCurrentProgram();
        return null;
    }

    private String safeName(String name, Address entry) {
        String base = name.replaceAll("[^A-Za-z0-9_.]", "_");
        return Long.toHexString(entry.getOffset()) + "__" + base;
    }

    private void emitStub(File outDir, String safe, String name, Address entry,
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
