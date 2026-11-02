/* FUN_00433160 @ 00433160 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 FUN_00433160(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  for (local_8 = 0; local_8 < 100; local_8 = local_8 + 1) {
    (&DAT_004f5d80)[local_8] = 0;
  }
  return 1;
}

