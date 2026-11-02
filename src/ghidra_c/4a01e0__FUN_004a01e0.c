/* FUN_004a01e0 @ 004a01e0 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 * FUN_004a01e0(void)

{
  undefined4 uVar1;
  undefined4 *local_c;
  int local_8;
  
  local_c = (undefined4 *)0x0;
  local_8 = 0;
  do {
    if (DAT_0050a280 <= local_8) {
LAB_004a0286:
      if (local_c != (undefined4 *)0x0) {
        local_c[1] = 0;
        local_c[3] = 0;
        local_c[2] = 0;
        *local_c = 0;
        local_c[7] = 0;
        local_c[4] = 0xffffffff;
      }
      return local_c;
    }
    if (*(int *)(DAT_00509264 + local_8 * 4) == 0) {
      uVar1 = FUN_00494860(0x20,2,0x4bb484,0x55);
      *(undefined4 *)(DAT_00509264 + local_8 * 4) = uVar1;
      if (*(int *)(DAT_00509264 + local_8 * 4) != 0) {
        local_c = *(undefined4 **)(DAT_00509264 + local_8 * 4);
      }
      goto LAB_004a0286;
    }
    if ((*(uint *)(*(int *)(DAT_00509264 + local_8 * 4) + 0xc) & 0x83) == 0) {
      local_c = *(undefined4 **)(DAT_00509264 + local_8 * 4);
      goto LAB_004a0286;
    }
    local_8 = local_8 + 1;
  } while( true );
}

