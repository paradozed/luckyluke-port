/* FUN_00445ef0 @ 00445ef0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00445ef0(byte *param_1,undefined1 *param_2,byte *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_2 = (char)((int)((uint)*param_1 * (uint)*param_3) >> 7);
  param_2[1] = (char)((int)((uint)param_1[1] * (uint)param_3[1]) >> 7);
  param_2[2] = (char)((int)((uint)param_1[2] * (uint)param_3[2]) >> 7);
  param_2[3] = (char)((int)((uint)param_1[3] * (uint)*param_3) >> 7);
  param_2[4] = (char)((int)((uint)param_1[4] * (uint)param_3[1]) >> 7);
  param_2[5] = (char)((int)((uint)param_1[5] * (uint)param_3[2]) >> 7);
  param_2[6] = (char)((int)((uint)param_1[6] * (uint)*param_3) >> 7);
  param_2[7] = (char)((int)((uint)param_1[7] * (uint)param_3[1]) >> 7);
  param_2[8] = (char)((int)((uint)param_1[8] * (uint)param_3[2]) >> 7);
  param_2[9] = (char)((int)((uint)param_1[9] * (uint)*param_3) >> 7);
  param_2[10] = (char)((int)((uint)param_1[10] * (uint)param_3[1]) >> 7);
  param_2[0xb] = (char)((int)((uint)param_1[0xb] * (uint)param_3[2]) >> 7);
  return;
}

