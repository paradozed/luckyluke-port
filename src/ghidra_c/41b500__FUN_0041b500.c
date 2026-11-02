/* FUN_0041b500 @ 0041b500 */
/* decompiled from Lucky.exe (Game.run) */


undefined2 __cdecl FUN_0041b500(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *(undefined2 *)(param_1 + 2);
}

