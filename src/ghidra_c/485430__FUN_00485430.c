/* FUN_00485430 @ 00485430 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00485430(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_58 [16];
  uint local_18;
  ushort *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar2 = local_58;
  for (iVar1 = 0x15; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = *(int *)(param_1 + 0xcc);
  local_c = *(int *)(local_8 + 0x28);
  local_10 = *(int *)(local_c + 8);
  local_14 = (ushort *)(local_8 + 0x2c);
  local_18 = (DAT_004e8abc >> 5) - *(int *)(local_8 + 8);
  do {
    while( true ) {
      if (local_18 <= *(uint *)(local_10 + (uint)*(ushort *)(local_8 + 4) * 0xc)) goto LAB_00485592;
      if (*(char *)(local_8 + 0x12) == '\0') {
        local_18 = local_18 - *(int *)(local_10 + (uint)*(ushort *)(local_8 + 4) * 0xc);
        *(int *)(local_8 + 8) =
             *(int *)(local_8 + 8) + *(int *)(local_10 + (uint)*(ushort *)(local_8 + 4) * 0xc);
      }
      else {
        local_18 = 0;
        *(uint *)(local_8 + 8) = DAT_004e8abc >> 5;
      }
      if ((*(char *)(local_8 + 0x12) == '\0') &&
         (*(short *)(local_8 + 4) == *(short *)(local_8 + 0xe))) break;
      if (*(char *)(local_8 + 0x13) == '\0') {
        FUN_00485630((ushort *)(local_8 + 4),*(short *)(local_c + 2) - 1);
      }
      else {
        FUN_00485680((short *)(local_8 + 4),*(short *)(local_c + 2) + -1);
      }
    }
  } while (*(int *)(local_8 + 0x18) == 0);
  (**(code **)(local_8 + 0x18))(*(undefined4 *)(local_8 + 0x1c));
  __chkesp();
  *(undefined4 *)(local_8 + 0x18) = 0;
LAB_00485592:
  if (*(short *)(local_8 + 4) != *(short *)(local_8 + DAT_004e8ad8 * 2)) {
    *(undefined2 *)(local_8 + DAT_004e8ad8 * 2) = *(undefined2 *)(local_8 + 4);
    if (*(char *)(local_c + 4) == '\0') {
      FUN_00485300(local_14,*(undefined2 *)(local_10 + 4 + (uint)*(ushort *)(local_8 + 4) * 0xc));
    }
    else {
      FUN_004862e0(param_1,local_10 + (uint)*(ushort *)(local_8 + 4) * 0xc,
                   (short)*(undefined4 *)(local_8 + 0x14));
    }
  }
  local_8 = 0x485623;
  __chkesp();
  return;
}

