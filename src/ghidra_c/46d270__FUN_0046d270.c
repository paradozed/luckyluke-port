/* FUN_0046d270 @ 0046d270 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046d270(int param_1,undefined4 *param_2)

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
    FUN_0046d2d0(param_1,param_2);
  }
  else {
    FUN_0046d320(*(int *)(param_1 + 0xdc),param_2);
  }
  uStack_8 = 0x46d2c9;
  __chkesp();
  return;
}

