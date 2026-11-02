/* FUN_004288b0 @ 004288b0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004288b0(void)

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
  if (100 < _DAT_004f58a0) {
    _DAT_004f58a0 = 100;
  }
  if (100 < _DAT_004f58ac) {
    _DAT_004f58ac = 100;
  }
  iVar1 = FUN_00442670('\0');
  if (iVar1 != 0) {
    FUN_004428e0("CD Volume");
    FUN_004428e0("Audio Volume");
    FUN_00442770();
  }
  uStack_8 = 0x428937;
  __chkesp();
  return;
}

