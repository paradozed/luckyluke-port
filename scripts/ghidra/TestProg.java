// Test: is currentProgram bound in postScript?
import ghidra.app.script.GhidraScript;
import ghidra.app.script.GhidraState;
import ghidra.program.model.listing.Program;

public class TestProg extends GhidraScript {
    @Override
    public void run() throws Exception {
        println("currentProgram=" + currentProgram);
        GhidraState st = getState();
        println("state=" + st);
        if (st != null) println("state.getCurrentProgram()=" + st.getCurrentProgram());
        if (currentProgram != null) {
            println("program name=" + currentProgram.getName());
            println("imageBase=0x" + Long.toHexString(currentProgram.getImageBase().getOffset()));
        }
    }
}
