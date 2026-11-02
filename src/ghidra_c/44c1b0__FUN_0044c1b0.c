/* FUN_0044c1b0 @ 0044c1b0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044c1b0(void)

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
  DAT_004e8610 = 0;
  FUN_00466510(4,FUN_0044c0f0);
  DAT_004f2c6e = 0xff;
  DAT_004f23f8 = FUN_0044c210;
  FUN_0044c210();
  uStack_8 = 0x44c201;
  __chkesp();
  return;
}

