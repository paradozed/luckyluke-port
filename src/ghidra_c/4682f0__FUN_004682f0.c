/* FUN_004682f0 @ 004682f0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004682f0(void)

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
  DAT_004f5556 = 0;
  DAT_004e8838 = 0xffff;
  DAT_004f2400 = FUN_00465a60;
  DAT_004f23f8 = FUN_00468160;
  FUN_00468160();
  uStack_8 = 0x46833e;
  __chkesp();
  return;
}

