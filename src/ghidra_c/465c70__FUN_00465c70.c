/* FUN_00465c70 @ 00465c70 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00465c70(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  undefined4 uStack_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  iVar1 = FUN_004696b0();
  if (iVar1 != 0) {
    DAT_004f2400 = FUN_00465da0;
  }
  FUN_0046a6e0((int *)(DAT_004f2458 + 0xac),(int *)(DAT_004f2458 + 0xb0),(int *)&DAT_004bdf00);
  uStack_8 = 0x465ccd;
  __chkesp();
  return;
}

