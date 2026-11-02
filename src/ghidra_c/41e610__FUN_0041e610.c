/* FUN_0041e610 @ 0041e610 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041e610(void)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_50 [17];
  uint local_c;
  undefined4 local_8;
  
  puVar3 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if ((DAT_004d2883 == '\0') && (DAT_004bcfd0 != 0)) {
    FUN_00458ec0();
    FUN_00458ec0();
    FUN_00493510(1,'\x02');
    FUN_00458ec0();
    cVar1 = FUN_00494450(2,16000,0x10,100000,0x40);
    if (cVar1 == '\0') {
      DAT_004bcfd0 = 0;
    }
    else {
      FUN_004935a0(0,0x3fff);
      local_8 = (uint)local_8._2_2_ << 0x10;
      while ((local_8 & 0xffff) < 0x3c) {
        *(undefined4 *)(&DAT_004d2790 + (local_8 & 0xffff) * 4) = 0;
        local_8 = CONCAT22(local_8._2_2_,(short)local_8 + 1);
      }
      FUN_00458ec0();
      local_c = local_c & 0xffffff00;
      while ((local_c & 0xff) < 0x40) {
        iVar2 = FUN_00493370(local_c & 0xff);
        *(int *)(&DAT_004d2390 + (local_c & 0xff) * 0x10) = iVar2;
        (&DAT_004d2394)[(local_c & 0xff) * 0x10] = 0;
        *(undefined2 *)(&DAT_004d2396 + (local_c & 0xff) * 0x10) = 0;
        *(undefined2 *)(&DAT_004d2398 + (local_c & 0xff) * 0x10) = 0;
        *(undefined2 *)(&DAT_004d239a + (local_c & 0xff) * 0x10) = 0x400;
        (&DAT_004d239c)[(local_c & 0xff) * 0x10] = 0;
        local_c = CONCAT31(local_c._1_3_,(char)local_c + '\x01');
      }
      DAT_004d2388 = 1;
      DAT_004d238d = 1;
      DAT_004d1eb2 = 0;
      _DAT_004d1eb4 = 0;
      DAT_004d1f1f = 0;
      DAT_004d1f1d = 0;
      FUN_0041fb60(0);
      FUN_0041feb0();
      DAT_004d2883 = '\x01';
    }
  }
  local_8 = 0x41e7fa;
  __chkesp();
  return;
}

