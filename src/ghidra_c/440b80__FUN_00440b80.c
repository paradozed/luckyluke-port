/* FUN_00440b80 @ 00440b80 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00440b80(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  for (local_8 = 0; local_8 < *(int *)(param_1 + 400); local_8 = local_8 + 1) {
    if (DAT_004be3c8 <= *(short *)(param_1 + 8 + local_8 * 0x28)) {
      *(short *)(param_1 + 8 + local_8 * 0x28) = (short)DAT_004be3c8 + -1;
    }
    if (DAT_004be3c8 <= *(short *)(param_1 + 0x10 + local_8 * 0x28)) {
      *(short *)(param_1 + 0x10 + local_8 * 0x28) = (short)DAT_004be3c8 + -1;
    }
    if (DAT_004be3c8 <= *(short *)(param_1 + 0x18 + local_8 * 0x28)) {
      *(short *)(param_1 + 0x18 + local_8 * 0x28) = (short)DAT_004be3c8 + -1;
    }
    if (DAT_004be3c8 <= *(short *)(param_1 + 0x20 + local_8 * 0x28)) {
      *(short *)(param_1 + 0x20 + local_8 * 0x28) = (short)DAT_004be3c8 + -1;
    }
    if (DAT_004be3cc <= *(short *)(param_1 + 10 + local_8 * 0x28)) {
      *(short *)(param_1 + 10 + local_8 * 0x28) = (short)DAT_004be3cc + -1;
    }
    if (DAT_004be3cc <= *(short *)(param_1 + 0x12 + local_8 * 0x28)) {
      *(short *)(param_1 + 0x12 + local_8 * 0x28) = (short)DAT_004be3cc + -1;
    }
    if (DAT_004be3cc <= *(short *)(param_1 + 0x1a + local_8 * 0x28)) {
      *(short *)(param_1 + 0x1a + local_8 * 0x28) = (short)DAT_004be3cc + -1;
    }
    if (DAT_004be3cc <= *(short *)(param_1 + 0x22 + local_8 * 0x28)) {
      *(short *)(param_1 + 0x22 + local_8 * 0x28) = (short)DAT_004be3cc + -1;
    }
  }
  return;
}

