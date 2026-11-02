/* FUN_0044a150 @ 0044a150 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044a150(void)

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
  DAT_004f2e0c = 0;
  DAT_004f2e20 = 0;
  DAT_004f2e0d = 0;
  DAT_004f2e22 = 0xc;
  FUN_00440f30();
  uStack_8 = 0x44a1b3;
  __chkesp();
  return;
}

