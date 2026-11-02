/* FUN_004a93e0 @ 004a93e0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004a93e0(void)

{
  BOOL BVar1;
  uint local_520;
  WCHAR local_51c [128];
  WCHAR local_41c [128];
  _cpinfo local_31c;
  CHAR local_308 [256];
  WORD local_208 [256];
  BYTE *local_8;
  
  BVar1 = GetCPInfo(DAT_00508f20,&local_31c);
  if (BVar1 == 1) {
    for (local_520 = 0; local_520 < 0x100; local_520 = local_520 + 1) {
      local_308[local_520] = (CHAR)local_520;
    }
    local_308[0] = ' ';
    for (local_8 = local_31c.LeadByte; *local_8 != 0; local_8 = local_8 + 2) {
      for (local_520 = (uint)*local_8; local_520 <= local_8[1]; local_520 = local_520 + 1) {
        local_308[local_520] = ' ';
      }
    }
    FUN_004a57e0(1,local_308,0x100,local_208,DAT_00508f20,DAT_00509144,0);
    FUN_004a9740(DAT_00509144,0x100,local_308,0x100,local_41c,0x100,DAT_00508f20,0);
    FUN_004a9740(DAT_00509144,0x200,local_308,0x100,local_51c,0x100,DAT_00508f20,0);
    for (local_520 = 0; local_520 < 0x100; local_520 = local_520 + 1) {
      if ((local_208[local_520] & 1) == 0) {
        if ((local_208[local_520] & 2) == 0) {
          (&DAT_00508f40)[local_520] = 0;
        }
        else {
          (&DAT_00509041)[local_520] = (&DAT_00509041)[local_520] | 0x20;
          (&DAT_00508f40)[local_520] = *(undefined1 *)((int)local_51c + local_520);
        }
      }
      else {
        (&DAT_00509041)[local_520] = (&DAT_00509041)[local_520] | 0x10;
        (&DAT_00508f40)[local_520] = *(undefined1 *)((int)local_41c + local_520);
      }
    }
  }
  else {
    for (local_520 = 0; local_520 < 0x100; local_520 = local_520 + 1) {
      if ((local_520 < 0x41) || (0x5a < local_520)) {
        if ((local_520 < 0x61) || (0x7a < local_520)) {
          (&DAT_00508f40)[local_520] = 0;
        }
        else {
          (&DAT_00509041)[local_520] = (&DAT_00509041)[local_520] | 0x20;
          (&DAT_00508f40)[local_520] = (char)local_520 + -0x20;
        }
      }
      else {
        (&DAT_00509041)[local_520] = (&DAT_00509041)[local_520] | 0x10;
        (&DAT_00508f40)[local_520] = (char)local_520 + ' ';
      }
    }
  }
  return;
}

