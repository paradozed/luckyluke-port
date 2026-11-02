/* FUN_004634d0 @ 004634d0 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 FUN_004634d0(void)

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
  if ((DAT_004f2744 & 0x20) == 0) {
    if ((DAT_004f2744 & 0x80) == 0) {
      uVar1 = 0;
    }
    else {
      DAT_004bdd50 = 0;
      if (*(char *)(DAT_004f2458 + 0x74) == '\0') {
        uVar1 = 1;
      }
      else {
        uVar1 = 2;
      }
    }
  }
  else {
    DAT_004bdd50 = 1;
    if (*(char *)(DAT_004f2458 + 0x74) == '\0') {
      uVar1 = 2;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}

