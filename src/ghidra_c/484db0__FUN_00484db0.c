/* FUN_00484db0 @ 00484db0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00484db0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [17];
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 != -0x22222223) {
    iVar1 = *(int *)(*(int *)(param_1 + 0xc4) + 8);
    *(undefined2 *)(*(int *)(param_1 + 0xc4) + 0x28) = 1;
    if (*(short *)(iVar1 + 4) == 0) {
      if (*(short *)(iVar1 + 8) != 0) {
        *(undefined2 *)(*(int *)(param_1 + 0xc4) + 0x28) = 2;
      }
    }
    else {
      *(undefined2 *)(*(int *)(param_1 + 0xc4) + 0x28) = 0;
    }
  }
  return;
}

