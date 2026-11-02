/* FUN_004435d0 @ 004435d0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004435d0(uint *param_1,uint param_2,uint param_3,uint param_4,uint param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  uint *local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = (uint *)FUN_00494c40(0x38,1);
  if (local_8 != (uint *)0x0) {
    local_8[9] = param_2;
    local_8[10] = param_3;
    local_8[0xb] = param_4;
    local_8[8] = param_5;
    local_8[0xd] = 0;
    FUN_00497270(local_8,param_1);
    if (DAT_004e8564 == (uint *)0x0) {
      local_8[0xc] = 0;
      DAT_004e8564 = local_8;
    }
    else {
      local_8[0xc] = (uint)DAT_004e8568;
      DAT_004e8568[0xd] = (uint)local_8;
    }
    DAT_004e8568 = local_8;
    if (local_8[9] != 0) {
      (*(code *)local_8[9])();
      __chkesp();
    }
  }
  local_8 = (uint *)0x4436ae;
  __chkesp();
  return;
}

