/* FUN_00460480 @ 00460480 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00460480(void)

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
  DAT_004e8810 = 1;
  DAT_004e880f = 0;
  DAT_004f2598 = FUN_0045fc80;
  FUN_0045fc80();
  uStack_8 = 0x4604c2;
  __chkesp();
  return;
}

