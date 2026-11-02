/* FUN_0047d910 @ 0047d910 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_0047d910(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,uint param_6)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_58 [16];
  uint local_18;
  int local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  
  puVar2 = local_58;
  for (iVar1 = 0x15; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_18 = param_6;
  switch(param_6) {
  case 0:
  case 2:
  case 4:
  case 6:
    local_14 = FUN_0047ddb0(param_2,param_3,param_4);
    break;
  case 1:
  case 3:
  case 5:
  case 7:
    local_14 = FUN_0047de20(param_2,param_3,param_4,param_5);
  }
  if (7 < param_6) {
    local_14 = FUN_0047de20(param_2,param_3,param_4,param_5);
  }
  if (DAT_004e8a94 == (undefined4 *)0x0) {
    DAT_004e8a98 = *(undefined4 **)(DAT_00508860 + DAT_004e8a8c * 4);
    DAT_004e8a8c = DAT_004e8a8c + 1;
    DAT_004e8a98[1] = 0;
    DAT_004e8a98[2] = 0;
    DAT_004e8a98[8] = param_6;
    DAT_004e8a98[3] = param_2;
    DAT_004e8a98[4] = param_3;
    DAT_004e8a98[5] = param_4;
    DAT_004e8a98[6] = param_5;
    DAT_004e8a98[7] = local_14;
    *(byte *)(DAT_004e8a98 + 9) = DAT_004e8a9c | DAT_004e8a9d;
    DAT_004e8a94 = DAT_004e8a98;
    *DAT_004e8a98 = param_1;
    local_c = DAT_004e8a98;
  }
  else if ((int)DAT_004e8a98[7] < local_14) {
    for (local_8 = DAT_004e8a98; local_8 != (undefined4 *)0x0; local_8 = (undefined4 *)local_8[2]) {
      if (local_14 < (int)local_8[7]) {
        DAT_004e8a98 = *(undefined4 **)(DAT_00508860 + DAT_004e8a8c * 4);
        DAT_004e8a8c = DAT_004e8a8c + 1;
        DAT_004e8a98[8] = param_6;
        DAT_004e8a98[3] = param_2;
        DAT_004e8a98[4] = param_3;
        DAT_004e8a98[5] = param_4;
        DAT_004e8a98[6] = param_5;
        DAT_004e8a98[7] = local_14;
        *(byte *)(DAT_004e8a98 + 9) = DAT_004e8a9c | DAT_004e8a9d;
        DAT_004e8a98[1] = local_8[1];
        DAT_004e8a98[2] = local_8;
        *(undefined4 **)(local_8[1] + 8) = DAT_004e8a98;
        local_8[1] = DAT_004e8a98;
        *DAT_004e8a98 = param_1;
        local_c = DAT_004e8a98;
        break;
      }
    }
    if (local_8 == (undefined4 *)0x0) {
      DAT_004e8a98 = *(undefined4 **)(DAT_00508860 + DAT_004e8a8c * 4);
      DAT_004e8a8c = DAT_004e8a8c + 1;
      DAT_004e8a98[8] = param_6;
      DAT_004e8a98[3] = param_2;
      DAT_004e8a98[4] = param_3;
      DAT_004e8a98[5] = param_4;
      DAT_004e8a98[6] = param_5;
      DAT_004e8a98[7] = local_14;
      *(byte *)(DAT_004e8a98 + 9) = DAT_004e8a9c | DAT_004e8a9d;
      DAT_004e8a98[1] = DAT_004e8a94;
      DAT_004e8a98[2] = 0;
      DAT_004e8a94[2] = DAT_004e8a98;
      DAT_004e8a94 = DAT_004e8a98;
      *DAT_004e8a98 = param_1;
      local_c = DAT_004e8a98;
    }
  }
  else {
    for (local_8 = DAT_004e8a98; local_8 != (undefined4 *)0x0; local_8 = (undefined4 *)local_8[1]) {
      if ((int)local_8[7] < local_14) {
        DAT_004e8a98 = *(undefined4 **)(DAT_00508860 + DAT_004e8a8c * 4);
        DAT_004e8a8c = DAT_004e8a8c + 1;
        DAT_004e8a98[8] = param_6;
        DAT_004e8a98[3] = param_2;
        DAT_004e8a98[4] = param_3;
        DAT_004e8a98[5] = param_4;
        DAT_004e8a98[6] = param_5;
        DAT_004e8a98[7] = local_14;
        *(byte *)(DAT_004e8a98 + 9) = DAT_004e8a9c | DAT_004e8a9d;
        DAT_004e8a98[1] = local_8;
        DAT_004e8a98[2] = local_8[2];
        *(undefined4 **)(local_8[2] + 4) = DAT_004e8a98;
        local_8[2] = DAT_004e8a98;
        *DAT_004e8a98 = param_1;
        local_c = DAT_004e8a98;
        break;
      }
      local_10 = local_8;
    }
    if (local_8 == (undefined4 *)0x0) {
      DAT_004e8a98 = *(undefined4 **)(DAT_00508860 + DAT_004e8a8c * 4);
      DAT_004e8a8c = DAT_004e8a8c + 1;
      DAT_004e8a98[8] = param_6;
      DAT_004e8a98[3] = param_2;
      DAT_004e8a98[4] = param_3;
      DAT_004e8a98[5] = param_4;
      DAT_004e8a98[6] = param_5;
      DAT_004e8a98[7] = local_14;
      *(byte *)(DAT_004e8a98 + 9) = DAT_004e8a9c | DAT_004e8a9d;
      DAT_004e8a98[1] = 0;
      DAT_004e8a98[2] = local_10;
      local_10[1] = DAT_004e8a98;
      *DAT_004e8a98 = param_1;
      local_c = DAT_004e8a98;
    }
  }
  DAT_004e8a9c = 0;
  local_8 = (undefined4 *)0x47dd81;
  __chkesp();
  return;
}

