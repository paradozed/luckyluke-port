/* FUN_00464ab0 @ 00464ab0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00464ab0(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_84 [16];
  int *local_44;
  int *local_40;
  int local_3c;
  int local_38 [3];
  int local_2c;
  int local_20 [3];
  int local_14;
  int local_8;
  
  puVar3 = local_84;
  for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = **(int **)(*(int *)(DAT_004f2458 + 0x9c) + 8);
  local_40 = *(int **)(*(int *)(DAT_004f2458 + 0x9c) + 8);
  local_44 = *(int **)(&DAT_004f2580 + (uint)DAT_004f2596 * 4);
  FUN_0040da10(local_40,0,local_20);
  FUN_0040da10(local_44,0,local_38);
  local_3c = FUN_004975e0(local_38[0] - local_2c);
  uVar1 = FUN_0040d810(local_20,local_38);
  if ((short)uVar1 != 0) {
    if (*(char *)(DAT_004f2458 + 0x74) == '\0') {
      if ((local_20[0] < local_2c) && (local_38[0] < local_20[0])) {
        iVar2 = FUN_004975e0(local_20[0] - local_2c);
        *(int *)(local_8 + 0x90) = *(int *)(local_8 + 0x90) + iVar2;
      }
    }
    else if ((local_38[0] < local_14) && (local_14 < local_2c)) {
      iVar2 = FUN_004975e0(local_14 - local_38[0]);
      *(int *)(local_8 + 0x90) = *(int *)(local_8 + 0x90) - iVar2;
    }
  }
  local_8 = 0x464beb;
  __chkesp();
  return;
}

