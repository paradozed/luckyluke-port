/* FUN_00471ce0 @ 00471ce0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00471ce0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004e893c == 0) {
    DAT_004e893c = 1;
    if (DAT_004be114 == 0) {
      QueryPerformanceCounter((LARGE_INTEGER *)&DAT_004e8940);
      __chkesp();
    }
    else {
      uVar3 = FUN_00497360();
      _DAT_004e8940 = (int)uVar3;
      _DAT_004e8944 = _DAT_004e8940 >> 0x1f;
    }
  }
  uStack_8 = 0x471d4a;
  __chkesp();
  return;
}

