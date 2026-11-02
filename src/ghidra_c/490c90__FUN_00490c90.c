/* FUN_00490c90 @ 00490c90 */
/* decompiled from Lucky.exe (Game.run) */


int __cdecl FUN_00490c90(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return param_2 * 0x1c + param_1;
}

