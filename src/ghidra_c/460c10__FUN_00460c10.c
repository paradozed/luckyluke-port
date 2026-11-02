/* FUN_00460c10 @ 00460c10 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00460c10(void)

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
  FUN_0045f940(0xf,FUN_0045f6e0);
  DAT_004f2598 = FUN_00460bf0;
  FUN_00460bf0();
  uStack_8 = 0x460c53;
  __chkesp();
  return;
}

