/* FUN_00403670 @ 00403670 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00403670(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_54 [16];
  undefined4 local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  int local_8;
  
  puVar2 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004d1d64 != 0) {
    FUN_00458ec0();
    if (DAT_004d1cc4 != -1) {
      FUN_00402800(*(void **)(&DAT_004d1ce0 + DAT_004d1ccc * 4),DAT_004d1cc8,DAT_004d1cc4,
                   DAT_004d1cd4);
    }
    FUN_00458ec0();
    for (local_8 = 0; local_8 < DAT_004d1cd0; local_8 = local_8 + 1) {
      local_10 = *(undefined4 **)(&DAT_004d1ce0 + local_8 * 4);
      local_c = local_10;
      if (local_10 == (undefined4 *)0x0) {
        local_14 = 0;
      }
      else {
        (**(code **)*local_10)(1);
        local_14 = __chkesp();
      }
      *(undefined4 *)(&DAT_004d1ce0 + local_8 * 4) = 0;
    }
    FUN_00403c10();
    if (DAT_004d1d68 != (HGLOBAL)0x0) {
      GlobalFree(DAT_004d1d68);
      __chkesp();
      DAT_004d1d68 = (HGLOBAL)0x0;
    }
    DAT_004d1cdc = 0;
    mciSendCommandA(DAT_004d1d60,0x804,0,0);
    __chkesp();
    DAT_004d1d64 = 0;
  }
  local_8 = 0x4037b9;
  __chkesp();
  return;
}

