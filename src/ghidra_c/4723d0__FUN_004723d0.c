/* FUN_004723d0 @ 004723d0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004723d0(void)

{
  int iVar1;
  undefined4 *puVar2;
  bool bVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined4 local_50 [16];
  int local_10;
  LARGE_INTEGER local_c;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004be114 == 0) {
    QueryPerformanceCounter(&local_c);
    __chkesp();
  }
  else {
    uVar4 = FUN_00497360();
    local_c.s.LowPart = (DWORD)uVar4;
    local_c.s.HighPart = (int)local_c.s.LowPart >> 0x1f;
  }
  bVar3 = local_c.s.LowPart < _DAT_004f1c10;
  local_c.s.LowPart = local_c.s.LowPart - _DAT_004f1c10;
  local_c.s.HighPart = (local_c.s.HighPart - _DAT_004f1c14) - (uint)bVar3;
  for (local_10 = 0; local_10 < 0x1e; local_10 = local_10 + 1) {
    lVar5 = __allmul(*(uint *)(&DAT_004f1b20 + local_10 * 8),*(int *)(&DAT_004f1b24 + local_10 * 8),
                     100,0);
    uVar4 = __alldiv((uint)lVar5,(uint)((ulonglong)lVar5 >> 0x20),local_c.s.LowPart,
                     local_c.s.HighPart);
    *(int *)(&DAT_004f1d20 + local_10 * 4) = (int)uVar4;
  }
  local_c.s.HighPart = 0x472486;
  __chkesp();
  return;
}

