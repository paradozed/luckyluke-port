/* FUN_00484ff0 @ 00484ff0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00484ff0(int param_1,undefined2 param_2,undefined1 param_3,undefined1 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined2 *)(*(int *)(param_1 + 0xc4) + 0x34) = param_2;
  *(undefined1 *)(*(int *)(param_1 + 0xc4) + 0x36) = param_3;
  *(undefined1 *)(*(int *)(param_1 + 0xc4) + 0x37) = param_4;
  return;
}

