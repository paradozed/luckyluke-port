/* FUN_0048ccf0 @ 0048ccf0 */
/* decompiled from Lucky.exe (Game.run) */


int __cdecl FUN_0048ccf0(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return param_2 * 0x10 + param_1;
}

