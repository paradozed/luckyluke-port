/* FUN_00430080 @ 00430080 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00430080(void)

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
  if (DAT_004f6124 != (void *)0xdddddddd) {
    FUN_00495280(DAT_004f6124);
  }
  if (DAT_004f6128 != (void *)0xdddddddd) {
    FUN_00495280(DAT_004f6128);
  }
  uStack_8 = 0x4300da;
  __chkesp();
  return;
}

