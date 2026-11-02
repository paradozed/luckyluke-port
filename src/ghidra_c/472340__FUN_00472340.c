/* FUN_00472340 @ 00472340 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00472340(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 local_4c [16];
  LARGE_INTEGER local_c;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004be114 == 0) {
    QueryPerformanceCounter(&local_c);
    __chkesp();
  }
  else {
    uVar3 = FUN_00497360();
    local_c.s.LowPart = (DWORD)uVar3;
    local_c.s.HighPart = (int)local_c.s.LowPart >> 0x1f;
  }
  *(DWORD *)(&DAT_004f1b20 + param_1 * 8) = local_c.s.LowPart - DAT_004f1c18;
  *(uint *)(&DAT_004f1b24 + param_1 * 8) =
       (local_c.s.HighPart - DAT_004f1c1c) - (uint)(local_c.s.LowPart < DAT_004f1c18);
  DAT_004f1c18 = local_c.s.LowPart;
  DAT_004f1c1c = local_c.s.HighPart;
  local_c.s.HighPart = 0x4723c4;
  __chkesp();
  return;
}

