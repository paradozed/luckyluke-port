/* FUN_004662e0 @ 004662e0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004662e0(void)

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
  DAT_004f2438 = (undefined2)DAT_004f2744;
  DAT_004f245c = (undefined2)DAT_004f2750;
  if (DAT_004f23c4 != (code *)0x0) {
    (*DAT_004f23c4)();
    __chkesp();
  }
  if (DAT_004f23b8 != (code *)0x0) {
    (*DAT_004f23b8)();
    __chkesp();
  }
  if (DAT_004f23f8 != (code *)0x0) {
    (*DAT_004f23f8)();
    __chkesp();
  }
  (**(code **)(*(int *)(*DAT_004f2458 + 0xd0) + 4))(*DAT_004f2458);
  __chkesp();
  if (DAT_004f23c0 != (code *)0x0) {
    (*DAT_004f23c0)();
    __chkesp();
  }
  uStack_8 = 0x4663a5;
  __chkesp();
  return;
}

