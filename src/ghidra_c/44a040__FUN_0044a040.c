/* FUN_0044a040 @ 0044a040 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044a040(void)

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
  if ((DAT_004f2e22 & 0x10) != 0x10) {
    DAT_004f2e22 = DAT_004f2e22 & 0xe3 | 2;
    DAT_004f2e20 = 0xff;
    DAT_004f2e0d = 0xff;
  }
  FUN_00440f30();
  uStack_8 = 0x44a0c2;
  __chkesp();
  return;
}

