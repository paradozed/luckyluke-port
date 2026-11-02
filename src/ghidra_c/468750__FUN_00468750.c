/* FUN_00468750 @ 00468750 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00468750(void)

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
  *(undefined4 *)(DAT_004f2458 + 0xb0) = 0;
  DAT_004f2400 = FUN_00465ab0;
  FUN_00466510(4,FUN_00465a40);
  DAT_004f23f8 = FUN_004686b0;
  FUN_004686b0();
  uStack_8 = 0x4687ac;
  __chkesp();
  return;
}

