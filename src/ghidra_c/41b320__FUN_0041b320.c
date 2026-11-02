/* FUN_0041b320 @ 0041b320 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041b320(int param_1,undefined1 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)(param_1 + 1) = param_2;
  *(undefined ***)(param_1 + 0xd0) = &PTR_FUN_004c6480 + (uint)*(byte *)(param_1 + 1) * 5;
  return;
}

