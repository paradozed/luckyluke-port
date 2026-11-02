/* FUN_00465df0 @ 00465df0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00465df0(void)

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
  iVar1 = FUN_004696b0();
  if (iVar1 == 0) {
    DAT_004f2400 = FUN_00465c20;
  }
  else if ((DAT_004f2438 & 0x4000) != 0) {
    DAT_004f2400 = FUN_00465f40;
  }
  FUN_0046a6e0((int *)(DAT_004f2458 + 0xac),(int *)(DAT_004f2458 + 0xb0),(int *)&DAT_004bdf30);
  uStack_8 = 0x465e6c;
  __chkesp();
  return;
}

