/* FUN_0046c910 @ 0046c910 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0046c910(void)

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
  (**(code **)(*(int *)(*DAT_004f22a4 + 0xd0) + 4))(*DAT_004f22a4);
  __chkesp();
  if (DAT_004f23b0 != (code *)0x0) {
    (*DAT_004f23b0)();
    __chkesp();
  }
  if (DAT_004f2294 != (code *)0x0) {
    (*DAT_004f2294)();
    __chkesp();
  }
  uStack_8 = 0x46c98a;
  __chkesp();
  return;
}

