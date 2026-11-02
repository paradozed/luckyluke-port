/* FUN_00463820 @ 00463820 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00463820(void)

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
  if ((DAT_004f2596 == 1) && (DAT_004f2598 == FUN_004616b0)) {
    FUN_00466510(0xf,FUN_00463730);
    DAT_004f2c6e = 0xff;
    DAT_004f23f8 = FUN_004638b0;
    FUN_004638b0();
  }
  else {
    FUN_00466510(0xc,FUN_00463730);
    DAT_004f2c6e = 0xff;
    DAT_004f23f8 = FUN_004639e0;
    FUN_004639e0();
  }
  uStack_8 = 0x4638aa;
  __chkesp();
  return;
}

