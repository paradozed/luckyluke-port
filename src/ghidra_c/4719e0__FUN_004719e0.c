/* FUN_004719e0 @ 004719e0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004719e0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 local_48 [16];
  int local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004be114 == 0) {
    QueryPerformanceCounter((LARGE_INTEGER *)&DAT_004e8920);
    __chkesp();
  }
  else {
    uVar3 = FUN_00497360();
    DAT_004e8920 = (int)uVar3;
    DAT_004e8924 = DAT_004e8920 >> 0x1f;
  }
  DAT_004f1c18 = DAT_004e8920;
  DAT_004f1c1c = DAT_004e8924;
  _DAT_004f1c10 = DAT_004e8920;
  _DAT_004f1c14 = DAT_004e8924;
  for (local_8 = 0; local_8 < 0x1e; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_004f1b20 + local_8 * 8) = 0;
    *(undefined4 *)(&DAT_004f1b24 + local_8 * 8) = 0;
  }
  local_8 = 0x471a94;
  __chkesp();
  return;
}

