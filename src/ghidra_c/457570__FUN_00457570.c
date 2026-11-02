/* FUN_00457570 @ 00457570 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00457570(int param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_dc [16];
  int local_9c;
  uint local_98;
  int local_94;
  int local_90;
  int local_8c;
  undefined1 local_84 [32];
  short local_64;
  short local_62;
  short local_60;
  undefined2 local_5e;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  uint local_24;
  uint local_20;
  uint local_1c;
  undefined4 *local_18;
  undefined4 *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar2 = local_dc;
  for (iVar1 = 0x36; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_10 = *(int *)(param_1 + 4);
  local_1c = 0xffffffff;
  local_20 = CONCAT22(local_20._2_2_,*(undefined2 *)(param_1 + 0xc));
  local_24 = local_24 & 0xffff0000;
  local_8 = local_10;
  while (local_c = local_8, (local_24 & 0xffff) < (local_20 & 0xffff)) {
    local_14 = *(undefined4 **)(local_8 + 4);
    local_18 = *(undefined4 **)(local_8 + 8);
    local_5c = *local_14;
    local_58 = local_14[1];
    local_54 = local_14[2];
    local_64 = (short)*local_18 - (short)*local_14;
    local_62 = (short)local_18[1] - (short)local_14[1];
    local_60 = (short)local_18[2] - (short)local_14[2];
    local_5e = *(undefined2 *)(local_8 + 0xc);
    local_8 = local_8 + *(int *)(local_8 + 0x10) * 4 + 0x14;
    local_9c = FUN_00457920((int)local_84,param_2,&local_94);
    if ((-1 < local_9c) && (local_9c <= *(int *)(local_c + 0xc))) {
      local_94 = local_94 - *param_2;
      local_90 = local_90 - param_2[1];
      local_8c = local_8c - param_2[2];
      local_98 = local_94 * local_94 + local_90 * local_90 + local_8c * local_8c;
      if (local_98 < local_1c) {
        local_10 = local_c;
        local_1c = local_98;
      }
    }
    local_24 = CONCAT22(local_24._2_2_,(short)local_24 + 1);
  }
  local_8 = 0x457736;
  __chkesp();
  return;
}

