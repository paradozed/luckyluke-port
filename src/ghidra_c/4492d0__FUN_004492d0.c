/* FUN_004492d0 @ 004492d0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004492d0(void)

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
  if (DAT_004f2a0c != 0) {
    FUN_004ae1b0(DAT_004f2a0c);
    DAT_004f2a0c = 0;
  }
  if (DAT_004f2830 != 0) {
    FUN_004ae1b0(DAT_004f2830);
    DAT_004f2830 = 0;
  }
  if (DAT_004f1608 != 0) {
    FUN_004ae1b0(DAT_004f1608);
    DAT_004f1608 = 0;
  }
  uStack_8 = 0x44934f;
  __chkesp();
  return;
}

