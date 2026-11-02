/* FUN_0041eeb0 @ 0041eeb0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041eeb0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [17];
  uint local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004bcfd0 != 0) {
    FUN_00458ec0();
    FUN_00458ec0();
    local_8 = local_8 & 0xffffff00;
    while ((local_8 & 0xff) < 0x18) {
      FUN_00493f10(*(undefined4 **)(&DAT_004d2390 + (local_8 & 0xff) * 0x10));
      (&DAT_004d2394)[(local_8 & 0xff) * 0x10] = 0;
      *(undefined2 *)(&DAT_004d2396 + (local_8 & 0xff) * 0x10) = 0;
      *(undefined2 *)(&DAT_004d2398 + (local_8 & 0xff) * 0x10) = 0;
      *(undefined2 *)(&DAT_004d239a + (local_8 & 0xff) * 0x10) = 0x400;
      (&DAT_004d239c)[(local_8 & 0xff) * 0x10] = 0;
      local_8 = CONCAT31(local_8._1_3_,(char)local_8 + '\x01');
    }
    DAT_004d2388 = 1;
    DAT_004d238d = 1;
    DAT_004d1eb2 = 0;
    _DAT_004d1eb4 = 0;
    DAT_004d1f1f = 0;
    DAT_004d1f1d = 0;
    FUN_0041fb60(0);
    FUN_00458ec0();
    FUN_00403c10();
  }
  local_8 = 0x41efea;
  __chkesp();
  return;
}

