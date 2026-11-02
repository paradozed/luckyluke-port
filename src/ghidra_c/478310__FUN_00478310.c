/* FUN_00478310 @ 00478310 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00478310(void)

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
  FUN_0046dd00();
  DAT_004e89da = DAT_004e89da + 1;
  _DAT_004e89dc = _DAT_004e89dc + 1;
  uStack_8 = 0x478359;
  __chkesp();
  return;
}

