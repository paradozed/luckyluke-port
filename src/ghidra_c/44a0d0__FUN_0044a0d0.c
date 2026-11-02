/* FUN_0044a0d0 @ 0044a0d0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044a0d0(void)

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
  if ((DAT_004f2e22 & 8) != 8) {
    DAT_004f2e22 = DAT_004f2e22 & 0xe1;
    DAT_004f2e20 = 0;
  }
  FUN_00440f70();
  uStack_8 = 0x44a14b;
  __chkesp();
  return;
}

