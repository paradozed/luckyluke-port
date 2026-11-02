/* FUN_0047d7e0 @ 0047d7e0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0047d7e0(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  uint local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  DAT_00508860 = FUN_00439af0(param_1 << 2);
  for (local_8 = 0; local_8 < param_1; local_8 = local_8 + 1) {
    uVar1 = FUN_00439af0(0x28);
    *(undefined4 *)(DAT_00508860 + local_8 * 4) = uVar1;
  }
  DAT_004e8a8c = 0;
  _DAT_004e8a90 = param_1;
  local_8 = 0x47d85d;
  __chkesp();
  return;
}

