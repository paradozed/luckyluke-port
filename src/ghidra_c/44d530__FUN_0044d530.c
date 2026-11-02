/* FUN_0044d530 @ 0044d530 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044d530(void)

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
  FUN_0044ce70(3,FUN_0044d460);
  DAT_004f2c79 = 0xff;
  DAT_004f2c60 = FUN_0044d580;
  FUN_0044d580();
  uStack_8 = 0x44d57a;
  __chkesp();
  return;
}

