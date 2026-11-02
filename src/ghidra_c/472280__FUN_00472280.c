/* FUN_00472280 @ 00472280 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00472280(uint param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 local_64 [16];
  uint local_24;
  int local_20;
  uint local_1c;
  int local_18;
  LARGE_INTEGER local_14;
  LARGE_INTEGER local_c;
  
  puVar2 = local_64;
  for (iVar1 = 0x18; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004be114 == 0) {
    QueryPerformanceCounter(&local_c);
    __chkesp();
    do {
      do {
        QueryPerformanceCounter(&local_14);
        __chkesp();
        local_24 = local_14.s.LowPart - local_c._0_4_;
        local_20 = (local_14.s.HighPart - local_c._4_4_) -
                   (uint)(local_14.s.LowPart < local_c.s.LowPart);
      } while (local_20 < param_2);
    } while ((local_20 <= param_2) && (local_24 < param_1));
  }
  else {
    uVar3 = FUN_00497360();
    local_c.s.LowPart = (DWORD)uVar3;
    local_c.s.HighPart = (int)local_c.s.LowPart >> 0x1f;
    do {
      do {
        uVar3 = FUN_00497360();
        local_14.s.LowPart = (DWORD)uVar3;
        local_14.s.HighPart = (int)local_14.s.LowPart >> 0x1f;
        local_1c = local_14.s.LowPart - local_c._0_4_;
        local_18 = (local_14.s.HighPart - local_c._4_4_) -
                   (uint)(local_14.s.LowPart < local_c.s.LowPart);
      } while (local_18 < param_2);
    } while ((local_18 <= param_2) && (local_1c < param_1));
  }
  local_c.s.HighPart = 0x472336;
  __chkesp();
  return;
}

