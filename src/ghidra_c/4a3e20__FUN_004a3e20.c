/* FUN_004a3e20 @ 004a3e20 */
/* decompiled from Lucky.exe (Game.run) */


byte * FUN_004a3e20(void)

{
  byte *pbVar1;
  int iVar2;
  byte *local_8;
  
  if (DAT_0050a2ac == 0) {
    FUN_004a9710();
  }
  local_8 = DAT_0050a2a4;
  pbVar1 = local_8;
  if (*DAT_0050a2a4 == 0x22) {
    while ((local_8 = pbVar1, pbVar1 = local_8 + 1, *pbVar1 != 0x22 && (*pbVar1 != 0))) {
      iVar2 = FUN_004a8e90((uint)*pbVar1);
      if (iVar2 != 0) {
        pbVar1 = local_8 + 2;
      }
    }
    if (*pbVar1 == 0x22) {
      pbVar1 = local_8 + 2;
    }
  }
  else {
    for (; pbVar1 = local_8, 0x20 < *local_8; local_8 = local_8 + 1) {
    }
  }
  while ((local_8 = pbVar1, *local_8 != 0 && (*local_8 < 0x21))) {
    pbVar1 = local_8 + 1;
  }
  return local_8;
}

