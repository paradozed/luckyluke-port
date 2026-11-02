/* FUN_0046b2a0 @ 0046b2a0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0046b2a0(void)

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
  uVar1 = FUN_0041ff20();
  if ((uVar1 & 0xff) == 1) {
    FUN_0041f5e0(2,5,0,0x1fff,0x400,'\0');
  }
  FUN_00466510(4,FUN_0046b250);
  FUN_004663b0(DAT_004f23fc,1,FUN_0046b1e0);
  FUN_004663b0(DAT_004f2404,0,FUN_0046aae0);
  *(uint *)(DAT_004f2458 + 0x10) = *(uint *)(DAT_004f2458 + 0x10) & 0xffffffbf;
  DAT_004f23f8 = FUN_0046af20;
  FUN_0046af20();
  uStack_8 = 0x46b34b;
  __chkesp();
  return;
}

