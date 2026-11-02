/* FUN_0044d830 @ 0044d830 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044d830(void)

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
  *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x36) = 0;
  FUN_0044ce70(6,FUN_0044d7e0);
  DAT_004f2c6d = 0;
  DAT_004f2c60 = FUN_0044d890;
  FUN_0044d890();
  uStack_8 = 0x44d888;
  __chkesp();
  return;
}

