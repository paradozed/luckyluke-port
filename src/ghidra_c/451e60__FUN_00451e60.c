/* FUN_00451e60 @ 00451e60 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00451e60(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_60 [16];
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined4 local_8;
  
  puVar2 = local_60;
  for (iVar1 = 0x17; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_00482760((undefined4 *)&DAT_00508180,param_1,&local_18);
  local_18 = local_18 + _DAT_004f2b40;
  local_14 = local_14 + _DAT_004f2b44;
  local_10 = local_10 + 4000 + DAT_004f2b48;
  local_1c = local_18;
  if (local_18 < 0) {
    local_1c = -local_18;
  }
  if ((local_1c < DAT_004bdab0 * local_10 >> 0xc) && (local_20 = local_14, local_14 < 0)) {
    local_20 = -local_14;
  }
  local_8 = 0x451f2d;
  __chkesp();
  return;
}

