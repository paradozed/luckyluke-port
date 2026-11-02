/* FUN_004a76d0 @ 004a76d0 */
/* decompiled from Lucky.exe (Game.run) */


int FUN_004a76d0(void)

{
  int local_10;
  int local_c;
  undefined4 *local_8;
  
  local_c = -1;
  local_10 = 0;
  do {
    if (0x3f < local_10) {
      return local_c;
    }
    if ((&DAT_00509160)[local_10] == 0) {
      local_8 = (undefined4 *)FUN_00494860(0x100,2,0x4bb880,0x79);
      if (local_8 == (undefined4 *)0x0) {
        return local_c;
      }
      (&DAT_00509160)[local_10] = local_8;
      DAT_00509260 = DAT_00509260 + 0x20;
      for (; local_8 < (undefined4 *)((&DAT_00509160)[local_10] + 0x100); local_8 = local_8 + 2) {
        *(undefined1 *)(local_8 + 1) = 0;
        *local_8 = 0xffffffff;
        *(undefined1 *)((int)local_8 + 5) = 10;
      }
      return local_10 << 5;
    }
    for (local_8 = (undefined4 *)(&DAT_00509160)[local_10];
        local_8 < (undefined4 *)((&DAT_00509160)[local_10] + 0x100); local_8 = local_8 + 2) {
      if ((*(byte *)(local_8 + 1) & 1) == 0) {
        *local_8 = 0xffffffff;
        local_c = local_10 * 0x20 + ((int)local_8 - (&DAT_00509160)[local_10] >> 3);
        break;
      }
    }
    if (local_c != -1) {
      return local_c;
    }
    local_10 = local_10 + 1;
  } while( true );
}

