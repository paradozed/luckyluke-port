/* FUN_0045fbe0 @ 0045fbe0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0045fbe0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004f2564 != '\0') {
    if (DAT_004f1780 == 0) {
      DAT_004e8914 = 0x1d;
      DAT_004f1e21 = 1;
      DAT_004f16c8 = 0;
      FUN_0041f830('\x01');
      FUN_004200e0('\x01');
    }
    if (*(short *)(*(int *)(DAT_004f1578 + 4) + 0x12) == 0) {
      DAT_004f23f8 = FUN_004647d0;
      DAT_004f2598 = FUN_00461920;
      FUN_00461920();
    }
    else {
      FUN_004624f0();
    }
  }
  uStack_8 = 0x45fc79;
  __chkesp();
  return;
}

