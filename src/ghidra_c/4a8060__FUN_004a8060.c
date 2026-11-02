/* FUN_004a8060 @ 004a8060 */
/* decompiled from Lucky.exe (Game.run) */


byte * __cdecl FUN_004a8060(byte *param_1,uint param_2)

{
  byte bVar1;
  byte *pbVar2;
  byte *local_8;
  
  local_8 = (byte *)0x0;
  if (DAT_00508f3c == 0) {
    local_8 = (byte *)_strrchr((char *)param_1,param_2);
  }
  else {
    do {
      bVar1 = *param_1;
      if (((&DAT_00509041)[bVar1] & 4) == 0) {
        pbVar2 = param_1;
        if (param_2 == bVar1) {
          local_8 = param_1;
        }
      }
      else {
        pbVar2 = param_1 + 1;
        if (*pbVar2 == 0) {
          if (local_8 == (byte *)0x0) {
            local_8 = pbVar2;
          }
        }
        else if (param_2 == CONCAT11(bVar1,*pbVar2)) {
          local_8 = param_1;
        }
      }
      param_1 = pbVar2;
      bVar1 = *param_1;
      param_1 = param_1 + 1;
    } while (bVar1 != 0);
  }
  return local_8;
}

