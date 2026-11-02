/* FUN_0042cfb0 @ 0042cfb0 */
/* decompiled from Lucky.exe (Game.run) */


int __cdecl FUN_0042cfb0(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [17];
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x10);
  *(undefined2 *)(*(int *)(*(int *)(param_1 + 0x20) + 4) + iVar1 * 8) = param_2;
  *(undefined2 *)(*(int *)(*(int *)(param_1 + 0x20) + 4) + 2 + iVar1 * 8) = param_3;
  *(undefined2 *)(*(int *)(*(int *)(param_1 + 0x20) + 4) + 4 + iVar1 * 8) = param_4;
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  return *(int *)(param_1 + 0xc0) + iVar1 * 8;
}

