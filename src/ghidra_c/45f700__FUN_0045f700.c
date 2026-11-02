/* FUN_0045f700 @ 0045f700 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0045f700(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_7c [16];
  int *local_3c;
  int *local_38;
  int local_34 [3];
  int local_28;
  int local_1c [3];
  int local_10;
  undefined4 uStack_8;
  
  puVar3 = local_7c;
  for (iVar2 = 0x1e; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_38 = *(int **)(*(int *)(DAT_004f2458 + 0x9c) + 8);
  local_3c = *(int **)(&DAT_004f2580 + (uint)DAT_004f2596 * 4);
  FUN_0040da10(local_3c,0,local_1c);
  FUN_0040da10(local_38,0,local_34);
  if ((DAT_004f2596 != 0) || (*(short *)(*(int *)(DAT_004f1578 + 4) + 0x32) != 0)) {
    if (*(char *)(DAT_004f2458 + 0x74) == '\0') {
      if ((int)(uint)DAT_004e87ba < local_28) {
        iVar2 = *local_38;
        iVar1 = FUN_004975e0((uint)DAT_004e87ba - local_28);
        *(int *)(*local_38 + 0x90) = *(int *)(iVar2 + 0x90) - iVar1;
      }
      if (local_1c[0] < (int)(uint)DAT_004e87b8) {
        iVar2 = *local_3c;
        iVar1 = FUN_004975e0((uint)DAT_004e87b8 - local_1c[0]);
        *(int *)(*local_3c + 0x90) = *(int *)(iVar2 + 0x90) + iVar1;
        DAT_004e8811 = 1;
      }
    }
    else {
      if (local_34[0] < (int)(uint)DAT_004e87b8) {
        iVar2 = *local_38;
        iVar1 = FUN_004975e0((uint)DAT_004e87b8 - local_34[0]);
        *(int *)(*local_38 + 0x90) = *(int *)(iVar2 + 0x90) + iVar1;
      }
      if ((int)(uint)DAT_004e87ba < local_10) {
        iVar2 = *local_3c;
        iVar1 = FUN_004975e0((uint)DAT_004e87ba - local_10);
        *(int *)(*local_3c + 0x90) = *(int *)(iVar2 + 0x90) - iVar1;
        DAT_004e8811 = 1;
      }
    }
  }
  uStack_8 = 0x45f897;
  __chkesp();
  return;
}

