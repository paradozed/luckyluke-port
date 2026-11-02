/* FUN_00471d50 @ 00471d50 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00471d50(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  bool bVar4;
  undefined8 uVar5;
  undefined4 local_50 [16];
  int local_10;
  LARGE_INTEGER local_c;
  
  puVar3 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (DAT_004e893c != 0) {
    DAT_004e893c = 0;
    if (DAT_004be114 == 0) {
      QueryPerformanceCounter(&local_c);
      __chkesp();
    }
    else {
      uVar5 = FUN_00497360();
      local_c.s.LowPart = (DWORD)uVar5;
      local_c.s.HighPart = (int)local_c.s.LowPart >> 0x1f;
    }
    bVar4 = local_c.s.LowPart < _DAT_004e8940;
    local_c.s.LowPart = local_c.s.LowPart - _DAT_004e8940;
    iVar2 = (local_c.s.HighPart - _DAT_004e8944) - (uint)bVar4;
    bVar4 = CARRY4(DAT_004e8930,local_c.s.LowPart);
    DAT_004e8930 = DAT_004e8930 + local_c.s.LowPart;
    DAT_004e8934 = DAT_004e8934 + iVar2 + (uint)bVar4;
    for (local_10 = 0; local_10 < 0x20; local_10 = local_10 + 1) {
      if (*(int *)(&DAT_004f1c20 + local_10 * 4) != 0) {
        uVar1 = *(uint *)(&DAT_004f1a20 + local_10 * 8);
        *(uint *)(&DAT_004f1a20 + local_10 * 8) = uVar1 + local_c.s.LowPart;
        *(uint *)(&DAT_004f1a24 + local_10 * 8) =
             *(int *)(&DAT_004f1a24 + local_10 * 8) + iVar2 + (uint)CARRY4(uVar1,local_c.s.LowPart);
      }
    }
  }
  local_c.s.HighPart = 0x471e3a;
  __chkesp();
  return;
}

