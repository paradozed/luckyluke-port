/* FUN_00433970 @ 00433970 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00433970(void)

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
  iVar1 = FUN_00442670('\0');
  if (iVar1 != 0) {
    FUN_004428e0("Language");
    FUN_00442770();
  }
  uStack_8 = 0x4339bd;
  __chkesp();
  return;
}

