/* FUN_0044ecc0 @ 0044ecc0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044ecc0(void)

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
  if (DAT_004e8622 != '\0') {
    FUN_0044d930();
  }
  if ((int)(uint)DAT_004bd068 <= (int)*(short *)(*(int *)(DAT_004f1578 + 4) + 0x36)) {
    DAT_004f2c60 = FUN_0044ed70;
    FUN_0044ed70();
  }
  uStack_8 = 0x44ed1e;
  __chkesp();
  return;
}

