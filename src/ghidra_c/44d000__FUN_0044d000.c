/* FUN_0044d000 @ 0044d000 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044d000(void)

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
  if (DAT_004f2c60 != (code *)0x0) {
    (*DAT_004f2c60)();
    __chkesp();
  }
  (**(code **)(*(int *)(**(int **)(&DAT_004f2c64 + (uint)DAT_004e8612 * 4) + 0xd0) + 4))
            (**(undefined4 **)(&DAT_004f2c64 + (uint)DAT_004e8612 * 4));
  __chkesp();
  uStack_8 = 0x44d075;
  __chkesp();
  return;
}

