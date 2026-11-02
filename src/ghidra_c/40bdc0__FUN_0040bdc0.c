/* FUN_0040bdc0 @ 0040bdc0 */
/* decompiled from Lucky.exe (Game.run) */


bool FUN_0040bdc0(void)

{
  int iVar1;
  undefined4 *puVar2;
  bool bVar3;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  bVar3 = (DAT_004f1794 & 1) != 0;
  if (bVar3) {
    DAT_004f1794 = DAT_004f1794 | 4;
  }
  return bVar3;
}

