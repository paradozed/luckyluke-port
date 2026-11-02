/* FUN_0046b0c0 @ 0046b0c0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0046b0c0(void)

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
  *(undefined4 *)(DAT_004f2458 + 0xac) = 0;
  FUN_0041f7b0(DAT_004f23bc);
  FUN_0041fc80(DAT_004f23bc);
  DAT_004f23bc = 0;
  uVar1 = FUN_0041ff20();
  if ((uVar1 & 0xff) == 1) {
    FUN_0041f5e0(2,1,0,0x3fff,0x400,'\0');
  }
  FUN_00466510(5,FUN_0046ae00);
  uVar1 = FUN_0041ff20();
  if ((uVar1 & 0xff) == 1) {
    FUN_0041f5e0(3,0xd,100,0x1fff,0x800,'\0');
  }
  FUN_004663b0(DAT_004f2404,5,FUN_0046aae0);
  uVar1 = FUN_0041ff20();
  if ((uVar1 & 0xff) == 1) {
    FUN_0041f5e0(4,0xf,0,0x1fff,0,'\0');
  }
  FUN_004663b0(DAT_004f23fc,2,FUN_0046ae40);
  DAT_004f23f8 = FUN_00465a40;
  FUN_00465a40();
  uStack_8 = 0x46b1da;
  __chkesp();
  return;
}

