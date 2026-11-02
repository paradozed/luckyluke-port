/* FUN_00448620 @ 00448620 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00448620(int param_1)

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
  iVar1 = *(short *)(param_1 + 0xc) * DAT_004be3c8;
  *(short *)(param_1 + 0xc) = (short)((int)(iVar1 + (iVar1 >> 0x1f & 0x1ffU)) >> 9);
  iVar1 = *(short *)(param_1 + 0x10) * DAT_004be3c8;
  *(short *)(param_1 + 0x10) = (short)((int)(iVar1 + (iVar1 >> 0x1f & 0x1ffU)) >> 9);
  iVar1 = *(short *)(param_1 + 0x14) * DAT_004be3c8;
  *(short *)(param_1 + 0x14) = (short)((int)(iVar1 + (iVar1 >> 0x1f & 0x1ffU)) >> 9);
  iVar1 = *(short *)(param_1 + 10) * DAT_004be3cc;
  *(short *)(param_1 + 10) = (short)(iVar1 + (iVar1 >> 0x1f & 0xffU) >> 8);
  iVar1 = *(short *)(param_1 + 0xe) * DAT_004be3cc;
  *(short *)(param_1 + 0xe) = (short)(iVar1 + (iVar1 >> 0x1f & 0xffU) >> 8);
  iVar1 = *(short *)(param_1 + 0x12) * DAT_004be3cc;
  *(short *)(param_1 + 0x12) = (short)(iVar1 + (iVar1 >> 0x1f & 0xffU) >> 8);
  iVar1 = *(short *)(param_1 + 0x16) * DAT_004be3cc;
  *(short *)(param_1 + 0x16) = (short)(iVar1 + (iVar1 >> 0x1f & 0xffU) >> 8);
  return;
}

