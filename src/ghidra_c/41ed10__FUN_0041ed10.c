/* FUN_0041ed10 @ 0041ed10 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041ed10(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [17];
  undefined4 local_c;
  uint local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004bcfd0 != 0) {
    DAT_004d2883 = 0;
    FUN_00458ec0();
    FUN_004943d0();
    local_8 = local_8 & 0xffffff00;
    while ((local_8 & 0xff) < 0x40) {
      *(undefined4 *)(&DAT_004d2390 + (local_8 & 0xff) * 0x10) = 0;
      (&DAT_004d2394)[(local_8 & 0xff) * 0x10] = 0;
      *(undefined2 *)(&DAT_004d2396 + (local_8 & 0xff) * 0x10) = 0;
      *(undefined2 *)(&DAT_004d2398 + (local_8 & 0xff) * 0x10) = 0;
      *(undefined2 *)(&DAT_004d239a + (local_8 & 0xff) * 0x10) = 0x400;
      (&DAT_004d239c)[(local_8 & 0xff) * 0x10] = 0;
      local_8 = CONCAT31(local_8._1_3_,(char)local_8 + '\x01');
    }
    local_c = (uint)local_c._2_2_ << 0x10;
    while ((local_c & 0xffff) < 0x3c) {
      if (*(int *)(&DAT_004d2790 + (local_c & 0xffff) * 4) != 0) {
        FUN_004932b0(*(int **)(&DAT_004d2790 + (local_c & 0xffff) * 4));
        *(undefined4 *)(&DAT_004d2790 + (local_c & 0xffff) * 4) = 0;
      }
      local_c = CONCAT22(local_c._2_2_,(short)local_c + 1);
    }
    DAT_004d2388 = 1;
    DAT_004d238d = 1;
    DAT_004d1eb2 = 0;
    _DAT_004d1eb4 = 0;
    DAT_004d1f1f = 0;
    DAT_004d1f1d = 0;
    FUN_0041fb60(0);
    FUN_00458ec0();
    FUN_00403670();
    DAT_004d2884 = 0;
  }
  local_8 = 0x41eea9;
  __chkesp();
  return;
}

