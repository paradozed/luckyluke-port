/* FUN_0044c910 @ 0044c910 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044c910(void)

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
  DAT_004e8628 = DAT_004e8abc >> 5;
  if (DAT_004e8624 == 0) {
    DAT_004e8624 = DAT_004e8abc >> 5;
  }
  if (400 < DAT_004e8628 - DAT_004e8624) {
    DAT_004e8624 = 0;
    DAT_004e8914 = 0x15;
    DAT_004f1e21 = 1;
    FUN_0041f830('\x01');
    FUN_004200e0('\x01');
    DAT_004f23f8 = FUN_0044beb0;
    DAT_004f2c60 = FUN_0044d830;
    DAT_004e861c = 0;
    DAT_004e861d = 0;
    DAT_004e861e = 0;
    DAT_004e861f = 0;
    DAT_004e8813 = 0;
  }
  uStack_8 = 0x44c9d3;
  __chkesp();
  return;
}

