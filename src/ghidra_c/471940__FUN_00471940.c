/* FUN_00471940 @ 00471940 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00471940(void)

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
  DAT_004e8954 = 0;
  _DAT_004e8938 = 0;
  if (DAT_004be114 == 0) {
    QueryPerformanceCounter((LARGE_INTEGER *)&DAT_004e8930);
    __chkesp();
  }
  else {
    uVar3 = FUN_00497360();
    DAT_004e8930 = (int)uVar3;
    DAT_004e8934 = DAT_004e8930 >> 0x1f;
  }
  DAT_004e8960 = 0;
  DAT_004e8964 = 0;
  DAT_004e8968 = 0;
  DAT_004e896c = 0;
  uStack_8 = 0x4719d1;
  __chkesp();
  return;
}

