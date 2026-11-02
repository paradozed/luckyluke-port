/* FUN_00461990 @ 00461990 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00461990(void)

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
  FUN_00461bf0();
  DAT_004e87a0 = DAT_004e8abc >> 5;
  if (DAT_004e881c == 0) {
    DAT_004e881c = DAT_004e8abc >> 5;
  }
  if (0x32 < DAT_004e87a0 - DAT_004e881c) {
    DAT_004e881c = 0;
    DAT_004f2598 = FUN_00461a90;
    FUN_00461a90();
  }
  uStack_8 = 0x461a09;
  __chkesp();
  return;
}

