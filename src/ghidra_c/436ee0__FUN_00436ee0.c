/* FUN_00436ee0 @ 00436ee0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00436ee0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(short *)(param_1 + 8) =
       (short)(((longlong)(int)*(short *)(param_1 + 8) * (longlong)DAT_004be3c8 & 0xffffffffU) /
              0x280);
  *(short *)(param_1 + 0x10) =
       (short)(((longlong)(int)*(short *)(param_1 + 0x10) * (longlong)DAT_004be3c8 & 0xffffffffU) /
              0x280);
  *(short *)(param_1 + 0x18) =
       (short)(((longlong)(int)*(short *)(param_1 + 0x18) * (longlong)DAT_004be3c8 & 0xffffffffU) /
              0x280);
  *(short *)(param_1 + 0x20) =
       (short)(((longlong)(int)*(short *)(param_1 + 0x20) * (longlong)DAT_004be3c8 & 0xffffffffU) /
              0x280);
  *(short *)(param_1 + 10) =
       (short)(((longlong)(int)*(short *)(param_1 + 10) * (longlong)DAT_004be3cc & 0xffffffffU) /
              0x1e0);
  *(short *)(param_1 + 0x12) =
       (short)(((longlong)(int)*(short *)(param_1 + 0x12) * (longlong)DAT_004be3cc & 0xffffffffU) /
              0x1e0);
  *(short *)(param_1 + 0x1a) =
       (short)(((longlong)(int)*(short *)(param_1 + 0x1a) * (longlong)DAT_004be3cc & 0xffffffffU) /
              0x1e0);
  *(short *)(param_1 + 0x22) =
       (short)(((longlong)(int)*(short *)(param_1 + 0x22) * (longlong)DAT_004be3cc & 0xffffffffU) /
              0x1e0);
  return;
}

