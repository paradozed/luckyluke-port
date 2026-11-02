/* FUN_0045ee90 @ 0045ee90 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0045ee90(void)

{
  char cVar1;
  short sVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_48 [16];
  uint local_8;
  
  puVar4 = local_48;
  for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_8 = local_8 & 0xffff0000;
  if (DAT_004bdcf0 == 0) {
    if ((DAT_004f5a88 & 0x80) != 0) {
      sVar2 = FUN_00482c60(DAT_004e879a);
      DAT_004f2b74 = DAT_004f2b74 + ((int)((int)sVar2 + ((int)sVar2 >> 0x1f & 7U)) >> 3);
      sVar2 = FUN_00482cb0(DAT_004e879a);
      DAT_004f2b6c = DAT_004f2b6c - ((int)((int)sVar2 + ((int)sVar2 >> 0x1f & 7U)) >> 3);
    }
    if ((DAT_004f5a90 & 0x80) != 0) {
      sVar2 = FUN_00482c60(DAT_004e879a);
      DAT_004f2b74 = DAT_004f2b74 - ((int)((int)sVar2 + ((int)sVar2 >> 0x1f & 7U)) >> 3);
      sVar2 = FUN_00482cb0(DAT_004e879a);
      DAT_004f2b6c = DAT_004f2b6c + ((int)((int)sVar2 + ((int)sVar2 >> 0x1f & 7U)) >> 3);
    }
    if ((DAT_004f59ec & 0x80) != 0) {
      sVar2 = FUN_00482cb0(DAT_004e879a);
      DAT_004f2b74 = DAT_004f2b74 - ((int)((int)sVar2 + ((int)sVar2 >> 0x1f & 7U)) >> 3);
      sVar2 = FUN_00482c60(DAT_004e879a);
      DAT_004f2b6c = DAT_004f2b6c - ((int)((int)sVar2 + ((int)sVar2 >> 0x1f & 7U)) >> 3);
    }
    if ((DAT_004f59ed & 0x80) != 0) {
      sVar2 = FUN_00482cb0(DAT_004e879a);
      DAT_004f2b74 = DAT_004f2b74 + ((int)((int)sVar2 + ((int)sVar2 >> 0x1f & 7U)) >> 3);
      sVar2 = FUN_00482c60(DAT_004e879a);
      DAT_004f2b6c = DAT_004f2b6c + ((int)((int)sVar2 + ((int)sVar2 >> 0x1f & 7U)) >> 3);
    }
    if ((DAT_004f59d0 & 0x80) != 0) {
      DAT_004f2b70 = DAT_004f2b70 + -0x80;
    }
    if ((DAT_004f59de & 0x80) != 0) {
      DAT_004f2b70 = DAT_004f2b70 + 0x80;
    }
    if ((DAT_004f5a8b & 0x80) != 0) {
      DAT_004e879a = DAT_004e879a + 0x20;
    }
    if ((DAT_004f5a8d & 0x80) != 0) {
      DAT_004e879a = DAT_004e879a + -0x20;
    }
    if ((DAT_004f5a91 & 0x80) != 0) {
      DAT_004e8798 = DAT_004e8798 + 0x10;
    }
    if ((DAT_004f5a89 & 0x80) != 0) {
      DAT_004e8798 = DAT_004e8798 + -0x10;
    }
    if ((DAT_004f5a87 & 0x80) != 0) {
      DAT_004e8798 = 0;
    }
    if (DAT_004e8581 != '\0') {
      FUN_00451500(&DAT_004f2b6c,&DAT_004e8798,0);
    }
  }
  if (DAT_004bdcf0 == 1) {
    cVar1 = FUN_0043fc90(DAT_004e875c);
    if (cVar1 != '\0') {
      local_8 = local_8 | 0x10;
    }
    cVar1 = FUN_0043fc90(DAT_004e8760);
    if (cVar1 != '\0') {
      local_8 = local_8 | 0x40;
    }
    cVar1 = FUN_0043fc90(DAT_004e8754);
    if (cVar1 != '\0') {
      local_8 = local_8 | 0x80;
    }
    cVar1 = FUN_0043fc90(DAT_004e8758);
    if (cVar1 != '\0') {
      local_8 = local_8 | 0x20;
    }
    cVar1 = FUN_0043fc90(DAT_004e8764);
    if (cVar1 != '\0') {
      local_8 = local_8 | 0x2000;
    }
    cVar1 = FUN_0043fc90(DAT_004e8768);
    if (cVar1 != '\0') {
      local_8 = local_8 | 0x4000;
    }
    cVar1 = FUN_0043fc90(DAT_004e876c);
    if (cVar1 != '\0') {
      local_8 = local_8 | 0x8000;
    }
    cVar1 = FUN_0043fc90(DAT_004e8770);
    if (cVar1 != '\0') {
      local_8 = local_8 | 0x1000;
    }
    cVar1 = FUN_0043fc90(DAT_004e8774);
    if (cVar1 != '\0') {
      local_8 = local_8 | 8;
    }
    cVar1 = FUN_0043fc90(DAT_004e8778);
    if (cVar1 != '\0') {
      local_8 = local_8 | 1;
    }
    cVar1 = FUN_0043fc90(DAT_004e877c);
    if (cVar1 != '\0') {
      local_8 = local_8 | 0x100;
    }
    if ((DAT_004f5a89 & 0x80) != 0) {
      DAT_004e85fc = DAT_004e85fc + -1;
    }
    if ((DAT_004f5a91 & 0x80) != 0) {
      DAT_004e85fc = DAT_004e85fc + 1;
    }
  }
  cVar1 = FUN_0043fc90(DAT_004e8780);
  if (cVar1 != '\0') {
    FUN_0042f780();
  }
  FUN_0045e8a0(0,local_8 & 0xffff);
  local_8 = 0x45f363;
  __chkesp();
  return;
}

