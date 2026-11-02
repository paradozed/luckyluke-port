/* FUN_004856f0 @ 004856f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004856f0(byte *param_1,int param_2,short param_3,short param_4,uint param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  undefined2 local_10;
  int local_c;
  int local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = *(int *)(param_1 + 0xcc);
  local_c = *(int *)(param_2 + 8);
  local_10 = *(undefined2 *)(local_c + 4);
  FUN_00485a70(param_1,param_2,local_10,param_3,param_4,0,0,param_5 & 0xffff);
  if (local_8 != 0) {
    *(uint *)(local_8 + 0x14) = param_5 & 0xffff;
  }
  if (param_3 == param_4) {
    if (local_8 == 0) {
      FUN_00485e30((int)param_1,FUN_004856d0,param_1);
    }
    else {
      *(undefined2 *)(local_8 + 6) = 0;
    }
  }
  local_8 = 0x4857b0;
  __chkesp();
  return;
}

