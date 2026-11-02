/* FUN_00450c00 @ 00450c00 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00450c00(void)

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
  cVar1 = FUN_0041fbb0(DAT_004f2c6d);
  if (cVar1 == '\0') {
    FUN_0041fc80(DAT_004f2c6d);
    uVar2 = FUN_0046d700();
    if ((uVar2 & 0xffff) % 10 == 5) {
      DAT_004f2c6d = FUN_0041f5e0(2,9,-300,0xfff,0,'\0');
    }
    else {
      DAT_004f2c6d = '\0';
    }
    FUN_0041fc30(DAT_004f2c6d);
  }
  uStack_8 = 0x450c99;
  __chkesp();
  return;
}

