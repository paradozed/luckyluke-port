/* FUN_00419c90 @ 00419c90 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00419c90(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  DAT_004c6438._0_2_ = param_1;
  DAT_004c6438._2_2_ = param_2;
  DAT_004c643c._0_2_ = param_3;
  DAT_004c643c._2_2_ = param_4;
  _DAT_004c6440 = param_5;
  return;
}

