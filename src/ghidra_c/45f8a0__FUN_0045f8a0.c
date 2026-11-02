/* FUN_0045f8a0 @ 0045f8a0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0045f8a0(void)

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
  if (DAT_004f25f4 != (code *)0x0) {
    (*DAT_004f25f4)();
    __chkesp();
  }
  if (DAT_004f2598 != (code *)0x0) {
    (*DAT_004f2598)();
    __chkesp();
  }
  FUN_0045f700();
  FUN_00461b10();
  (**(code **)(*(int *)(**(int **)(&DAT_004f2580 + (uint)DAT_004f2596 * 4) + 0xd0) + 4))
            (**(undefined4 **)(&DAT_004f2580 + (uint)DAT_004f2596 * 4));
  __chkesp();
  uStack_8 = 0x45f937;
  __chkesp();
  return;
}

