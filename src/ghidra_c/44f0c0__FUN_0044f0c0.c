/* FUN_0044f0c0 @ 0044f0c0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044f0c0(void)

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
  FUN_0044ce70(5,FUN_0044f050);
  DAT_004f2c79 = 0xff;
  DAT_004f2c60 = FUN_0044f110;
  FUN_0044f110();
  uStack_8 = 0x44f10a;
  __chkesp();
  return;
}

