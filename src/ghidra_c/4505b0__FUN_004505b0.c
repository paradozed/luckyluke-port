/* FUN_004505b0 @ 004505b0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004505b0(void)

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
  cVar1 = FUN_0041fbb0(DAT_004f2c6f);
  if (cVar1 == '\0') {
    FUN_0041fc80(DAT_004f2c6f);
    uVar2 = FUN_0046d700();
    if ((uVar2 & 0xffff) % 0x1e == 0xf) {
      DAT_004f2c6f = FUN_0041f5e0(2,7,0,2000,0x800,'\0');
    }
    else {
      uVar2 = FUN_0046d700();
      if ((uVar2 & 0xffff) % 0x1e == 0xf) {
        DAT_004f2c6f = FUN_0041f5e0(2,8,0,2000,0x800,'\0');
      }
      else {
        DAT_004f2c6f = '\0';
      }
    }
    FUN_0041fc30(DAT_004f2c6f);
  }
  uStack_8 = 0x450685;
  __chkesp();
  return;
}

