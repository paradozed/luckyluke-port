/* FUN_004743d0 @ 004743d0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004743d0(void)

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
  if (DAT_004f1794 == 0) {
    if (DAT_004f1674 != (code *)0x0) {
      (*DAT_004f1674)();
      __chkesp();
    }
    if (DAT_004f166c != (code *)0x0) {
      (*DAT_004f166c)();
      __chkesp();
    }
  }
  uStack_8 = 0x474439;
  __chkesp();
  return;
}

