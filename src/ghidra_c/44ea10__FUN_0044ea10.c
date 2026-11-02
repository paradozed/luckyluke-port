/* FUN_0044ea10 @ 0044ea10 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044ea10(void)

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
  FUN_00466510(0xf,FUN_0044e970);
  DAT_004f23f8 = FUN_0044ea60;
  FUN_0044ea60();
  uStack_8 = 0x44ea53;
  __chkesp();
  return;
}

