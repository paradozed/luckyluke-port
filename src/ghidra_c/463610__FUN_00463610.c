/* FUN_00463610 @ 00463610 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00463610(void)

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
  FUN_00466510(0xb,FUN_00463560);
  DAT_004f2c6e = 0xff;
  DAT_004f23f8 = FUN_00463660;
  FUN_00463660();
  uStack_8 = 0x46365a;
  __chkesp();
  return;
}

