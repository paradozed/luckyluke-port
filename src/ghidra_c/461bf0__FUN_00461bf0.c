/* FUN_00461bf0 @ 00461bf0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00461bf0(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_80 [16];
  int *local_40;
  int *local_3c;
  int local_38;
  int local_34 [3];
  int local_28;
  int local_1c [3];
  int local_10;
  undefined4 uStack_8;
  
  puVar4 = local_80;
  for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_3c = *(int **)(*(int *)(DAT_004f2458 + 0x9c) + 8);
  local_40 = *(int **)(&DAT_004f2580 + (uint)DAT_004f2596 * 4);
  FUN_0040da10(local_40,0,local_1c);
  FUN_0040da10(local_3c,0,local_34);
  local_38 = FUN_004975e0(local_34[0] - local_28);
  uVar1 = FUN_0040d810(local_1c,local_34);
  if ((short)uVar1 != 0) {
    if (*(char *)(DAT_004f2458 + 0x74) == '\0') {
      if ((int)((uint)DAT_004e87ba - local_38) < local_10) {
        iVar3 = *local_40;
        iVar2 = FUN_004975e0(local_10 - local_34[0]);
        *(int *)(*local_40 + 0x90) = *(int *)(iVar3 + 0x90) - iVar2;
        goto LAB_00461d94;
      }
    }
    else if (local_1c[0] < (int)((uint)DAT_004e87b8 + local_38)) {
      iVar3 = *local_40;
      iVar2 = FUN_004975e0(local_28 - local_1c[0]);
      *(int *)(*local_40 + 0x90) = *(int *)(iVar3 + 0x90) + iVar2;
      goto LAB_00461d94;
    }
    if ((local_34[0] < local_10) && (local_10 < local_28)) {
      iVar3 = *local_40;
      iVar2 = FUN_004975e0(local_34[0] - local_10);
      *(int *)(*local_40 + 0x90) = *(int *)(iVar3 + 0x90) - iVar2;
      DAT_004e8811 = 1;
    }
    else if ((local_1c[0] < local_28) && (local_34[0] < local_1c[0])) {
      iVar3 = *local_40;
      iVar2 = FUN_004975e0(local_28 - local_1c[0]);
      *(int *)(*local_40 + 0x90) = *(int *)(iVar3 + 0x90) + iVar2;
      DAT_004e8811 = 1;
    }
  }
LAB_00461d94:
  uStack_8 = 0x461da1;
  __chkesp();
  return;
}

