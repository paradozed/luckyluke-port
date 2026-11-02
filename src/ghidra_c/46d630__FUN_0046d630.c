/* FUN_0046d630 @ 0046d630 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046d630(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar3 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_0046d700();
  if ((uVar1 & 0xffff) % 7 == 3) {
    FUN_0041f5e0(5,8,0,0xfff,0x400,'\0');
  }
  else {
    uVar1 = FUN_0046d700();
    if ((uVar1 & 0xffff) % 5 == 3) {
      FUN_0041f5e0(5,10,0,0xfff,0x400,'\0');
    }
  }
  DAT_004f22a0 = 0xff;
  DAT_004e8858 = 0;
  DAT_004e8859 = 0;
  FUN_00466510(1,FUN_0046d520);
  _DAT_004f23a4 = 0xfffffe3e;
  DAT_004f23f8 = FUN_0046d570;
  FUN_0046d570();
  uStack_8 = 0x46d6f6;
  __chkesp();
  return;
}

