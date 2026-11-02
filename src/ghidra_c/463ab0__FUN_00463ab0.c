/* FUN_00463ab0 @ 00463ab0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00463ab0(void)

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
  DAT_004f25c4 = 0;
  if (*(short *)(*(int *)(DAT_004f1578 + 4) + 0x32) == 0) {
    DAT_004f23f8 = FUN_00464880;
    DAT_004f2598 = FUN_00460b50;
    FUN_00460b50();
  }
  else {
    DAT_004f23f8 = FUN_00462ff0;
    FUN_00462ff0();
  }
  uStack_8 = 0x463b18;
  __chkesp();
  return;
}

