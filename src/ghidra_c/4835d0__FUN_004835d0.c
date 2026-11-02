/* FUN_004835d0 @ 004835d0 */
/* decompiled from Lucky.exe (Game.run) */


undefined2 * __cdecl FUN_004835d0(undefined2 *param_1,undefined2 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  int local_c;
  int local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_2 = *param_1;
  param_2[4] = param_1[4];
  param_2[8] = param_1[8];
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < 3; local_c = local_c + 1) {
      param_2[local_c * 3 + local_8] = param_1[local_8 * 3 + local_c];
    }
  }
  *(undefined4 *)(param_2 + 10) = *(undefined4 *)(param_1 + 10);
  *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(param_2 + 0xe) = *(undefined4 *)(param_1 + 0xe);
  return param_2;
}

