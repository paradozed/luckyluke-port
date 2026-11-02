/* FUN_0044c300 @ 0044c300 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044c300(void)

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
  FUN_00466510(5,FUN_0044c2c0);
  DAT_004f23f8 = FUN_0044c350;
  FUN_0044c350();
  uStack_8 = 0x44c343;
  __chkesp();
  return;
}

