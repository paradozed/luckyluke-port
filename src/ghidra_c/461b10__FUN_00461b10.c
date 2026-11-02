/* FUN_00461b10 @ 00461b10 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00461b10(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_80 [16];
  int *local_40;
  int *local_3c;
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
  local_3c = *(int **)(*(int *)(DAT_004f2458 + 0x9c) + 8);
  local_40 = *(int **)(&DAT_004f2580 + (uint)DAT_004f2596 * 4);
  if (DAT_004f2564 != '\0') {
    FUN_0040da10(local_40,0,local_1c);
    FUN_0040da10(local_3c,0,local_34);
    if (*(char *)(DAT_004f2458 + 0x74) == '\0') {
      if (local_34[0] < local_10) {
        *(int *)(*local_3c + 0x90) = *(int *)(*local_3c + 0x90) + (local_10 - local_34[0]);
      }
    }
    else if (local_1c[0] < local_28) {
      *(int *)(*local_3c + 0x90) = *(int *)(*local_3c + 0x90) - (local_28 - local_1c[0]);
    }
  }
  uStack_8 = 0x461bea;
  __chkesp();
  return;
}

