/* FUN_00482640 @ 00482640 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00482640(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_64 [16];
  int local_24;
  int local_20;
  int local_1c;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 uStack_8;
  
  puVar2 = local_64;
  for (iVar1 = 0x18; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_004824e0(param_1,param_2,param_3);
  local_14 = *(int *)(param_2 + 0x14);
  local_10 = *(undefined4 *)(param_2 + 0x18);
  local_c = *(undefined4 *)(param_2 + 0x1c);
  FUN_00482760(param_1,&local_14,&local_24);
  param_3[5] = local_24 + param_1[5];
  param_3[6] = local_20 + param_1[6];
  param_3[7] = local_1c + param_1[7];
  uStack_8 = 0x4826d5;
  __chkesp();
  return;
}

