/* FUN_00445a20 @ 00445a20 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00445a20(int param_1,short *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(short *)(param_1 + 8) = *param_2;
  *(short *)(param_1 + 10) = param_2[1];
  *(short *)(param_1 + 0x10) = *param_2 + param_2[2];
  *(short *)(param_1 + 0x12) = param_2[1];
  *(short *)(param_1 + 0x18) = *param_2;
  *(short *)(param_1 + 0x1a) = param_2[1] + param_2[3];
  *(short *)(param_1 + 0x20) = *param_2 + param_2[2];
  *(short *)(param_1 + 0x22) = param_2[1] + param_2[3];
  return;
}

