/* FUN_00437480 @ 00437480 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00437480(void)

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
  if (DAT_004e84b4 != (void *)0x0) {
    FUN_00435e90(DAT_004e84b4);
    DAT_004e84b4 = (void *)0x0;
  }
  uStack_8 = 0x4374c6;
  __chkesp();
  return;
}

