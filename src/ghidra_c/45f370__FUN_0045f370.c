/* FUN_0045f370 @ 0045f370 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045f370(void)

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
  if (_DAT_004bdcf8 != -1) {
    FUN_0041fe60(DAT_004bdcf8);
    _DAT_004bdcf8 = -1;
  }
  if (DAT_004bdcf4 != -1) {
    FUN_00420240((byte)DAT_004bdcf4);
    DAT_004bdcf4 = -1;
  }
  uStack_8 = 0x45f3d8;
  __chkesp();
  return;
}

