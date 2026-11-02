/* FUN_00448a00 @ 00448a00 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00448a00(int param_1)

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
  return;
}

