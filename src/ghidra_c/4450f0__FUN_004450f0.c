/* FUN_004450f0 @ 004450f0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004450f0(void)

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
  if ((DAT_004f25a0 != (void *)0x0) && (DAT_004f25a0 != (void *)0xdddddddd)) {
    FUN_00495280(DAT_004f25a0);
  }
  if ((DAT_004f25e0 != (void *)0x0) && (DAT_004f25e0 != (void *)0xdddddddd)) {
    FUN_00495280(DAT_004f25e0);
  }
  FUN_00471210(DAT_004f1e24);
  if ((DAT_004f58a4 != (void *)0x0) && (DAT_004f58a4 != (void *)0xdddddddd)) {
    FUN_00495280(DAT_004f58a4);
  }
  FUN_004399f0(DAT_004e85e8);
  FUN_004399f0(DAT_004e85ec);
  uStack_8 = 0x4451ac;
  __chkesp();
  return;
}

