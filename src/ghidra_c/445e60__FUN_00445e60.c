/* FUN_00445e60 @ 00445e60 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00445e60(byte *param_1,undefined1 *param_2,byte *param_3)

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
  return;
}

