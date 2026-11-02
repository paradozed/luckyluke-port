/* FUN_0044ee40 @ 0044ee40 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044ee40(void)

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
  FUN_0044f490();
  DAT_004f2c60 = FUN_0044ef30;
  FUN_0044ef30();
  uStack_8 = 0x44ee79;
  __chkesp();
  return;
}

