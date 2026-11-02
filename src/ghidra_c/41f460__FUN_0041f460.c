/* FUN_0041f460 @ 0041f460 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041f460(uint param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_90 [16];
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_c;
  int local_8;
  
  puVar2 = local_90;
  for (iVar1 = 0x23; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = **(int **)(*(int *)(&DAT_004f1e40 + (param_1 & 0xffff) * 4) + 8);
  local_1c = *(undefined4 *)(local_8 + 0x90);
  local_18 = *(undefined4 *)(local_8 + 0x94);
  local_14 = *(undefined4 *)(local_8 + 0x98);
  local_c = **(int **)(*(int *)(&DAT_004f1e40 + (param_2 & 0xffff) * 4) + 8);
  local_2c = *(undefined4 *)(local_c + 0x90);
  local_28 = *(undefined4 *)(local_c + 0x94);
  local_24 = *(undefined4 *)(local_c + 0x98);
  FUN_00451d70(local_8,&local_30,&local_34);
  FUN_00451d70(local_c,&local_38,&local_3c);
  local_40 = local_38 - local_30;
  local_44 = local_3c - local_34;
  if ((local_40 != 0) && (local_44 != 0)) {
    if (local_40 < 1) {
      local_4c = local_40;
      if (local_40 < 0) {
        local_4c = -local_40;
      }
      local_50 = local_44;
      if (local_44 < 0) {
        local_50 = -local_44;
      }
      FUN_004836a0(local_50,local_4c);
    }
    else {
      local_48 = local_44;
      if (local_44 < 0) {
        local_48 = -local_44;
      }
      FUN_004836a0(local_48,local_40);
    }
  }
  local_8 = 0x41f5d9;
  __chkesp();
  return;
}

