/* FUN_00486950 @ 00486950 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00486950(int param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_60 [16];
  int local_20;
  int local_1c [5];
  undefined4 uStack_8;
  
  puVar2 = local_60;
  for (iVar1 = 0x17; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_0047fbe0(param_1,param_2);
  for (local_20 = **(int **)(param_1 + 0xd8); local_20 != 0;
      local_20 = *(int *)(*(int *)(local_20 + 0xdc) + 0x3c)) {
    FUN_0047fbe0(local_20,local_1c);
    FUN_00487a10(param_2,param_2,local_1c);
  }
  uStack_8 = 0x4869d0;
  __chkesp();
  return;
}

