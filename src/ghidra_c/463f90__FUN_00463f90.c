/* FUN_00463f90 @ 00463f90 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00463f90(void)

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
  *(short *)(DAT_004f25a8 + 0xe) = *(short *)(DAT_004f25a8 + 0xe) + 1;
  FUN_00466510(7,FUN_00463ab0);
  DAT_004f2c6e = 0xff;
  DAT_004f23f8 = FUN_00464000;
  FUN_00464000();
  uStack_8 = 0x463ff1;
  __chkesp();
  return;
}

