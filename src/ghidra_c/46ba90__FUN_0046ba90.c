/* FUN_0046ba90 @ 0046ba90 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0046ba90(void)

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
    FUN_0041f5e0(2,4,0,0x1fff,0x400,'\0');
    uVar1 = FUN_0046d700();
    if ((uVar1 & 0xffff) % 5 == 3) {
      FUN_0041f5e0(3,0xe,0x32,0xfff,0x800,'\0');
    }
  }
  *(uint *)(DAT_004f2458 + 0x10) = *(uint *)(DAT_004f2458 + 0x10) & 0xfffbffdf;
  FUN_004663b0(DAT_004f2404,0,FUN_0046aae0);
  FUN_00466510(3,FUN_0046b9a0);
  *(int *)(DAT_004f2458 + 0xb4) = (int)DAT_004be0b8;
  DAT_004f23f8 = FUN_0046b9c0;
  FUN_0046b9c0();
  uStack_8 = 0x46bb6d;
  __chkesp();
  return;
}

