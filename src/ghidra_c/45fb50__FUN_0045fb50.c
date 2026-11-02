/* FUN_0045fb50 @ 0045fb50 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0045fb50(void)

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
  if (DAT_004f2564 != '\0') {
    DAT_004f25c4 = 0;
    DAT_004f23f8 = FUN_0045fc80;
    FUN_0045fc80();
  }
  uStack_8 = 0x45fb96;
  __chkesp();
  return;
}

