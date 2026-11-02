/* FUN_0047d490 @ 0047d490 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0047d490(void)

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
  FUN_00488030();
  (*DAT_004e8a20)();
  __chkesp();
  FUN_0047ba60();
  uStack_8 = 0x47d4ce;
  __chkesp();
  return;
}

