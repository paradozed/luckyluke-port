/* FUN_00409d30 @ 00409d30 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00409d30(int param_1,int param_2,char param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_50 [16];
  uint local_10;
  uint local_c;
  uint local_8;
  
  puVar3 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_10 = CONCAT31(local_10._1_3_,1);
  local_8 = CONCAT31(local_8._1_3_,param_3 + -1);
  while ((local_10 & 0xff) != 0) {
    local_10 = local_10 & 0xffffff00;
    local_c = local_c & 0xffffff00;
    while ((local_c & 0xff) < (local_8 & 0xff)) {
      if (*(int *)(param_1 + 4 + (local_c & 0xff) * 4) < *(int *)(param_1 + (local_c & 0xff) * 4)) {
        uVar1 = FUN_00409e20(param_1,CONCAT31((int3)((uint)param_1 >> 8),(char)local_c),
                             (local_c & 0xff) + 1);
        FUN_00409e80(param_2,CONCAT31((int3)((uint)uVar1 >> 8),(char)local_c),(local_c & 0xff) + 1);
        local_10 = CONCAT31(local_10._1_3_,1);
      }
      local_c = CONCAT31(local_c._1_3_,(char)local_c + '\x01');
    }
    local_8 = CONCAT31(local_8._1_3_,(char)local_8 + -1);
  }
  local_8 = 0x409e11;
  __chkesp();
  return;
}

