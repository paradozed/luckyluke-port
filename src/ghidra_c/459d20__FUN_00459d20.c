/* FUN_00459d20 @ 00459d20 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00459d20(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  uint local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = param_1 & 0xffff;
  if (local_8 != 0) {
    if ((local_8 == 0) || (2 < local_8)) {
      FUN_00497610((byte *)"Error: File %s, Line %d");
    }
    else {
      if ((DAT_004f2750 & 0x20) != 0) {
        DAT_004e86a0 = DAT_004e86a0 + 1;
      }
      if ((DAT_004f2750 & 0x80) != 0) {
        DAT_004e86a0 = DAT_004e86a0 - 1;
      }
      if ((DAT_004f2750 & 0x10) != 0) {
        DAT_004e86a0 = DAT_004e86a0 - 0x10;
      }
      if ((DAT_004f2750 & 0x40) != 0) {
        DAT_004e86a0 = DAT_004e86a0 + 0x10;
      }
      if ((DAT_004f2750 & 0x400) != 0) {
        DAT_004bdabc = DAT_004bdabc + 1;
      }
      if ((DAT_004f2750 & 0x100) != 0) {
        DAT_004bdabc = DAT_004bdabc - 1;
      }
      DAT_004e86a0 = DAT_004e86a0 & 0x1f;
      DAT_004bdabc = DAT_004bdabc & 3;
      FUN_00459e90((uint)DAT_004e86a0,DAT_004bdabc);
    }
  }
  local_8 = 0x459e85;
  __chkesp();
  return;
}

