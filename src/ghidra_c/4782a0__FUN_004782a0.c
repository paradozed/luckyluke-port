/* FUN_004782a0 @ 004782a0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004782a0(void)

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
  if (DAT_004e89d9 == '\x01') {
    do {
      uVar1 = FUN_004ae460(DAT_004e8ed4,DAT_004e8ed0);
    } while (uVar1 == 0);
    (*DAT_0050a844)();
    __chkesp();
  }
  DAT_004be2e4 = 1;
  uStack_8 = 0x4782fe;
  __chkesp();
  return;
}

