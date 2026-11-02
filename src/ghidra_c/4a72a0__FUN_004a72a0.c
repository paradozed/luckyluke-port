/* FUN_004a72a0 @ 004a72a0 */
/* decompiled from Lucky.exe (Game.run) */


int FUN_004a72a0(void)

{
  int iVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  for (local_c = 3; local_c < DAT_0050a280; local_c = local_c + 1) {
    if (*(int *)(DAT_00509264 + local_c * 4) != 0) {
      if ((*(uint *)(*(int *)(DAT_00509264 + local_c * 4) + 0xc) & 0x83) != 0) {
        iVar1 = FUN_00497b30(*(int **)(DAT_00509264 + local_c * 4));
        if (iVar1 != -1) {
          local_8 = local_8 + 1;
        }
      }
      if (0x13 < local_c) {
        FUN_004952a0(*(void **)(DAT_00509264 + local_c * 4),2);
        *(undefined4 *)(DAT_00509264 + local_c * 4) = 0;
      }
    }
  }
  return local_8;
}

