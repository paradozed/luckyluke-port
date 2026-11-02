/* FUN_00471800 @ 00471800 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00471800(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  int local_10;
  LARGE_INTEGER local_c;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  DAT_004e8954 = 0;
  QueryPerformanceFrequency(&local_c);
  __chkesp();
  if ((local_c.s.LowPart == 0) && (local_c.s.HighPart == 0)) {
    DAT_004be108 = 1000;
    DAT_004be10c = 0;
    DAT_004be114 = 1;
  }
  else {
    DAT_004be108 = local_c.s.LowPart;
    DAT_004be10c = local_c.s.HighPart;
    DAT_004be114 = 0;
    for (local_10 = 0; local_10 < 0x20; local_10 = local_10 + 1) {
      *(undefined4 *)(&DAT_004f1ca0 + local_10 * 4) = 0;
      *(undefined4 *)(&DAT_004f1c20 + local_10 * 4) = 0;
      *(undefined4 *)(&DAT_004f1a20 + local_10 * 8) = 0;
      *(undefined4 *)(&DAT_004f1a24 + local_10 * 8) = 0;
    }
  }
  local_c.s.HighPart = 0x4718d9;
  __chkesp();
  return;
}

