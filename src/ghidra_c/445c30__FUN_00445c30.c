/* FUN_00445c30 @ 00445c30 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00445c30(int param_1,undefined2 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined2 *)(param_1 + 0x14) = *param_2;
  *(undefined2 *)(param_1 + 0x16) = param_2[1];
  return;
}

