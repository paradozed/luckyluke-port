/* FUN_00494110 @ 00494110 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00494110(undefined *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  uint local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = 0;
  while( true ) {
    if (9 < local_8) {
      return;
    }
    if (&DAT_004e8af0 + local_8 * 0x20 == param_1) break;
    local_8 = local_8 + 1;
  }
  (&DAT_004e8c30)[local_8] = 1;
  return;
}

