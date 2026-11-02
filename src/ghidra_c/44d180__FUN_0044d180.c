/* FUN_0044d180 @ 0044d180 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044d180(void)

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
  if ((int)(uint)DAT_004bd05e < (int)*(short *)(*(int *)(DAT_004f1578 + 4) + 0x36)) {
    DAT_004f2c60 = FUN_0044d360;
    FUN_0044d360();
  }
  else {
    DAT_004f2c60 = FUN_0044d0f0;
    FUN_0044d0f0();
  }
  uStack_8 = 0x44d1dd;
  __chkesp();
  return;
}

