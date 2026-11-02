/* FUN_004830a0 @ 004830a0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004830a0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  longlong lVar3;
  undefined4 local_60 [16];
  uint local_20;
  undefined4 uStack_1c;
  uint local_18;
  undefined4 uStack_14;
  float local_10;
  float local_c;
  float local_8;
  
  puVar2 = local_60;
  for (iVar1 = 0x17; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_18 = DAT_004be3c8;
  uStack_14 = 0;
  local_8 = (float)DAT_004be3c8 / _DAT_004b8e0c;
  local_20 = DAT_004be3cc;
  uStack_1c = 0;
  local_c = (float)DAT_004be3cc / _DAT_004b8e08;
  local_10 = (float)param_1 * local_8;
  lVar3 = __ftol();
  DAT_004be3dc = (int)lVar3;
  local_10 = (float)param_1 * local_c;
  lVar3 = __ftol();
  DAT_004be3e0 = (int)lVar3;
  _DAT_00508828 = DAT_004be3dc << 4;
  _DAT_0050882c = (int)lVar3 << 4;
  return;
}

