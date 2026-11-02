/* FUN_004a50c0 @ 004a50c0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_004a50c0(int param_1)

{
  code *local_18;
  undefined4 *local_14;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  
  switch(param_1) {
  case 2:
    local_14 = &DAT_004e8e2c;
    local_18 = DAT_004e8e2c;
    break;
  default:
    return 0xffffffff;
  case 4:
  case 8:
  case 0xb:
    local_14 = siglookup(param_1);
    local_14 = local_14 + 2;
    local_18 = (code *)*local_14;
    break;
  case 0xf:
    local_14 = &DAT_004e8e38;
    local_18 = DAT_004e8e38;
    break;
  case 0x15:
    local_14 = &DAT_004e8e30;
    local_18 = DAT_004e8e30;
    break;
  case 0x16:
    local_14 = &DAT_004e8e34;
    local_18 = DAT_004e8e34;
  }
  if (local_18 != (code *)0x1) {
    if (local_18 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
      __exit(3);
    }
    if (((param_1 == 8) || (param_1 == 0xb)) || (param_1 == 4)) {
      local_10 = DAT_004e8d1c;
      DAT_004e8d1c = 0;
      if (param_1 == 8) {
        local_8 = DAT_004c77bc;
        DAT_004c77bc = 0x8c;
      }
    }
    if (param_1 == 8) {
      for (local_c = DAT_004c77b0; local_c < DAT_004c77b0 + _DAT_004c77b4; local_c = local_c + 1) {
        *(undefined4 *)(local_c * 0xc + 0x4c7740) = 0;
      }
    }
    else {
      *local_14 = 0;
    }
    if (param_1 == 8) {
      (*local_18)(8,DAT_004c77bc);
    }
    else {
      (*local_18)(param_1);
      if ((param_1 != 0xb) && (param_1 != 4)) {
        return 0;
      }
    }
    if (param_1 == 8) {
      DAT_004c77bc = local_8;
    }
    DAT_004e8d1c = local_10;
    return 0;
  }
  return 0;
}

