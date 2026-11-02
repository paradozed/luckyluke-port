/* FUN_00493430 @ 00493430 */
/* decompiled from Lucky.exe (Game.run) */


int * __cdecl FUN_00493430(int param_1,int *param_2)

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
  if (param_2 == (int *)0xffffffff) {
    for (local_8 = 0; local_8 < DAT_00508a10; local_8 = local_8 + 1) {
      if (*(int *)(DAT_004e8c44 + local_8 * 0x14) == 0) {
        *(int *)(DAT_004e8c44 + local_8 * 0x14) = param_1;
        *(undefined1 *)(DAT_004e8c44 + 4 + local_8 * 0x14) = 1;
        *(undefined4 *)(DAT_004e8c44 + 8 + local_8 * 0x14) = 0;
        return (int *)(DAT_004e8c44 + local_8 * 0x14);
      }
    }
  }
  else if (*param_2 == 0) {
    *param_2 = param_1;
    *(undefined1 *)(param_2 + 1) = 1;
    param_2[2] = 0;
    return param_2;
  }
  return (int *)(local_8 * 0x14 + DAT_004e8c44);
}

