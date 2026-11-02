/* FUN_0046d4c0 @ 0046d4c0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046d4c0(void)

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
  FUN_00466510(0,FUN_0046d3b0);
  DAT_004f22a0 = 0xff;
  _DAT_004f2298 = 0;
  DAT_004f23f8 = FUN_0046d3d0;
  FUN_0046d3d0();
  uStack_8 = 0x46d513;
  __chkesp();
  return;
}

