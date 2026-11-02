/* FUN_00483540 @ 00483540 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00483540(short param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  float10 fVar4;
  undefined4 local_50 [16];
  int local_10;
  undefined8 local_c;
  
  puVar3 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_10 = (int)param_1;
  local_c._4_4_ = (undefined4)((ulonglong)((double)local_10 / _DAT_004b8e20) >> 0x20);
  uVar1 = local_c._4_4_;
  local_c = (double)local_10 / _DAT_004b8e20;
  fVar4 = (float10)FUN_004997d4(uVar1);
  fVar4 = fVar4 * (float10)_DAT_004b8e18 * (float10)_DAT_004b8e30;
  local_c = (double)fVar4;
  if (fVar4 < (float10)_DAT_004b8e28) {
    local_c = _DAT_004b8e20 - local_c;
  }
  __ftol();
  local_c = (double)CONCAT44(0x4835be,(undefined4)local_c);
  __chkesp();
  return;
}

