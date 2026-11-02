/* FUN_0041fc30 @ 0041fc30 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041fc30(char param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 != '\0') {
    _param_1 = (uint)(byte)(param_1 - 1);
    (&DAT_004d2394)[_param_1 * 0x10] = 1;
  }
  return;
}

