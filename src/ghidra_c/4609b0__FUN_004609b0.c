/* FUN_004609b0 @ 004609b0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004609b0(void)

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
  if (DAT_004f2596 == 2) {
    FUN_00460a50(*piRam004f2588,0,0,0);
    DAT_004e8914 = 0x10;
    DAT_004f1e21 = 1;
    DAT_004e8813 = 0;
    DAT_004f2800 = DAT_004f2c6c;
    FUN_0041f830('\x01');
    FUN_004200e0('\x01');
  }
  DAT_004f2598 = FUN_00460ce0;
  FUN_00460ce0();
  uStack_8 = 0x460a49;
  __chkesp();
  return;
}

