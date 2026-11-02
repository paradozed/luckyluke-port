/* FUN_00457510 @ 00457510 */
/* decompiled from Lucky.exe (Game.run) */


int __cdecl FUN_00457510(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [18];
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *(int *)(param_1 + 0x2c) +
         ((int)*(short *)(param_1 + 0x22) *
          (((int)*(short *)(param_1 + 0x48) << 0x10) / (int)*(short *)(param_1 + 0x26)) >> 0x10);
}

