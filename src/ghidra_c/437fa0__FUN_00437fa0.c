/* FUN_00437fa0 @ 00437fa0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00437fa0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004e84cc != (int *)0x0) {
    FUN_00498130(DAT_004e84cc,(byte *)"<HTML>\n");
    FUN_00498130(DAT_004e84cc,(byte *)"<HEADER>\n");
    FUN_00498130(DAT_004e84cc,(byte *)"   <TITLE>Memory allocation manager output</TITLE>\n");
    FUN_00498130(DAT_004e84cc,(byte *)"</HEADER>\n");
    FUN_00498130(DAT_004e84cc,(byte *)"<BODY>\n");
    FUN_00498130(DAT_004e84cc,(byte *)"<H2><CENTER>Memory Allocation Manager Log</CENTER></H2>\n");
    FUN_00498130(DAT_004e84cc,(byte *)"<BR><BR>\n");
    FUN_00498130(DAT_004e84cc,(byte *)"<HR width=70%%>\n");
    FUN_00498130(DAT_004e84cc,(byte *)"<BR><BR>\n");
    FUN_00498130(DAT_004e84cc,(byte *)"<b>Legend:</b><BR><BR>\n");
    FUN_00498130(DAT_004e84cc,(byte *)"Black - Normal allocations<BR>\n");
    FUN_00498130(DAT_004e84cc,(byte *)"<FONT color=00AA00>Green</FONT> - Safe deallocations<BR>\n");
    FUN_00498130(DAT_004e84cc,(byte *)"<FONT color=AA0000>Red</FONT> - Any errors<BR>\n");
    FUN_00498130(DAT_004e84cc,(byte *)"<FONT color=0000AA>Blue</FONT> - Statistics<BR>\n");
    FUN_00498130(DAT_004e84cc,(byte *)"<BR>\n");
    FUN_00498130(DAT_004e84cc,(byte *)"<HR width=70%%>\n");
    FUN_00498130(DAT_004e84cc,(byte *)"<BR><BR>\n");
  }
  uStack_8 = 0x438121;
  __chkesp();
  return;
}

