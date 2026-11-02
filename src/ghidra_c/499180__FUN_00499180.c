/* FUN_00499180 @ 00499180 */
/* decompiled from Lucky.exe (Game.run) */


int __cdecl FUN_00499180(int param_1)

{
  int iVar1;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0;
  for (local_10 = 0; local_10 < DAT_0050a280; local_10 = local_10 + 1) {
    if ((*(int *)(DAT_00509264 + local_10 * 4) != 0) &&
       ((*(uint *)(*(int *)(DAT_00509264 + local_10 * 4) + 0xc) & 0x83) != 0)) {
      if (param_1 == 1) {
        iVar1 = FUN_00499050(*(int **)(DAT_00509264 + local_10 * 4));
        if (iVar1 != -1) {
          local_8 = local_8 + 1;
        }
      }
      else if (((param_1 == 0) &&
               ((*(uint *)(*(int *)(DAT_00509264 + local_10 * 4) + 0xc) & 2) != 0)) &&
              (iVar1 = FUN_00499050(*(int **)(DAT_00509264 + local_10 * 4)), iVar1 == -1)) {
        local_c = -1;
      }
    }
  }
  if (param_1 == 1) {
    local_c = local_8;
  }
  return local_c;
}

