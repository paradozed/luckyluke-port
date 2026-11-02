/* FUN_0043d310 @ 0043d310 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0043d310(int *param_1)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 *puVar2;
  float10 fVar3;
  undefined4 local_48 [16];
  float local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((param_1[0xd] == 1) && (_DAT_004b6ad8 < (float)param_1[5])) {
    param_1[5] = (int)((float)param_1[5] - _DAT_004b5d48);
    local_8 = ((_DAT_004b6ad4 - (float)param_1[5]) / _DAT_004b6ad0) * (float)_DAT_004b6ac8 -
              (float)_DAT_004b6ac0;
    fVar3 = (float10)FUN_00497f54(param_1);
    param_1[4] = (int)(float)(fVar3 * (float10)_DAT_004b6ab8);
    local_8 = local_8 + (float)_DAT_004b6ac0;
    fVar3 = (float10)FUN_00497f54(extraout_ECX);
    param_1[6] = (int)(float)(fVar3 * (float10)_DAT_004b6ab8 + (float10)_DAT_004b6ab0);
    param_1[7] = (int)((float)param_1[7] + (float)_DAT_004b6aa8);
  }
  if ((param_1[0xd] == 2) && ((float)param_1[5] < _DAT_004b6ad4)) {
    param_1[5] = (int)((float)param_1[5] + _DAT_004b5d48);
    local_8 = ((_DAT_004b6ad4 - (float)param_1[5]) / _DAT_004b6ad0) * (float)_DAT_004b6ac8 -
              (float)_DAT_004b6ac0;
    fVar3 = (float10)FUN_00497f54(param_1);
    param_1[4] = (int)(float)(fVar3 * (float10)_DAT_004b6ab8);
    local_8 = local_8 + (float)_DAT_004b6ac0;
    fVar3 = (float10)FUN_00497f54(extraout_ECX_00);
    param_1[6] = (int)(float)(fVar3 * (float10)_DAT_004b6ab8 + (float10)_DAT_004b6ab0);
    param_1[7] = (int)((float)param_1[7] - (float)_DAT_004b6aa8);
  }
  param_1[2] = (int)((float)param_1[2] + (float)_DAT_004b4930);
  FUN_0043d0f0(param_1);
  FUN_0043bc30((int *)*param_1);
  local_8 = 6.229297e-39;
  __chkesp();
  return;
}

