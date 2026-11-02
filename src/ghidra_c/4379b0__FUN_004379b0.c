/* FUN_004379b0 @ 004379b0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004379b0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004e84cc != (int *)0x0) {
    FUN_00498130(DAT_004e84cc,(byte *)"<BR><BR>\n");
    FUN_00498130(DAT_004e84cc,(byte *)"<HR width=70%%>\n");
    FUN_00498130(DAT_004e84cc,(byte *)"<BR><b>HEAP DUMP:</b> %s<BR>\n");
    FUN_00498130(DAT_004e84cc,(byte *)"<HR width=70%%>\n");
    FUN_00498130(DAT_004e84cc,(byte *)"<BR><BR>\n");
    if (DAT_004e84d4 != (int *)0x0) {
      for (local_8 = *DAT_004e84d4; local_8 != 0; local_8 = *(int *)(local_8 + 4)) {
        FUN_00438540();
      }
    }
    FUN_00498130(DAT_004e84cc,(byte *)"<BR><BR>\n");
    FUN_00498130(DAT_004e84cc,(byte *)"<HR width=70%%>\n");
    FUN_00498130(DAT_004e84cc,(byte *)"<BR><BR>\n");
  }
  local_8 = 0x437ac0;
  __chkesp();
  return;
}

