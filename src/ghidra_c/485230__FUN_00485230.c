/* FUN_00485230 @ 00485230 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_00485230(int param_1,int param_2,undefined2 param_3,undefined2 param_4,undefined2 param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [17];
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x20) + param_2 * 0x28;
  *(byte *)(iVar1 + 0x14) = *(byte *)(iVar1 + 0x14) | 2;
  *(undefined2 *)(iVar1 + 0x1c) = param_3;
  *(undefined2 *)(iVar1 + 0x1e) = param_4;
  *(undefined2 *)(iVar1 + 0x20) = param_5;
  return;
}

