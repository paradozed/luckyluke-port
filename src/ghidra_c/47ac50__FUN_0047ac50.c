/* FUN_0047ac50 @ 0047ac50 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047ac50(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_64 [16];
  int local_24;
  int local_20;
  int local_1c;
  int *local_18;
  int local_14;
  int local_10;
  short local_c;
  byte *local_8;
  
  puVar2 = local_64;
  for (iVar1 = 0x18; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (*(char *)(param_1 + 0x13) == '\0') {
    local_8 = (byte *)**(undefined4 **)(param_1 + 8);
    if (local_8[1] == 7) {
      if (*(char *)(param_1 + 0x14) == '\x01') {
        FUN_004803f0(local_8);
      }
    }
    else {
      local_c = FUN_0047a5d0((int)local_8);
      if ((local_c != -1) &&
         ((*(char *)(param_1 + 0x15) == '\x01' ||
          ((local_8[1] == 5 && (*(char *)(DAT_004e89f0 + 5 + local_c * 0x20) == '\x01')))))) {
        local_1c = DAT_004e8670 * DAT_004bc4e8;
        local_20 = DAT_004e8674 * DAT_004bc4ea;
        local_24 = DAT_004e8678 * DAT_004bc4ec;
        *(int *)(local_8 + 0x70) = *(int *)(local_8 + 0x90) - local_1c;
        *(int *)(local_8 + 0x74) = *(int *)(local_8 + 0x94) - local_20;
        *(int *)(local_8 + 0x78) = *(int *)(local_8 + 0x98) - local_24;
        if (*(int *)(local_8 + 0xd8) != 0) {
          for (local_10 = **(int **)(local_8 + 0xd8); local_10 != 0;
              local_10 = *(int *)(*(int *)(local_10 + 0xdc) + 0x3c)) {
            *(int *)(local_10 + 0x70) = *(int *)(local_10 + 0x90) - local_1c;
            *(int *)(local_10 + 0x74) = *(int *)(local_10 + 0x94) - local_20;
            *(int *)(local_10 + 0x78) = *(int *)(local_10 + 0x98) - local_24;
            if (*(int *)(local_10 + 0xd8) != 0) {
              for (local_14 = **(int **)(local_10 + 0xd8); local_14 != 0;
                  local_14 = *(int *)(*(int *)(local_14 + 0xdc) + 0x3c)) {
                *(int *)(local_14 + 0x70) = *(int *)(local_14 + 0x90) - local_1c;
                *(int *)(local_14 + 0x74) = *(int *)(local_14 + 0x94) - local_20;
                *(int *)(local_14 + 0x78) = *(int *)(local_14 + 0x98) - local_24;
              }
            }
          }
        }
        if ((*(char *)(param_1 + 0x14) == '\x01') && (*(int *)(local_8 + 0xdc) == 0)) {
          FUN_004803f0(local_8);
        }
        local_18 = *(int **)(param_1 + 8);
        local_18[0x19] = *(int *)(*local_18 + 0x90);
        local_18[0x1a] = *(int *)(*local_18 + 0x94);
        local_18[0x1b] = *(int *)(*local_18 + 0x98);
      }
    }
  }
  local_8 = (byte *)0x47aebe;
  __chkesp();
  return;
}

