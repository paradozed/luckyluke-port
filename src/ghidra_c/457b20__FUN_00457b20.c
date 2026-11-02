/* FUN_00457b20 @ 00457b20 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00457b20(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)(param_1 + 0x90) = param_2;
  *(undefined4 *)(param_1 + 0x94) = param_3;
  *(undefined4 *)(param_1 + 0x98) = param_4;
  return;
}

