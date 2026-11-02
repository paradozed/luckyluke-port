/* FUN_0046c870 @ 0046c870 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046c870(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)(*(int *)(param_1 + 0xc4) + 0x38) = param_2;
  *(undefined4 *)(*(int *)(param_1 + 0xc4) + 0x3c) = param_3;
  return;
}

