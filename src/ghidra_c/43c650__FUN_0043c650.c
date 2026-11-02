/* FUN_0043c650 @ 0043c650 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0043c650(int param_1,float param_2,float param_3,float param_4)

{
  int iVar1;
  undefined4 *puVar2;
  float10 fVar3;
  undefined4 local_70 [16];
  float local_30;
  float local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int *local_18;
  float local_14;
  float local_10;
  int local_c;
  int local_8;
  
  puVar2 = local_70;
  for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_18 = (int *)FUN_0043c330();
  if (local_18 != (int *)0x0) {
    local_1c = param_1 * 2 + 2;
    local_20 = param_1 * 3;
    iVar1 = FUN_0043c390(local_18,local_1c);
    if (iVar1 == 0) {
      FUN_0043c230(local_18);
    }
    else {
      iVar1 = FUN_0043c440((int)local_18,local_20);
      if (iVar1 == 0) {
        FUN_0043c230(local_18);
      }
      else {
        local_10 = (float)_DAT_004b6aa0 / (float)param_1;
        local_14 = 0.0;
        for (local_8 = 0; local_8 < param_1; local_8 = local_8 + 1) {
          fVar3 = (float10)FUN_00497f54(local_8);
          local_2c = (float)fVar3;
          iVar1 = local_18[4];
          *(float *)(iVar1 + local_8 * 0xc) = (float)fVar3;
          fVar3 = (float10)FUN_00498004(iVar1);
          local_30 = (float)fVar3;
          *(float *)(local_18[4] + 8 + local_8 * 0xc) = (float)fVar3;
          *(undefined4 *)(local_18[4] + 4 + local_8 * 0xc) = 0x3f800000;
          *(undefined4 *)(local_18[4] + (local_8 + param_1) * 0xc) =
               *(undefined4 *)(local_18[4] + local_8 * 0xc);
          *(undefined4 *)(local_18[4] + 8 + (local_8 + param_1) * 0xc) =
               *(undefined4 *)(local_18[4] + 8 + local_8 * 0xc);
          *(undefined4 *)(local_18[4] + 4 + (local_8 + param_1) * 0xc) = 0xbf800000;
          local_14 = local_14 + local_10;
        }
        *(undefined4 *)(local_18[4] + local_8 * 0x18) = 0;
        *(undefined4 *)(local_18[4] + 8 + local_8 * 0x18) = 0;
        *(undefined4 *)(local_18[4] + 4 + local_8 * 0x18) = 0x3f800000;
        *(undefined4 *)(local_18[4] + (local_8 * 2 + 1) * 0xc) = 0;
        *(undefined4 *)(local_18[4] + 8 + (local_8 * 2 + 1) * 0xc) = 0;
        *(undefined4 *)(local_18[4] + 4 + (local_8 * 2 + 1) * 0xc) = 0xbf800000;
        for (local_8 = 0; local_8 < param_1; local_8 = local_8 + 1) {
          local_c = (local_8 + 1) % param_1;
          *(undefined4 *)(local_18[5] + local_8 * 0x54) = 0;
          iVar1 = local_18[5] + local_8 * 0x54;
          *(int *)(iVar1 + 0x18) = local_c;
          *(int *)(iVar1 + 0x1c) = local_8;
          *(int *)(iVar1 + 0x20) = param_1 << 1;
          *(undefined4 *)(iVar1 + 0x24) = 0xff;
          *(undefined4 *)(iVar1 + 0x28) = 0xff;
          *(undefined4 *)(iVar1 + 0x2c) = 0xff;
          *(undefined4 *)(local_18[5] + (param_1 + local_8) * 0x54) = 1;
          local_28 = local_18[5] + (param_1 + local_8) * 0x54;
          *(int *)(local_28 + 0x1c) = local_c;
          *(int *)(local_28 + 0x20) = local_8;
          *(int *)(local_28 + 0x24) = local_c + param_1;
          *(int *)(local_28 + 0x28) = local_8 + param_1;
          *(undefined4 *)(local_28 + 0x2c) = 0xff;
          *(undefined4 *)(local_28 + 0x30) = 0xff;
          *(undefined4 *)(local_28 + 0x34) = 0xff;
          *(undefined4 *)(local_18[5] + (local_8 + param_1 * 2) * 0x54) = 0;
          local_24 = local_18[5] + (local_8 + param_1 * 2) * 0x54;
          *(int *)(local_24 + 0x18) = local_8 + param_1;
          *(int *)(local_24 + 0x1c) = local_c + param_1;
          *(int *)(local_24 + 0x20) = param_1 * 2 + 1;
          *(undefined4 *)(local_24 + 0x24) = 0xff;
          *(undefined4 *)(local_24 + 0x28) = 0xff;
          *(undefined4 *)(local_24 + 0x2c) = 0xff;
        }
        FUN_0043a7d0(local_18,param_2,param_3,param_4);
        FUN_00439d40(local_18 + 6);
      }
    }
  }
  local_8 = 0x43ca06;
  __chkesp();
  return;
}

