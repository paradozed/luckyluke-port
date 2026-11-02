/* FUN_00461250 @ 00461250 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00461250(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_80 [16];
  undefined2 local_40;
  undefined2 uStack_3e;
  int *local_3c;
  int *local_38;
  int local_34 [3];
  int local_28;
  int local_1c [3];
  int local_10;
  undefined4 uStack_8;
  
  puVar2 = local_80;
  for (iVar1 = 0x1f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_38 = *(int **)(*(int *)(DAT_004f2458 + 0x9c) + 8);
  local_3c = *(int **)(&DAT_004f2580 + (uint)DAT_004f2596 * 4);
  FUN_0040da10(local_3c,0,local_1c);
  FUN_0040da10(local_38,0,local_34);
  if (*(char *)(DAT_004f2458 + 0x74) == '\0') {
    iVar1 = FUN_004975e0(local_10 - local_34[0]);
    _local_40 = CONCAT22(uStack_3e,(short)iVar1);
  }
  else {
    iVar1 = FUN_004975e0(local_28 - local_1c[0]);
    _local_40 = CONCAT22(uStack_3e,(short)iVar1);
  }
  uStack_8 = 0x46130e;
  __chkesp();
  return;
}

