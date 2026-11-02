/* FUN_004021d0 @ 004021d0 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 * __fastcall FUN_004021d0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  int local_c;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = &PTR_FUN_004b33d8;
  param_1[2] = 0xffffffff;
  param_1[1] = &DAT_004b33d4;
  param_1[0xf] = 0;
  for (local_c = 0; local_c < 0x14; local_c = local_c + 1) {
    param_1[local_c + 0x10] = 0;
  }
  return param_1;
}

