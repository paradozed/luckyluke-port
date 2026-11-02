/* FUN_004397c0 @ 004397c0 */
/* decompiled from Lucky.exe (Game.run) */


uint __cdecl FUN_004397c0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_54 [16];
  undefined4 local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  puVar2 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = 0;
  local_14 = param_1;
  for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
    local_8 = local_8 * 0x10 + (uint)*(byte *)((int)&local_14 + local_10);
    local_c = local_8 & 0xf0000000;
    if (local_c != 0) {
      local_8 = local_8 ^ local_c >> 0x18;
    }
    local_8 = local_8 & ~local_c;
  }
  return local_8;
}

