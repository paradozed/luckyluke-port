/* FUN_004a8f80 @ 004a8f80 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __cdecl FUN_004a8f80(UINT param_1)

{
  UINT CodePage;
  undefined4 uVar1;
  BOOL BVar2;
  BYTE *local_2c;
  uint local_28;
  _cpinfo local_24;
  uint local_10;
  byte *local_c;
  uint local_8;
  
  CodePage = getSystemCP(param_1);
  if (CodePage == DAT_00508f20) {
    uVar1 = 0;
  }
  else if (CodePage == 0) {
    setSBCS();
    FUN_004a93e0();
    uVar1 = 0;
  }
  else {
    for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
      if (*(UINT *)(&DAT_004c79f8 + local_8 * 0x30) == CodePage) {
        for (local_28 = 0; local_28 < 0x101; local_28 = local_28 + 1) {
          (&DAT_00509040)[local_28] = 0;
        }
        for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
          for (local_c = &DAT_004c7a08 + local_10 * 8 + local_8 * 0x30;
              (*local_c != 0 && (local_c[1] != 0)); local_c = local_c + 2) {
            for (local_28 = (uint)*local_c; local_28 <= local_c[1]; local_28 = local_28 + 1) {
              (&DAT_00509041)[local_28] = (&DAT_00509041)[local_28] | (&DAT_004c79f0)[local_10];
            }
          }
        }
        DAT_00508f3c = 1;
        DAT_00508f20 = CodePage;
        DAT_00509144 = FUN_004a92e0(CodePage);
        for (local_10 = 0; local_10 < 6; local_10 = local_10 + 1) {
          *(undefined2 *)(&DAT_00508f30 + local_10 * 2) =
               *(undefined2 *)(&DAT_004c79fc + local_10 * 2 + local_8 * 0x30);
        }
        FUN_004a93e0();
        return 0;
      }
    }
    BVar2 = GetCPInfo(CodePage,&local_24);
    if (BVar2 == 1) {
      for (local_28 = 0; local_28 < 0x101; local_28 = local_28 + 1) {
        (&DAT_00509040)[local_28] = 0;
      }
      DAT_00509144 = 0;
      if (local_24.MaxCharSize < 2) {
        DAT_00508f3c = 0;
        DAT_00508f20 = CodePage;
      }
      else {
        DAT_00508f20 = CodePage;
        for (local_2c = local_24.LeadByte; (*local_2c != 0 && (local_2c[1] != 0));
            local_2c = local_2c + 2) {
          for (local_28 = (uint)*local_2c; local_28 <= local_2c[1]; local_28 = local_28 + 1) {
            (&DAT_00509041)[local_28] = (&DAT_00509041)[local_28] | 4;
          }
        }
        for (local_28 = 1; local_28 < 0xff; local_28 = local_28 + 1) {
          (&DAT_00509041)[local_28] = (&DAT_00509041)[local_28] | 8;
        }
        DAT_00509144 = FUN_004a92e0(DAT_00508f20);
        DAT_00508f3c = 1;
      }
      for (local_10 = 0; local_10 < 6; local_10 = local_10 + 1) {
        *(undefined2 *)(&DAT_00508f30 + local_10 * 2) = 0;
      }
      FUN_004a93e0();
      uVar1 = 0;
    }
    else if (DAT_004e8e8c == 0) {
      uVar1 = 0xffffffff;
    }
    else {
      setSBCS();
      FUN_004a93e0();
      uVar1 = 0;
    }
  }
  return uVar1;
}

