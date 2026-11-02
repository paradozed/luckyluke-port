/* FUN_004b1473 @ 004b1473 */
/* decompiled from Lucky.exe (Game.run) */


short __fastcall FUN_004b1473(byte param_1,byte param_2,byte param_3)

{
  undefined2 local_8;
  
  if (DAT_004c7fbc == '\0') {
    local_8 = (param_2 & 0xf8) * 4 + (param_1 & 0xf8) * 0x80 + (ushort)(param_3 >> 3);
  }
  else {
    local_8 = (param_2 & 0xfc) * 8 + (param_1 & 0xf8) * 0x100 + (ushort)(param_3 >> 3);
  }
  return local_8;
}

