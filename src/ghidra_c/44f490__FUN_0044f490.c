/* FUN_0044f490 @ 0044f490 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044f490(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar4 = local_44;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  cVar1 = FUN_0041fbb0(DAT_004f2c7a);
  if (cVar1 == '\0') {
    FUN_0041fc80(DAT_004f2c7a);
    uVar2 = FUN_0046d700();
    if ((uVar2 & 0xffff) % 7 == 3) {
      DAT_004f2c7a = FUN_0041f5e0(3,0x10,0,0x9c4,0x800,'\0');
    }
    else {
      uVar2 = FUN_0046d700();
      if ((uVar2 & 0xffff) % 5 == 3) {
        DAT_004f2c7a = FUN_0041f5e0(3,0x11,0,0x9c4,0x800,'\0');
      }
      else {
        DAT_004f2c7a = '\0';
      }
    }
    FUN_0041fc30(DAT_004f2c7a);
  }
  uStack_8 = 0x44f565;
  __chkesp();
  return;
}

