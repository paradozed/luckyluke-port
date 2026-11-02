/* FUN_00473450 @ 00473450 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00473450(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_60 [16];
  int local_20;
  ushort *local_1c;
  int local_18;
  int local_14;
  int local_10;
  byte *local_c;
  int local_8;
  
  puVar2 = local_60;
  for (iVar1 = 0x17; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_20 = 0;
  local_1c = *(ushort **)(param_1 + 8);
  if ((*(char *)(param_1 + 0x15) != '\0') && ((char)local_1c[1] != '\0')) {
    local_10 = DAT_004e8670 * DAT_004bc4e8;
    local_14 = DAT_004e8674 * DAT_004bc4ea;
    local_18 = DAT_004e8678 * DAT_004bc4ec;
    for (local_8 = 0; local_8 < (int)(uint)*local_1c; local_8 = local_8 + 1) {
      local_c = *(byte **)(*(int *)(local_1c + 8) + local_8 * 0x20);
      *(int *)(local_c + 0x70) = *(int *)(local_c + 0x90) - local_10;
      *(int *)(local_c + 0x74) = *(int *)(local_c + 0x94) - local_14;
      *(int *)(local_c + 0x78) = *(int *)(local_c + 0x98) - local_18;
      if (*(char *)(*(int *)(local_1c + 8) + 0x1f + local_8 * 0x20) != '\0') {
        local_20 = *(int *)(local_c + 0xcc);
        if (*(int *)(local_c + 0xcc) != 0) {
          FUN_00485430((int)local_c);
        }
        FUN_004803f0(local_c);
        if ((*(char *)(*(int *)(local_1c + 8) + 0x1e + local_8 * 0x20) != '\0') &&
           (*(short *)(local_20 + 4) == *(short *)(local_20 + 0xe))) {
          *(undefined1 *)(*(int *)(local_1c + 8) + 0x1f + local_8 * 0x20) = 0;
          DAT_004e8994 = 0;
        }
      }
    }
  }
  local_8 = 0x4735d4;
  __chkesp();
  return;
}

