/* FUN_0040f060 @ 0040f060 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040f060(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (*(int *)(param_1 + 0xdc) == 0) {
    FUN_0040f0d0(param_1,param_2,param_3,param_4);
  }
  else {
    FUN_0040f120(*(int *)(param_1 + 0xdc),param_2,param_3,param_4);
  }
  uStack_8 = 0x40f0c9;
  __chkesp();
  return;
}

