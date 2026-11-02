/* FUN_00451f40 @ 00451f40 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00451f40(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_b8 [16];
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar2 = local_b8;
  for (iVar1 = 0x2d; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_00482760((undefined4 *)&DAT_00508180,param_1,&local_38);
  local_38 = local_38 + _DAT_004f2b40;
  local_34 = local_34 + _DAT_004f2b44;
  local_30 = local_30 + 4000 + DAT_004f2b48;
  local_8 = DAT_004bdab0 * local_30 >> 0xc;
  local_3c = local_38;
  if (local_38 < 0) {
    local_3c = -local_38;
  }
  if (local_3c < local_8) {
    local_40 = local_34;
    if (local_34 < 0) {
      local_40 = -local_34;
    }
    if (((local_40 < DAT_004bdab0 * local_30 >> 0xd) && (DAT_004e865c < local_30)) &&
       (local_30 < 60000)) goto LAB_00452843;
  }
  *param_1 = *param_1 + (int)DAT_004bc4e8;
  local_28 = local_30;
  local_24 = local_30;
  local_20 = local_34;
  local_1c = local_34;
  local_18 = local_38;
  local_14 = local_38;
  local_c = local_8;
  FUN_00482760((undefined4 *)&DAT_00508180,param_1,&local_38);
  local_38 = local_38 + _DAT_004f2b40;
  local_34 = local_34 + _DAT_004f2b44;
  local_30 = local_30 + 4000 + DAT_004f2b48;
  local_8 = DAT_004bdab0 * local_30 >> 0xc;
  local_44 = local_38;
  if (local_38 < 0) {
    local_44 = -local_38;
  }
  if (local_44 < local_8) {
    local_48 = local_34;
    if (local_34 < 0) {
      local_48 = -local_34;
    }
    if (((local_48 < DAT_004bdab0 * local_30 >> 0xd) && (DAT_004e865c < local_30)) &&
       (local_30 < 60000)) goto LAB_00452843;
  }
  if (local_c < local_8) {
    local_c = local_8;
  }
  if (local_38 < local_14) {
    local_14 = local_38;
  }
  if (local_18 < local_38) {
    local_18 = local_38;
  }
  if (local_34 < local_1c) {
    local_1c = local_34;
  }
  if (local_20 < local_34) {
    local_20 = local_34;
  }
  if (local_30 < local_24) {
    local_24 = local_30;
  }
  if (local_28 < local_30) {
    local_28 = local_30;
  }
  param_1[2] = param_1[2] + (int)DAT_004bc4ec;
  FUN_00482760((undefined4 *)&DAT_00508180,param_1,&local_38);
  local_38 = local_38 + _DAT_004f2b40;
  local_34 = local_34 + _DAT_004f2b44;
  local_30 = local_30 + 4000 + DAT_004f2b48;
  local_8 = DAT_004bdab0 * local_30 >> 0xc;
  local_4c = local_38;
  if (local_38 < 0) {
    local_4c = -local_38;
  }
  if (local_4c < local_8) {
    local_50 = local_34;
    if (local_34 < 0) {
      local_50 = -local_34;
    }
    if (((local_50 < DAT_004bdab0 * local_30 >> 0xd) && (DAT_004e865c < local_30)) &&
       (local_30 < 60000)) goto LAB_00452843;
  }
  if (local_c < local_8) {
    local_c = local_8;
  }
  if (local_38 < local_14) {
    local_14 = local_38;
  }
  if (local_18 < local_38) {
    local_18 = local_38;
  }
  if (local_34 < local_1c) {
    local_1c = local_34;
  }
  if (local_20 < local_34) {
    local_20 = local_34;
  }
  if (local_30 < local_24) {
    local_24 = local_30;
  }
  if (local_28 < local_30) {
    local_28 = local_30;
  }
  *param_1 = *param_1 - (int)DAT_004bc4e8;
  FUN_00482760((undefined4 *)&DAT_00508180,param_1,&local_38);
  local_38 = local_38 + _DAT_004f2b40;
  local_34 = local_34 + _DAT_004f2b44;
  local_30 = local_30 + 4000 + DAT_004f2b48;
  local_8 = DAT_004bdab0 * local_30 >> 0xc;
  local_54 = local_38;
  if (local_38 < 0) {
    local_54 = -local_38;
  }
  if (local_54 < local_8) {
    local_58 = local_34;
    if (local_34 < 0) {
      local_58 = -local_34;
    }
    if (((local_58 < DAT_004bdab0 * local_30 >> 0xd) && (DAT_004e865c < local_30)) &&
       (local_30 < 60000)) goto LAB_00452843;
  }
  if (local_c < local_8) {
    local_c = local_8;
  }
  if (local_38 < local_14) {
    local_14 = local_38;
  }
  if (local_18 < local_38) {
    local_18 = local_38;
  }
  if (local_34 < local_1c) {
    local_1c = local_34;
  }
  if (local_20 < local_34) {
    local_20 = local_34;
  }
  if (local_30 < local_24) {
    local_24 = local_30;
  }
  if (local_28 < local_30) {
    local_28 = local_30;
  }
  param_1[1] = param_1[1] + (int)DAT_004bc4ea;
  FUN_00482760((undefined4 *)&DAT_00508180,param_1,&local_38);
  local_38 = local_38 + _DAT_004f2b40;
  local_34 = local_34 + _DAT_004f2b44;
  local_30 = local_30 + 4000 + DAT_004f2b48;
  local_8 = DAT_004bdab0 * local_30 >> 0xc;
  local_5c = local_38;
  if (local_38 < 0) {
    local_5c = -local_38;
  }
  if (local_5c < local_8) {
    local_60 = local_34;
    if (local_34 < 0) {
      local_60 = -local_34;
    }
    if (((local_60 < DAT_004bdab0 * local_30 >> 0xd) && (DAT_004e865c < local_30)) &&
       (local_30 < 60000)) goto LAB_00452843;
  }
  if (local_c < local_8) {
    local_c = local_8;
  }
  if (local_38 < local_14) {
    local_14 = local_38;
  }
  if (local_18 < local_38) {
    local_18 = local_38;
  }
  if (local_34 < local_1c) {
    local_1c = local_34;
  }
  if (local_20 < local_34) {
    local_20 = local_34;
  }
  if (local_30 < local_24) {
    local_24 = local_30;
  }
  if (local_28 < local_30) {
    local_28 = local_30;
  }
  param_1[2] = param_1[2] - (int)DAT_004bc4ec;
  FUN_00482760((undefined4 *)&DAT_00508180,param_1,&local_38);
  local_38 = local_38 + _DAT_004f2b40;
  local_34 = local_34 + _DAT_004f2b44;
  local_30 = local_30 + 4000 + DAT_004f2b48;
  local_8 = DAT_004bdab0 * local_30 >> 0xc;
  local_64 = local_38;
  if (local_38 < 0) {
    local_64 = -local_38;
  }
  if (local_64 < local_8) {
    local_68 = local_34;
    if (local_34 < 0) {
      local_68 = -local_34;
    }
    if (((local_68 < DAT_004bdab0 * local_30 >> 0xd) && (DAT_004e865c < local_30)) &&
       (local_30 < 60000)) goto LAB_00452843;
  }
  if (local_c < local_8) {
    local_c = local_8;
  }
  if (local_38 < local_14) {
    local_14 = local_38;
  }
  if (local_18 < local_38) {
    local_18 = local_38;
  }
  if (local_34 < local_1c) {
    local_1c = local_34;
  }
  if (local_20 < local_34) {
    local_20 = local_34;
  }
  if (local_30 < local_24) {
    local_24 = local_30;
  }
  if (local_28 < local_30) {
    local_28 = local_30;
  }
  *param_1 = *param_1 + (int)DAT_004bc4e8;
  FUN_00482760((undefined4 *)&DAT_00508180,param_1,&local_38);
  local_38 = local_38 + _DAT_004f2b40;
  local_34 = local_34 + _DAT_004f2b44;
  local_30 = local_30 + 4000 + DAT_004f2b48;
  local_8 = DAT_004bdab0 * local_30 >> 0xc;
  local_6c = local_38;
  if (local_38 < 0) {
    local_6c = -local_38;
  }
  if (local_6c < local_8) {
    local_70 = local_34;
    if (local_34 < 0) {
      local_70 = -local_34;
    }
    if (((local_70 < DAT_004bdab0 * local_30 >> 0xd) && (DAT_004e865c < local_30)) &&
       (local_30 < 60000)) goto LAB_00452843;
  }
  if (local_c < local_8) {
    local_c = local_8;
  }
  if (local_38 < local_14) {
    local_14 = local_38;
  }
  if (local_18 < local_38) {
    local_18 = local_38;
  }
  if (local_34 < local_1c) {
    local_1c = local_34;
  }
  if (local_20 < local_34) {
    local_20 = local_34;
  }
  if (local_30 < local_24) {
    local_24 = local_30;
  }
  if (local_28 < local_30) {
    local_28 = local_30;
  }
  param_1[2] = param_1[2] + (int)DAT_004bc4ec;
  FUN_00482760((undefined4 *)&DAT_00508180,param_1,&local_38);
  local_38 = local_38 + _DAT_004f2b40;
  local_34 = local_34 + _DAT_004f2b44;
  local_30 = local_30 + 4000 + DAT_004f2b48;
  iVar1 = DAT_004bdab0 * local_30 >> 0xc;
  local_74 = local_38;
  if (local_38 < 0) {
    local_74 = -local_38;
  }
  if (local_74 < iVar1) {
    local_78 = local_34;
    if (local_34 < 0) {
      local_78 = -local_34;
    }
    if (((local_78 < DAT_004bdab0 * local_30 >> 0xd) && (DAT_004e865c < local_30)) &&
       (local_30 < 60000)) goto LAB_00452843;
  }
  if (local_c < iVar1) {
    local_c = iVar1;
  }
  if (local_38 < local_14) {
    local_14 = local_38;
  }
  if (local_18 < local_38) {
    local_18 = local_38;
  }
  if (local_34 < local_1c) {
    local_1c = local_34;
  }
  if (local_20 < local_34) {
    local_20 = local_34;
  }
  if (local_30 < local_24) {
    local_24 = local_30;
  }
  if (local_28 < local_30) {
    local_28 = local_30;
  }
  local_10 = local_c >> 1;
LAB_00452843:
  local_8 = 0x452853;
  __chkesp();
  return;
}

