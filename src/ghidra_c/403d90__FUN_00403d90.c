/* FUN_00403d90 @ 00403d90 */
/* decompiled from Lucky.exe (Game.run) */


bool FUN_00403d90(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return DAT_004d1d64 != 0;
}

