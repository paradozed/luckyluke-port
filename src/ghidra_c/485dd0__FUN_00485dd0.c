/* FUN_00485dd0 @ 00485dd0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_00485dd0(int param_1,undefined2 param_2,undefined1 param_3,undefined1 param_4,undefined4 param_5
            )

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined2 *)(*(int *)(param_1 + 0xcc) + 0xe) = param_2;
  *(undefined1 *)(*(int *)(param_1 + 0xcc) + 0x12) = param_3;
  *(undefined1 *)(*(int *)(param_1 + 0xcc) + 0x13) = param_4;
  *(undefined4 *)(*(int *)(param_1 + 0xcc) + 0x14) = param_5;
  return;
}

