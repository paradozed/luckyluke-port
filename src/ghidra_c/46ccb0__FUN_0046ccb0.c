/* FUN_0046ccb0 @ 0046ccb0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046ccb0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  DAT_004f22aa = 100;
  DAT_004f229c = 100;
  _DAT_004f23a0 = 100;
  DAT_004f23a8 = 0;
  if (DAT_004f2b6c < 120000) {
    DAT_004f22a8 = 1;
  }
  else {
    DAT_004f22a8 = 2;
  }
  DAT_005081a1 = 1;
  DAT_004f5556 = 0;
  DAT_004f23c4 = FUN_0046cd40;
  return;
}

