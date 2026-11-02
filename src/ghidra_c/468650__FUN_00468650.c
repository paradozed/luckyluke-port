/* FUN_00468650 @ 00468650 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00468650(void)

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
  DAT_004f2400 = FUN_00465a60;
  FUN_00466510(2,FUN_004685c0);
  DAT_004f23f8 = FUN_004685c0;
  FUN_004685c0();
  uStack_8 = 0x46869d;
  __chkesp();
  return;
}

