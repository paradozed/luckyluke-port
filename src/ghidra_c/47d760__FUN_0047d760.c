/* FUN_0047d760 @ 0047d760 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __cdecl FUN_0047d760(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [17];
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004be3d4 == 1) {
    if ((0xe < param_1) && (param_1 < 0x14)) {
      return 0;
    }
  }
  else if (DAT_004be3d4 == 5) {
    if ((param_1 == 0x5d) || (param_1 == 0x5f)) {
      return 0;
    }
  }
  else if ((DAT_004be3d4 == 0xf) && ((param_1 == 0x20 || (param_1 == 0x21)))) {
    return 0;
  }
  return CONCAT31((int3)((uint)DAT_004be3d4 >> 8),1);
}

