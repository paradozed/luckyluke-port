/* FUN_0045fc80 @ 0045fc80 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0045fc80(void)

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
  FUN_0045f940(0,FUN_0045fba0);
  DAT_004f2598 = FUN_0045fbe0;
  FUN_0045fbe0();
  uStack_8 = 0x45fcc3;
  __chkesp();
  return;
}

