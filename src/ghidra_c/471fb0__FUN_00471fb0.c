/* FUN_00471fb0 @ 00471fb0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00471fb0(int param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined4 local_54 [16];
  LARGE_INTEGER local_14;
  uint local_c;
  int local_8;
  
  puVar2 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004be114 == 0) {
    QueryPerformanceCounter(&local_14);
    __chkesp();
  }
  else {
    uVar3 = FUN_00497360();
    local_14.s.LowPart = (DWORD)uVar3;
    local_14.s.HighPart = (int)local_14.s.LowPart >> 0x1f;
  }
  lVar4 = __allmul(param_2,(int)param_2 >> 0x1f,DAT_004be108,DAT_004be10c);
  uVar3 = __alldiv((uint)lVar4,(uint)((ulonglong)lVar4 >> 0x20),1000,0);
  *(DWORD *)(&DAT_004f1920 + param_1 * 8) = local_14.s.LowPart;
  *(LONG *)(&DAT_004f1924 + param_1 * 8) = local_14.s.HighPart;
  *(undefined4 *)(&DAT_004f1da0 + param_1 * 4) = 0;
  *(undefined4 *)(&DAT_004f1c20 + param_1 * 4) = 1;
  local_c = (uint)uVar3;
  local_8 = (int)((ulonglong)uVar3 >> 0x20);
  *(DWORD *)(&DAT_004f1a20 + param_1 * 8) = local_14.s.LowPart + local_c;
  *(uint *)(&DAT_004f1a24 + param_1 * 8) =
       local_14.s.HighPart + local_8 + (uint)CARRY4(local_14.s.LowPart,local_c);
  *(undefined4 *)(&DAT_004f1ca0 + param_1 * 4) = 0;
  _local_c = CONCAT44(0x47208a,local_c);
  __chkesp();
  return;
}

