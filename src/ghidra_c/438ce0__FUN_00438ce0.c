/* FUN_00438ce0 @ 00438ce0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00438ce0(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_6c [16];
  int local_2c;
  undefined4 *local_28;
  int local_24;
  undefined4 *local_20;
  int local_1c;
  int *local_18;
  int *local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  puVar2 = local_6c;
  for (iVar1 = 0x1a; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = *DAT_004e84d0;
  local_c = 0;
  local_14 = (int *)DAT_004e84d0[0xc];
  do {
    if (local_14 == (int *)0x0) {
      if ((DAT_004e84d0[0xc] == 0) || (DAT_004e84d0[0xd] == 0)) {
        local_24 = *DAT_004e84d0;
        local_20 = (undefined4 *)FUN_00494c40(0x10,1);
        if (local_20 != (undefined4 *)0x0) {
          DAT_004e84d0[0xc] = (int)local_20;
          DAT_004e84d0[0xd] = (int)local_20;
          *local_20 = 0;
          local_20[1] = 0;
          local_20[3] = local_24;
          local_20[2] = param_1;
          DAT_004e84d0[2] = DAT_004e84d0[2] - param_1;
        }
      }
      else {
        local_10 = DAT_004e84d0[1] -
                   ((*(int *)(DAT_004e84d0[0xd] + 0xc) + *(int *)(DAT_004e84d0[0xd] + 8)) -
                   *DAT_004e84d0);
        if (param_1 <= local_10) {
          local_14 = (int *)DAT_004e84d0[0xd];
          local_2c = local_14[3] + local_14[2];
          local_28 = (undefined4 *)FUN_00494c40(0x10,1);
          if (local_28 != (undefined4 *)0x0) {
            local_14[1] = (int)local_28;
            local_28[1] = 0;
            *local_28 = local_14;
            DAT_004e84d0[0xd] = (int)local_28;
            local_28[3] = local_2c;
            local_28[2] = param_1;
            DAT_004e84d0[2] = DAT_004e84d0[2] - param_1;
          }
        }
      }
LAB_00438f8b:
      local_8 = 0x438f98;
      __chkesp();
      return;
    }
    local_10 = (local_14[3] - local_8) - local_c;
    if (param_1 <= local_10) {
      local_1c = local_8 + local_c;
      local_18 = (int *)FUN_00494c40(0x10,1);
      if (local_18 != (int *)0x0) {
        if (*local_14 == 0) {
          *local_14 = (int)local_18;
          local_18[1] = (int)local_14;
          *local_18 = 0;
          DAT_004e84d0[0xc] = (int)local_18;
          local_18[3] = local_1c;
          local_18[2] = param_1;
          DAT_004e84d0[2] = DAT_004e84d0[2] - param_1;
        }
        else {
          *local_18 = *local_14;
          local_18[1] = (int)local_14;
          *(int **)(*local_14 + 4) = local_18;
          *local_14 = (int)local_18;
          local_18[3] = local_1c;
          local_18[2] = param_1;
          DAT_004e84d0[2] = DAT_004e84d0[2] - param_1;
        }
      }
      goto LAB_00438f8b;
    }
    local_8 = local_14[3];
    local_c = local_14[2];
    local_14 = (int *)local_14[1];
  } while( true );
}

