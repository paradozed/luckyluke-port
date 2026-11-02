/* FUN_00437c30 @ 00437c30 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00437c30(size_t param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_54 [16];
  uint local_14;
  uint local_10;
  int *local_c;
  void *local_8;
  
  puVar3 = local_54;
  for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_10 = CONCAT31(local_10._1_3_,1);
  if (DAT_004e84c8 == '\0') {
    uVar1 = FUN_00437b80();
    local_10 = CONCAT31(local_10._1_3_,uVar1);
  }
  local_8 = (void *)FUN_00494c40(param_1,1);
  if ((local_10 & 0xff) == 0) {
    FUN_004383a0();
  }
  else {
    if ((DAT_004bcc84 & 1) != 0) {
      FUN_004382c0();
    }
    if (((DAT_004bcc84 & 4) != 0) && (local_8 == (void *)0x0)) {
      FUN_00438470();
    }
    local_c = (int *)FUN_00494c40(0x10,1);
    if (local_c == (int *)0x0) {
      FUN_004383a0();
    }
    else {
      if (*DAT_004e84d4 == 0) {
        DAT_004e84d4[1] = (int)local_c;
        *DAT_004e84d4 = (int)local_c;
        local_c[1] = 0;
        *local_c = 0;
      }
      else {
        *(int **)(DAT_004e84d4[1] + 4) = local_c;
        *local_c = DAT_004e84d4[1];
        DAT_004e84d4[1] = (int)local_c;
        local_c[1] = 0;
      }
      local_c[3] = (int)local_8;
      local_c[2] = param_1;
      if ((DAT_004bcc84 & 0x40) != 0) {
        local_14 = 0;
        for (local_c = (int *)*DAT_004e84d4; local_c != (int *)0x0; local_c = (int *)local_c[1]) {
          if ((void *)local_c[3] == local_8) {
            local_14 = local_14 + 1;
          }
        }
        if (1 < local_14) {
          FUN_00438400();
        }
      }
      DAT_004e84c0 = DAT_004e84c0 + param_1;
      if (DAT_004e84c4 < DAT_004e84c0) {
        DAT_004e84c4 = DAT_004e84c0;
      }
      _memset(local_8,0,param_1);
    }
  }
  local_8 = (void *)0x437e1e;
  __chkesp();
  return;
}

