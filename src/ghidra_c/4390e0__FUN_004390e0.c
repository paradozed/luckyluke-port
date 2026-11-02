/* FUN_004390e0 @ 004390e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004390e0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_148 [16];
  int *local_108;
  CHAR local_104 [252];
  undefined4 uStack_8;
  
  puVar3 = local_148;
  for (iVar2 = 0x51; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  FUN_00497080(local_104,0x4b69fc);
  uVar1 = FUN_00497d00(local_104,"wb");
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  if (*(int *)(param_1 + 0xc) != 0) {
    local_108 = *(int **)(param_1 + 0xc);
    FUN_00498130(local_108,(byte *)"<HTML>\n");
    FUN_00498130(local_108,(byte *)"<HEADER>\n");
    FUN_00498130(local_108,(byte *)"   <TITLE>Memory Pool allocation manager output</TITLE>\n");
    FUN_00498130(local_108,(byte *)"</HEADER>\n");
    FUN_00498130(local_108,(byte *)"<BODY>\n");
    FUN_00498130(local_108,(byte *)"<H2><CENTER>Memory Pool Allocation Manager Log</CENTER></H2>\n")
    ;
    FUN_00498130(local_108,(byte *)"<BR>\n");
    FUN_00498130(local_108,(byte *)"<H3><CENTER>Pool: %s</CENTER></H3>\n");
    FUN_00498130(local_108,(byte *)"<BR><BR>\n");
    FUN_00498130(local_108,(byte *)"<HR width=70%%>\n");
    FUN_00498130(local_108,(byte *)"<BR><BR>\n");
    FUN_00498130(local_108,(byte *)"<b>Legend:</b><BR><BR>\n");
    FUN_00498130(local_108,(byte *)"Black - Normal allocations<BR>\n");
    FUN_00498130(local_108,(byte *)"<FONT color=00AA00>Green</FONT> - Safe deallocations<BR>\n");
    FUN_00498130(local_108,(byte *)"<FONT color=AA0000>Red</FONT> - Any errors<BR>\n");
    FUN_00498130(local_108,(byte *)"<FONT color=0000AA>Blue</FONT> - Statistics<BR>\n");
    FUN_00498130(local_108,(byte *)"<BR>\n");
    FUN_00498130(local_108,(byte *)"<HR width=70%%>\n");
    FUN_00498130(local_108,(byte *)"<BR><BR>\n");
  }
  uStack_8 = 0x4392e0;
  __chkesp();
  return;
}

