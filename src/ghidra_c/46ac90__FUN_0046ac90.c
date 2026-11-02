/* FUN_0046ac90 @ 0046ac90 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046ac90(void)

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
    FUN_0041f5e0(2,6,0,0xfff,0x400,'\0');
    FUN_0041f5e0(4,7,0,0x3fff,0,'\0');
  }
  if ((short)DAT_004f2458[0x29] == *(short *)(*(int *)(*DAT_004f2458 + 0xe4) + 0x58)) {
    _DAT_004e8834 = 0x60;
  }
  else {
    _DAT_004e8834 = 0xffa0;
  }
  DAT_004f2458[4] = DAT_004f2458[4] & 0xffffffdf;
  *(uint *)(*(int *)(*DAT_004f2458 + 0xe4) + 0x54) =
       *(uint *)(*(int *)(*DAT_004f2458 + 0xe4) + 0x54) | 1;
  *(undefined2 *)(DAT_004f2458 + 0x2a) = 0;
  DAT_004f23f8 = FUN_0046ab40;
  FUN_0046ab40();
  uStack_8 = 0x46ad81;
  __chkesp();
  return;
}

