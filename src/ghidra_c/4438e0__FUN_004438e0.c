/* FUN_004438e0 @ 004438e0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004438e0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  int local_c;
  int local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_00458ec0();
  FUN_00458ec0();
  FUN_00458ec0();
  local_c = DAT_004d1e90;
  FUN_00458ec0();
  if ((((DAT_004e8914 == 9) || (DAT_004e8914 == 0x11)) || (DAT_004e8914 == 10)) ||
     (DAT_004e8914 == 1)) {
    local_c = local_c + 1;
  }
  DAT_004e856c = 0x10 - local_c;
  FUN_00458ec0();
  FUN_00458ec0();
  DAT_004e8574 = (void *)FUN_00494c40(DAT_004e856c << 2,1);
  if (DAT_004e8574 != (void *)0x0) {
    _memset(DAT_004e8574,0,DAT_004e856c << 2);
    FUN_00458ec0();
    for (local_8 = 0; local_8 < DAT_004e856c; local_8 = local_8 + 1) {
      *(int *)((int)DAT_004e8574 + local_8 * 4) = local_c + local_8;
    }
    DAT_004e8570 = 0;
    FUN_00458ec0();
    FUN_00458ec0();
  }
  local_8 = 0x443a54;
  __chkesp();
  return;
}

