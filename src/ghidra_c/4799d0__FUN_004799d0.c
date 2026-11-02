/* FUN_004799d0 @ 004799d0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004799d0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_5c [16];
  int local_1c;
  int local_18;
  int local_14;
  short local_10;
  short local_c;
  uint local_8;
  
  puVar2 = local_5c;
  for (iVar1 = 0x16; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = local_8 & 0xffff0000;
  for (local_10 = 0; (int)local_10 < (int)(uint)DAT_004e89fa; local_10 = local_10 + 1) {
    if ((*(char *)(DAT_004e89f0 + 5 + local_10 * 0x20) == '\x01') &&
       (*(short *)(DAT_004e89f0 + local_10 * 0x20) != 0)) {
      *(undefined1 *)(DAT_004e89f0 + 6 + local_10 * 0x20) = 0;
      if ((*(char *)(DAT_004e89f0 + 2 + local_10 * 0x20) == '\x01') || (DAT_004e9380 == '\x01')) {
        if (*(char *)(DAT_004e89f0 + 2 + local_10 * 0x20) == '\0') {
          FUN_00479820((int)local_10);
        }
        FUN_0042e640();
        FUN_004794f0((int)local_10);
        local_14 = *(int *)(DAT_004e89f0 + 8 + local_10 * 0x20);
        local_18 = *(int *)(DAT_004e89f0 + 0xc + local_10 * 0x20);
        local_1c = *(int *)(DAT_004e89f0 + 0x10 + local_10 * 0x20);
        for (local_c = 0; local_c < *(short *)(DAT_004e89f0 + local_10 * 0x20);
            local_c = local_c + 1) {
          *(int *)(*(int *)(*(int *)(DAT_004e89f0 + 0x14 + local_10 * 0x20) + local_c * 4) + 0x70) =
               *(int *)(*(int *)(*(int *)(DAT_004e89f0 + 0x14 + local_10 * 0x20) + local_c * 4) +
                       0x70) + local_14;
          *(int *)(*(int *)(*(int *)(DAT_004e89f0 + 0x14 + local_10 * 0x20) + local_c * 4) + 0x74) =
               *(int *)(*(int *)(*(int *)(DAT_004e89f0 + 0x14 + local_10 * 0x20) + local_c * 4) +
                       0x74) + local_18;
          *(int *)(*(int *)(*(int *)(DAT_004e89f0 + 0x14 + local_10 * 0x20) + local_c * 4) + 0x78) =
               *(int *)(*(int *)(*(int *)(DAT_004e89f0 + 0x14 + local_10 * 0x20) + local_c * 4) +
                       0x78) + local_1c;
          FUN_004803f0(*(byte **)(*(int *)(DAT_004e89f0 + 0x14 + local_10 * 0x20) + local_c * 4));
          FUN_0042f7f0(*(byte **)(*(int *)(DAT_004e89f0 + 0x14 + local_10 * 0x20) + local_c * 4));
          *(int *)(*(int *)(*(int *)(DAT_004e89f0 + 0x14 + local_10 * 0x20) + local_c * 4) + 0x70) =
               *(int *)(*(int *)(*(int *)(DAT_004e89f0 + 0x14 + local_10 * 0x20) + local_c * 4) +
                       0x70) - local_14;
          *(int *)(*(int *)(*(int *)(DAT_004e89f0 + 0x14 + local_10 * 0x20) + local_c * 4) + 0x74) =
               *(int *)(*(int *)(*(int *)(DAT_004e89f0 + 0x14 + local_10 * 0x20) + local_c * 4) +
                       0x74) - local_18;
          *(int *)(*(int *)(*(int *)(DAT_004e89f0 + 0x14 + local_10 * 0x20) + local_c * 4) + 0x78) =
               *(int *)(*(int *)(*(int *)(DAT_004e89f0 + 0x14 + local_10 * 0x20) + local_c * 4) +
                       0x78) - local_1c;
        }
      }
      else if (*(char *)(DAT_004e89f0 + 3 + local_10 * 0x20) == '\0') {
        FUN_004797a0((int)local_10);
      }
    }
    else if ((*(short *)(DAT_004e89f0 + local_10 * 0x20) != 0) &&
            ((*(char *)(DAT_004e89f0 + 2 + local_10 * 0x20) == '\x01' ||
             (*(char *)(DAT_004e89f0 + 3 + local_10 * 0x20) == '\x01')))) {
      *(undefined1 *)(DAT_004e89f0 + 6 + local_10 * 0x20) = 1;
    }
  }
  DAT_004e9380 = 0;
  if (DAT_004e860c == 0) {
    for (local_10 = 0; (int)local_10 < (int)(uint)DAT_004e89fa; local_10 = local_10 + 1) {
      if ((*(char *)(DAT_004e89f0 + 6 + local_10 * 0x20) == '\x01') &&
         (*(char *)(DAT_004e89f0 + 4 + local_10 * 0x20) == '\0')) {
        FUN_004798a0((int)local_10);
        *(undefined1 *)(DAT_004e89f0 + 6 + local_10 * 0x20) = 0;
      }
    }
  }
  local_8 = 0x479dda;
  __chkesp();
  return;
}

