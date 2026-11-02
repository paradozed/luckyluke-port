/* FUN_0040c030 @ 0040c030 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 FUN_0040c030(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return CONCAT22(0xcccc,DAT_004bcfdc);
}

