/* FUN_00464450 @ 00464450 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00464450(void)

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
  FUN_00466510(10,FUN_00463ab0);
  DAT_004f23f8 = FUN_004644a0;
  FUN_004644a0();
  uStack_8 = 0x464493;
  __chkesp();
  return;
}

