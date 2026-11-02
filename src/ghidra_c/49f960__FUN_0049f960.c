/* FUN_0049f960 @ 0049f960 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0049f960(void)

{
  uint local_8;
  
  if (DAT_0050a280 == 0) {
    DAT_0050a280 = 0x200;
  }
  else if (DAT_0050a280 < 0x14) {
    DAT_0050a280 = 0x14;
  }
  DAT_00509264 = __calloc_dbg(DAT_0050a280,4,2,0x4bb468,0x83);
  if (DAT_00509264 == (undefined1 *)0x0) {
    DAT_0050a280 = 0x14;
    DAT_00509264 = __calloc_dbg(0x14,4,2,0x4bb468,0x86);
    if (DAT_00509264 == (undefined1 *)0x0) {
      __amsg_exit(0x1a);
    }
  }
  for (local_8 = 0; (int)local_8 < 0x14; local_8 = local_8 + 1) {
    *(undefined ***)(DAT_00509264 + local_8 * 4) = &PTR_DAT_004c7260 + local_8 * 8;
  }
  for (local_8 = 0; (int)local_8 < 3; local_8 = local_8 + 1) {
    if ((*(int *)((&DAT_00509160)[(int)local_8 >> 5] + (local_8 & 0x1f) * 8) == -1) ||
       (*(int *)((&DAT_00509160)[(int)local_8 >> 5] + (local_8 & 0x1f) * 8) == 0)) {
      *(undefined4 *)(&DAT_004c7270 + local_8 * 0x20) = 0xffffffff;
    }
  }
  return;
}

