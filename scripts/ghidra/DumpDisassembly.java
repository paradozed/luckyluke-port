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
// Export a complete, byte-exact disassembly of all executable memory blocks.
// Every byte of each block is accounted for: instructions are disassembled;
// non-instruction bytes are emitted as .byte directives for reassembly.
// Uses base Ghidra APIs only.
// @category Scripts

import ghidra.app.script.GhidraScript;
import ghidra.app.script.GhidraState;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.SymbolTable;
import ghidra.program.model.listing.Program;
import ghidra.util.task.TaskMonitor;

import java.io.File;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class DumpDisassembly extends GhidraScript {

    @Override
    public void run() throws Exception {
        File outDir = new File("/mnt/dev/decomp-luckyluke/src/asm");
        if (!outDir.exists()) {
            outDir.mkdirs();
        }

        Program prog = getProgram();
        if (prog == null) {
            println("ERROR: no program available from state");
            return;
        }
        println("Program: " + prog.getName());

        Listing listing = prog.getListing();
        Memory mem = prog.getMemory();
        SymbolTable symtab = prog.getSymbolTable();
        long imageBase = prog.getImageBase().getOffset();

        List<MemoryBlock> execBlocks = new ArrayList<>();
        for (MemoryBlock block : mem.getBlocks()) {
            if (block.isExecute()) {
                execBlocks.add(block);
            }
        }

        println("Executable memory blocks: " + execBlocks.size());
        long totalBytes = 0;
        long totalInsns = 0;
        long totalDataBytes = 0;

        File indexFile = new File(outDir, "_index.tsv");
        try (PrintWriter index = new PrintWriter(new BufferedWriter(
                new OutputStreamWriter(Files.newOutputStream(indexFile.toPath()), StandardCharsets.UTF_8)))) {
            index.println("block\tstart_rva\tend_rva\tsize\tfile\tinstructions\tdata_bytes");

            for (MemoryBlock block : execBlocks) {
                String bname = block.getName();
                String safe = bname.replaceAll("[^A-Za-z0-9_.]", "_");
                File asmFile = new File(outDir, safe + ".asm");
                long startOff = block.getStart().getOffset();
                long endOff = block.getEnd().getOffset();

                index.println(bname + "\t" + toHex(startOff - imageBase) + "\t" +
                        toHex(endOff - imageBase) + "\t" + (endOff - startOff + 1) + "\t" +
                        safe + ".asm");

                try (PrintWriter pw = new PrintWriter(new BufferedWriter(
                        new OutputStreamWriter(Files.newOutputStream(asmFile.toPath()), StandardCharsets.UTF_8)))) {
                    pw.println("; " + bname + " - byte-exact disassembly");
                    pw.println("; imageBase=0x" + toHex(imageBase));
                    pw.println("; block RVA " + toHex(startOff - imageBase) + " .. " +
                            toHex(endOff - imageBase));
                    pw.println("; size=" + (endOff - startOff + 1) + " bytes");
                    pw.println("; .686p");
                    pw.println("; .model flat, stdcall");
                    pw.println("; option casemap:none");
                    pw.println("; Reassembly: reassemble to a flat binary, then splice bytes at");
                    pw.println(";   the matching file offset to rebuild a byte-identical PE.");
                    pw.println();

                    Address addr = block.getStart();
                    Address last = block.getEnd();
                    int insnCount = 0;
                    int dataBytes = 0;
                    while (true) {
                        Instruction ins = listing.getInstructionAt(addr);
                        if (ins != null && ins.getAddress().equals(addr)) {
                            pw.print(formatInsn(ins, symtab, imageBase));
                            pw.println();
                            insnCount++;
                            addr = ins.getMaxAddress();
                        } else {
                            byte b = mem.getByte(addr);
                            if (dataBytes % 12 == 0) {
                                pw.print("\t.byte ");
                            }
                            pw.append(String.format("0x%02x", b & 0xff));
                            dataBytes++;
                            if (dataBytes % 12 == 0 || addr.equals(last)) {
                                pw.println();
                            } else {
                                pw.append(", ");
                            }
                            addr = addr.next();
                        }
                        if (addr.compareTo(last) > 0) {
                            break;
                        }
                    }
                    totalBytes += (endOff - startOff + 1);
                    totalInsns += insnCount;
                    totalDataBytes += dataBytes;
                    println("  " + bname + ": " + insnCount + " instructions, " +
                            dataBytes + " data bytes");
                }
            }
            index.close();
        }

        println("DONE: " + totalBytes + " bytes, " + totalInsns + " instructions, " +
                totalDataBytes + " data bytes -> " + outDir);
    }

    private Program getProgram() {
        Program p = currentProgram;
        if (p != null) return p;
        GhidraState st = getState();
        if (st != null) return st.getCurrentProgram();
        return null;
    }

    private String formatInsn(Instruction ins, SymbolTable symtab, long imageBase) throws Exception {
        StringBuilder sb = new StringBuilder();
        Address a = ins.getAddress();
        long rva = a.getOffset() - imageBase;
        sb.append(String.format("%-10s", "0x" + toHex(rva)));
        sb.append("\t");
        sb.append(ins.toString());
        byte[] bytes = ins.getBytes();
        if (bytes != null && bytes.length > 0) {
            sb.append("   ; bytes:");
            for (byte b : bytes) {
                sb.append(String.format("%02x", b));
            }
        }
        return sb.toString();
    }

    private String toHex(long v) {
        return Long.toHexString(v).toUpperCase();
    }
}
