/* FUN_00470e20 @ 00470e20 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00470e20(int param_1,byte *param_2,byte *param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 local_48 [17];
  
  puVar3 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar2 = (uint)*(ushort *)(DAT_004d1e78 + param_1 * 4);
  *param_2 = (byte)((int)*(short *)(DAT_004d1e7c + 4 + uVar2 * 0x14) << 2);
  if (*param_2 == 0) {
    *param_2 = 0xff;
  }
  else if (0xff < (uint)*(byte *)(DAT_004d1e7c + 0x10 + uVar2 * 0x14) + (uint)*param_2) {
    *param_2 = *param_2 - (*param_2 + 1 + *(char *)(DAT_004d1e7c + 0x10 + uVar2 * 0x14));
  }
  *param_3 = *(byte *)(DAT_004d1e7c + 6 + uVar2 * 0x14);
  if (*param_3 == 0) {
    *param_3 = 0xff;
  }
  else if (0xff < (uint)*(byte *)(DAT_004d1e7c + 0x11 + uVar2 * 0x14) + (uint)*param_3) {
    *param_3 = *param_3 - (*param_3 + 1 + *(char *)(DAT_004d1e7c + 0x11 + uVar2 * 0x14));
  }
  return;
}

