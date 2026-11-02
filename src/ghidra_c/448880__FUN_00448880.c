/* FUN_00448880 @ 00448880 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00448880(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(short *)(param_1 + 10) = *(short *)(param_1 + 10) + (short)DAT_004e85fc;
  *(short *)(param_1 + 0x12) = *(short *)(param_1 + 0x12) + (short)DAT_004e85fc;
  *(short *)(param_1 + 0x1a) = *(short *)(param_1 + 0x1a) + (short)DAT_004e85fc;
  *(short *)(param_1 + 0x22) = *(short *)(param_1 + 0x22) + (short)DAT_004e85fc;
  return;
}

