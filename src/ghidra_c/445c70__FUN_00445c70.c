/* FUN_00445c70 @ 00445c70 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00445c70(int param_1,undefined1 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)(param_1 + 4) = *param_2;
  *(undefined1 *)(param_1 + 5) = param_2[1];
  *(undefined1 *)(param_1 + 6) = param_2[2];
  return;
}

