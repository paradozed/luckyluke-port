/* FUN_0045fdc0 @ 0045fdc0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0045fdc0(void)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *puVar2;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(short *)(*(int *)(DAT_004f1578 + 4) + 0x32) = *(short *)(*(int *)(DAT_004f1578 + 4) + 0x32) + -1
  ;
  FUN_0045f940(0xc,FUN_0045fcd0);
  DAT_004f2c79 = 0xff;
  DAT_004f2598 = FUN_0045fe30;
  FUN_0045fe30(extraout_ECX,extraout_EDX);
  uStack_8 = 0x45fe26;
  __chkesp();
  return;
}

