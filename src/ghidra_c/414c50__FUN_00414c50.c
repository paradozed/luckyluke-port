/* FUN_00414c50 @ 00414c50 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00414c50(undefined1 *param_1,undefined1 param_2,undefined1 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}

