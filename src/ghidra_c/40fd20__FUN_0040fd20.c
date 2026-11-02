/* FUN_0040fd20 @ 0040fd20 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040fd20(void)

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
  _DAT_004f58a0 = (uint)DAT_004d238c;
  _DAT_004f58ac = (uint)DAT_004d1f1e;
  FUN_004288b0();
  uStack_8 = 0x40fd68;
  __chkesp();
  return;
}

