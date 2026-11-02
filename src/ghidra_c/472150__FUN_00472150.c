/* FUN_00472150 @ 00472150 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00472150(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 local_54 [16];
  uint *local_14;
  uint *local_10;
  LARGE_INTEGER local_c;
  
  puVar2 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (*(int *)(&DAT_004f1c20 + param_1 * 4) != 0) {
    if (DAT_004be114 == 0) {
      QueryPerformanceCounter(&local_c);
      __chkesp();
    }
    else {
      uVar3 = FUN_00497360();
      local_c.s.LowPart = (DWORD)uVar3;
      local_c.s.HighPart = (int)local_c.s.LowPart >> 0x1f;
    }
    local_10 = (uint *)(&DAT_004f1920 + param_1 * 8);
    if ((local_c.s.HighPart <= *(int *)(&DAT_004f1924 + param_1 * 8)) &&
       ((local_c.s.HighPart < *(int *)(&DAT_004f1924 + param_1 * 8) ||
        (local_c.s.LowPart < *local_10)))) {
      *(undefined4 *)(&DAT_004f1ca0 + param_1 * 4) = 1;
      *(undefined4 *)(&DAT_004f1c20 + param_1 * 4) = 0;
    }
    local_14 = (uint *)(&DAT_004f1a20 + param_1 * 8);
    if ((*(int *)(&DAT_004f1a24 + param_1 * 8) <= local_c.s.HighPart) &&
       ((*(int *)(&DAT_004f1a24 + param_1 * 8) < local_c.s.HighPart ||
        (*local_14 < local_c.s.LowPart)))) {
      *(undefined4 *)(&DAT_004f1ca0 + param_1 * 4) = 1;
      *(undefined4 *)(&DAT_004f1c20 + param_1 * 4) = 0;
    }
  }
  local_c.s.HighPart = 0x47223d;
  __chkesp();
  return;
}

