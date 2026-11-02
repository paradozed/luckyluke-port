/* FUN_0044d2f0 @ 0044d2f0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044d2f0(void)

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
  if ((int)(uint)DAT_004bd066 < (int)*(short *)(*(int *)(DAT_004f1578 + 4) + 0x36)) {
    DAT_004f2c60 = FUN_0044d530;
    FUN_0044d530();
  }
  else {
    DAT_004f2c60 = FUN_0044d1f0;
    FUN_0044d1f0();
  }
  uStack_8 = 0x44d34d;
  __chkesp();
  return;
}

