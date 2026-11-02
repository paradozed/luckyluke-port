/* FUN_00452860 @ 00452860 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00452860(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_a0 [16];
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_40;
  int local_3c;
  int local_38;
  int local_30;
  int local_2c;
  int local_28;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_10;
  int local_c;
  int local_8;
  
  puVar2 = local_a0;
  for (iVar1 = 0x27; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_20 = *(int *)(param_1 + 0x90);
  local_1c = *(undefined4 *)(param_1 + 0x94);
  local_18 = *(undefined4 *)(param_1 + 0x98);
  FUN_00482760((undefined4 *)&DAT_00508180,&local_20,&local_30);
  local_40 = local_30 + _DAT_004f2b40 + *(int *)(param_1 + 0xa4);
  local_3c = local_2c + _DAT_004f2b44 + *(int *)(param_1 + 0xa8);
  local_38 = local_28 + DAT_004f2b48 + *(int *)(param_1 + 0xac) + param_2;
  local_8 = DAT_004bdab0 * local_38 >> 0xc;
  local_54 = local_40;
  if (local_40 < 0) {
    local_54 = -local_40;
  }
  if (local_54 < local_8) {
    local_58 = local_3c;
    if (local_3c < 0) {
      local_58 = -local_3c;
    }
    if (((local_58 < DAT_004bdab0 * local_38 >> 0xd) && (0 < local_38)) && (local_38 < 60000))
    goto LAB_00452a4a;
  }
  local_50 = local_30 + _DAT_004f2b40 + *(int *)(param_1 + 0xb0);
  local_4c = local_2c + _DAT_004f2b44 + *(int *)(param_1 + 0xb4);
  local_48 = local_28 + DAT_004f2b48 + *(int *)(param_1 + 0xb8) + param_2;
  local_c = DAT_004bdab0 * local_48 >> 0xc;
  local_5c = local_50;
  if (local_50 < 0) {
    local_5c = -local_50;
  }
  if (local_5c < local_c) {
    local_60 = local_4c;
    if (local_4c < 0) {
      local_60 = -local_4c;
    }
    if (((local_60 < DAT_004bdab0 * local_48 >> 0xd) && (0 < local_48)) && (local_48 < 60000))
    goto LAB_00452a4a;
  }
  if (local_8 < local_c) {
    local_8 = local_c;
  }
  local_10 = local_8 >> 1;
LAB_00452a4a:
  local_8 = 0x452a5a;
  __chkesp();
  return;
}

