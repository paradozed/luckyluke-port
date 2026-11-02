/* FUN_0040f640 @ 0040f640 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0040f640(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (_DAT_004b4078 <= _DAT_004d1e40) {
    DAT_004d1e3c = 0;
  }
  return CONCAT22(0xcccc,(ushort)(_DAT_004b4078 <= _DAT_004d1e40));
}

