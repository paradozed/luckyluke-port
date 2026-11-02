/* FUN_00462ee0 @ 00462ee0 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 FUN_00462ee0(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_44 [16];
  
  puVar3 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if ((DAT_004f275c & 0xf000) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = CONCAT31((int3)((DAT_004f275c & 0xf000) >> 8),1);
  }
  return uVar1;
}

