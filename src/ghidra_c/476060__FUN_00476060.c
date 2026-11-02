/* FUN_00476060 @ 00476060 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00476060(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_5c [16];
  int local_1c;
  int local_18;
  int local_14;
  byte *local_10;
  byte *local_c;
  int local_8;
  
  puVar2 = local_5c;
  for (iVar1 = 0x16; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_14 = DAT_004e8670 * DAT_004bc4e8;
  local_18 = DAT_004e8674 * DAT_004bc4ea;
  local_1c = DAT_004e8678 * DAT_004bc4ec;
  for (local_8 = 0; local_8 < 10; local_8 = local_8 + 1) {
    local_c = *(byte **)(&DAT_004f13c0 + local_8 * 0x2c);
    *(int *)(local_c + 0x70) = *(int *)(local_c + 0x90) - local_14;
    *(int *)(local_c + 0x74) = *(int *)(local_c + 0x94) - local_18;
    *(int *)(local_c + 0x78) = *(int *)(local_c + 0x98) - local_1c;
    local_10 = *(byte **)(&DAT_004f13c4 + local_8 * 0x2c);
    *(int *)(local_10 + 0x70) = *(int *)(local_10 + 0x90) - local_14;
    *(int *)(local_10 + 0x74) = *(int *)(local_10 + 0x94) - local_18;
    *(int *)(local_10 + 0x78) = *(int *)(local_10 + 0x98) - local_1c;
    if (*(short *)(&DAT_004f13ca + local_8 * 0x2c) != 0) {
      if (*(int *)(local_c + 0xcc) != 0) {
        FUN_00485430((int)local_c);
      }
      FUN_004803f0(local_c);
    }
    if (*(short *)(&DAT_004f13cc + local_8 * 0x2c) != 0) {
      if (*(int *)(local_10 + 0xcc) != 0) {
        FUN_00485430((int)local_10);
      }
      FUN_004803f0(local_10);
    }
  }
  local_8 = 0x4761d6;
  __chkesp();
  return;
}

