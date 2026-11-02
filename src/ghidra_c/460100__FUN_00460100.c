/* FUN_00460100 @ 00460100 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00460100(void)

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
  FUN_0045f940(4,FUN_004602a0);
  DAT_004f2c79 = 0xff;
  DAT_004f2598 = FUN_00460150;
  FUN_00460150(extraout_ECX,extraout_EDX);
  uStack_8 = 0x46014a;
  __chkesp();
  return;
}

