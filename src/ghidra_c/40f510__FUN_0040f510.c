/* FUN_0040f510 @ 0040f510 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040f510(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined4 local_60 [16];
  int local_20;
  int local_1c;
  float local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 uStack_8;
  
  puVar2 = local_60;
  for (iVar1 = 0x17; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004d1e3c != 0) {
    local_14 = *(undefined4 *)(DAT_004d1e44 + 0x90);
    local_10 = *(undefined4 *)(DAT_004d1e44 + 0x94);
    local_c = *(undefined4 *)(DAT_004d1e44 + 0x98);
    uVar3 = FUN_00497360();
    local_1c = (int)uVar3 - _DAT_004d1e28;
    local_18 = (float)local_1c / (float)_DAT_004d1e38;
    if (_DAT_004b4078 < local_18) {
      local_18 = 1.0;
    }
    local_20 = DAT_004d1e2c - DAT_004d1e34;
    lVar4 = __ftol();
    local_10 = (undefined4)lVar4;
    FUN_00410130(DAT_004d1e44,local_14,local_10,local_c);
    _DAT_004d1e30 = local_10;
    _DAT_004d1e40 = local_18;
    (*DAT_004e8a2c)(10,200,"Lift Active");
    __chkesp();
    (*DAT_004e8a2c)(10,0xd2,"t: %f",(double)local_18);
    __chkesp();
  }
  uStack_8 = 0x40f634;
  __chkesp();
  return;
}

