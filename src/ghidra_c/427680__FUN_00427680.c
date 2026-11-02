/* FUN_00427680 @ 00427680 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00427680(void)

{
  int iVar1;
  undefined4 *puVar2;
  float10 fVar3;
  undefined8 uVar4;
  undefined4 local_4c [16];
  int local_c;
  float local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004bc4f8 != 0) {
    FUN_00426fd0();
    FUN_00427260();
    (*DAT_004e8a30)();
    __chkesp();
    (*DAT_004e8a54)(&DAT_004d28f0,0x10,0x10,0x10,0x10);
    __chkesp();
    (*DAT_004e8a30)();
    __chkesp();
    (*DAT_004e8a54)(&DAT_004d28c0,0x10,0x10,0x10,0x10);
    __chkesp();
    FUN_00427560();
    uVar4 = FUN_00497360();
    local_c = (int)uVar4;
    local_8 = (float)local_c / _DAT_004b40d4 - _DAT_004d292c;
    _DAT_004d2920 = _DAT_004d2928 * local_8 + _DAT_004d2920;
    if (_DAT_004d2920 < _DAT_004b4938) {
      _DAT_004d2920 = _DAT_004d2920 + (float)_DAT_004b4940;
    }
    fVar3 = (float10)FUN_004980a0(SUB84((double)_DAT_004d2920,0),
                                  (int)((ulonglong)(double)_DAT_004d2920 >> 0x20),0xf01b866e,
                                  0x401921f9);
    _DAT_004d2920 = (float)fVar3;
    _DAT_004d292c = _DAT_004d292c + local_8;
  }
  local_8 = 6.104059e-39;
  __chkesp();
  return;
}

