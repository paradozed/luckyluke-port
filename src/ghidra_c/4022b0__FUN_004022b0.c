/* FUN_004022b0 @ 004022b0 */
/* decompiled from Lucky.exe (Game.run) */


void __fastcall FUN_004022b0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_54 [16];
  undefined4 local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  
  puVar2 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = &PTR_FUN_004b33d8;
  param_1[0xf] = param_1[0xf] + -1;
  local_8 = param_1;
  while (-1 < (int)local_8[0xf]) {
    if (local_8[local_8[0xf] + 0x10] != 0) {
      local_10 = (undefined4 *)local_8[local_8[0xf] + 0x10];
      local_c = local_10;
      if (local_10 == (undefined4 *)0x0) {
        local_14 = 0;
      }
      else {
        (**(code **)*local_10)(1);
        local_14 = __chkesp();
      }
      local_8[local_8[0xf] + 0x10] = 0;
    }
    local_8[0xf] = local_8[0xf] + -1;
  }
  local_8 = (undefined4 *)0x40236e;
  __chkesp();
  return;
}

