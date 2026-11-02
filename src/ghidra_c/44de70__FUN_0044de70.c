/* FUN_0044de70 @ 0044de70 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044de70(void)

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
  FUN_00466510(1,FUN_0044de50);
  DAT_004f23f8 = FUN_0044dec0;
  FUN_0044dec0();
  uStack_8 = 0x44deb3;
  __chkesp();
  return;
}

