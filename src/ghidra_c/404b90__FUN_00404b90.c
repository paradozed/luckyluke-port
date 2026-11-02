/* FUN_00404b90 @ 00404b90 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00404b90(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((param_2 == 0x3bd) && (DAT_004d1dc4 != '\0')) {
    *(char *)(DAT_004d1d80 + 0xe9) = *(char *)(DAT_004d1d80 + 0xe9) + -1;
  }
  return;
}

