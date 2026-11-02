/* FUN_00479ee0 @ 00479ee0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00479ee0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_5c [16];
  undefined1 local_1c [4];
  uint local_18;
  uint local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  puVar2 = local_5c;
  for (iVar1 = 0x16; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = 0;
  local_c = 0;
  for (local_18 = 0; local_18 < DAT_004e89fa; local_18 = local_18 + 1) {
    if (*(char *)(DAT_004e89f0 + 5 + local_18 * 0x20) == '\x01') {
      local_10 = (uint)(local_8 + local_c) % 10;
      local_14 = (uint)(local_8 + local_c) / 10;
      FUN_00497080(local_1c,0x4b7e18);
      if (*(short *)(DAT_004e89f0 + local_18 * 0x20) == 0) {
        FUN_004266b0();
        local_c = local_c + 1;
      }
      else {
        FUN_004266b0();
        if (DAT_004e8702 == '\x02') {
          FUN_00497080(local_1c,0x4b4060);
          FUN_004266b0();
        }
        local_8 = local_8 + 1;
      }
    }
  }
  FUN_00459540();
  FUN_00459540();
  FUN_00459540();
  FUN_00497080(local_1c,0x4b7e18);
  FUN_004266b0();
  local_8 = 0x47a106;
  __chkesp();
  return;
}

