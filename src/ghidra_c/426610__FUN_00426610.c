/* FUN_00426610 @ 00426610 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __cdecl FUN_00426610(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  DAT_00507f00 = param_1;
  return 1;
}

