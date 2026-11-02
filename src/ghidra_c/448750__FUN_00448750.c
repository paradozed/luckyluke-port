/* FUN_00448750 @ 00448750 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00448750(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  iVar1 = *(short *)(param_1 + 8) * DAT_004be3c8;
  *(short *)(param_1 + 8) = (short)((int)(iVar1 + (iVar1 >> 0x1f & 0x1ffU)) >> 9);
  iVar1 = *(short *)(param_1 + 0x10) * DAT_004be3c8;
  *(short *)(param_1 + 0x10) = (short)((int)(iVar1 + (iVar1 >> 0x1f & 0x1ffU)) >> 9);
  iVar1 = *(short *)(param_1 + 0x18) * DAT_004be3c8;
  *(short *)(param_1 + 0x18) = (short)((int)(iVar1 + (iVar1 >> 0x1f & 0x1ffU)) >> 9);
  iVar1 = *(short *)(param_1 + 0x20) * DAT_004be3c8;
  *(short *)(param_1 + 0x20) = (short)((int)(iVar1 + (iVar1 >> 0x1f & 0x1ffU)) >> 9);
  iVar1 = *(short *)(param_1 + 10) * DAT_004be3cc;
  *(short *)(param_1 + 10) = (short)(iVar1 + (iVar1 >> 0x1f & 0xffU) >> 8);
  iVar1 = *(short *)(param_1 + 0x12) * DAT_004be3cc;
  *(short *)(param_1 + 0x12) = (short)(iVar1 + (iVar1 >> 0x1f & 0xffU) >> 8);
  iVar1 = *(short *)(param_1 + 0x1a) * DAT_004be3cc;
  *(short *)(param_1 + 0x1a) = (short)(iVar1 + (iVar1 >> 0x1f & 0xffU) >> 8);
  iVar1 = *(short *)(param_1 + 0x22) * DAT_004be3cc;
  *(short *)(param_1 + 0x22) = (short)(iVar1 + (iVar1 >> 0x1f & 0xffU) >> 8);
  return;
}

