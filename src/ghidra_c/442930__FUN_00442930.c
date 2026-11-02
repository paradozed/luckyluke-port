/* FUN_00442930 @ 00442930 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00442930(uint *param_1,uint param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_54 [16];
  int local_14;
  uint local_10;
  int local_c;
  uint local_8;
  
  puVar4 = local_54;
  for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_c = 0;
  FUN_004988b0(param_1,0,0);
  for (local_8 = 0; local_8 < param_2; local_8 = local_8 + 1) {
    uVar1 = FUN_00498340((int *)param_1);
    local_10 = CONCAT31(local_10._1_3_,(char)uVar1);
    if ((uVar1 & 0xff) == 0xd) {
      uVar1 = FUN_00498340((int *)param_1);
      local_10 = CONCAT31(local_10._1_3_,(char)uVar1);
      local_8 = local_8 + 1;
      if ((uVar1 & 0xff) == 10) {
        local_c = local_c + 1;
      }
    }
  }
  if ((local_10 & 0xff) != 10) {
    local_c = local_c + 1;
  }
  FUN_004988b0(param_1,0,0);
  if (param_3 != (int *)0x0) {
    local_14 = 0;
    iVar3 = FUN_00494c40(local_c * 4 + 4,1);
    *param_3 = iVar3;
    if (*param_3 != 0) {
      *(undefined4 *)(*param_3 + local_14 * 4) = 0;
      local_14 = local_14 + 1;
      for (local_8 = 0; local_8 < param_2; local_8 = local_8 + 1) {
        uVar2 = FUN_00498340((int *)param_1);
        local_10 = CONCAT31(local_10._1_3_,(char)uVar2);
        uVar1 = local_8;
        if ((uVar2 & 0xff) == 0xd) {
          uVar2 = FUN_00498340((int *)param_1);
          local_10 = CONCAT31(local_10._1_3_,(char)uVar2);
          uVar1 = local_8 + 1;
          if ((uVar2 & 0xff) == 10) {
            *(uint *)(*param_3 + local_14 * 4) = local_8 + 2;
            local_14 = local_14 + 1;
          }
        }
        local_8 = uVar1;
      }
      FUN_004988b0(param_1,0,0);
    }
  }
  local_8 = 0x442ad9;
  __chkesp();
  return;
}

