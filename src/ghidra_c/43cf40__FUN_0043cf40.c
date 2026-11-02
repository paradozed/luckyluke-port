/* FUN_0043cf40 @ 0043cf40 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043cf40(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_5c [17];
  int local_18;
  int local_14;
  int local_c;
  int local_8;
  
  puVar2 = local_5c;
  for (iVar1 = 0x16; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = param_3 * param_3;
  local_c = (param_3 + 1) * (param_3 + 1);
  if ((local_8 != 0) && (local_14 = FUN_00494c40(local_8 * 0xc,1), local_14 != 0)) {
    local_18 = FUN_00494c40(local_8 * 0xc,1);
    if (local_18 == 0) {
      local_18 = 0;
    }
    else {
      local_18 = FUN_00494c40(local_8 * 0xc,1);
    }
  }
  local_8 = 0x43cfd5;
  __chkesp();
  return;
}

