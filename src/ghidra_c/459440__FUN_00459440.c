/* FUN_00459440 @ 00459440 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00459440(void)

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
  DAT_004e86fc = FUN_004714a0(DAT_004f1e24);
  *(code **)(DAT_004e86fc + 4) = FUN_00459580;
  *(undefined2 *)(DAT_004e86fc + 0xc) = 0xfa;
  *(undefined1 *)(DAT_004e86fc + 0x10) = 1;
  *(undefined1 *)(DAT_004e86fc + 0x11) = 0;
  *(undefined **)(DAT_004e86fc + 8) = &DAT_004bd9d0;
  uStack_8 = 0x4594b1;
  __chkesp();
  return;
}

