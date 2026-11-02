/* FUN_00406740 @ 00406740 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00406740(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar3 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if ((DAT_004d1d9c & 1) == 0) {
    DAT_004d1d9c = DAT_004d1d9c | 1;
    uVar4 = FUN_00497360();
    _DAT_004d1d98 = (int)uVar4;
  }
  uVar4 = FUN_00497360();
  if (500 < (int)uVar4 - _DAT_004d1d98) {
    DAT_004f1e21 = 1;
    uVar1 = FUN_004971c0();
    DAT_004e8914 = (short)((int)uVar1 % 0x16) + 1;
    uVar4 = FUN_00497360();
    _DAT_004d1d98 = (int)uVar4;
    DAT_004d1de0 = DAT_004d1de0 + 1;
  }
  uStack_8 = 0x4067d5;
  __chkesp();
  return;
}

