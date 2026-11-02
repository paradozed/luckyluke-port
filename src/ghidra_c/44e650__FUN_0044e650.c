/* FUN_0044e650 @ 0044e650 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044e650(void)

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
  FUN_00466510(7,FUN_0044e600);
  DAT_004f23f8 = FUN_0044e6a0;
  FUN_0044e6a0();
  uStack_8 = 0x44e693;
  __chkesp();
  return;
}

