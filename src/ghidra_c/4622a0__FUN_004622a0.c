/* FUN_004622a0 @ 004622a0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004622a0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  int local_c;
  uint local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004e880e == '\0') {
    if (DAT_004e880f != '\0') {
      local_c = DAT_004e8818 - 6;
      switch(local_c) {
      case 0:
        if (DAT_004f2598 != FUN_004606c0) {
          DAT_004f2598 = FUN_00460670;
          FUN_00460670();
        }
        break;
      case 1:
        if (DAT_004f2598 != FUN_00460860) {
          DAT_004f2598 = FUN_00460810;
          FUN_00460810();
        }
        break;
      case 2:
        if (DAT_004f2598 != FUN_00460520) {
          DAT_004f2598 = FUN_004604d0;
          FUN_004604d0();
        }
        break;
      case 4:
        if (DAT_004f2598 != FUN_00461370) {
          DAT_004f2598 = FUN_00461320;
          FUN_00461320();
        }
      }
    }
    goto switchD_0046235a_caseD_3;
  }
  DAT_004e880e = '\0';
  local_8 = (uint)DAT_004e8818;
  if (local_8 != 2) {
    if (local_8 != 4) goto switchD_0046235a_caseD_3;
    if (DAT_004f2598 != FUN_0045ffd0) {
      DAT_004f2598 = FUN_0045ff60;
      FUN_0045ff60();
      goto switchD_0046235a_caseD_3;
    }
  }
  if (DAT_004f2598 != FUN_0045fe30) {
    DAT_004f2598 = FUN_0045fdc0;
    FUN_0045fdc0();
  }
switchD_0046235a_caseD_3:
  local_8 = 0x4623e6;
  __chkesp();
  return;
}

