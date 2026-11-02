/* FUN_00402930 @ 00402930 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 * __fastcall FUN_00402930(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [17];
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = &PTR_FUN_004b33dc;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = &DAT_004b33d4;
  return param_1;
}

