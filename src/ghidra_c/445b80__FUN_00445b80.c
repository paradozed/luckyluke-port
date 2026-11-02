/* FUN_00445b80 @ 00445b80 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00445b80(int param_1,short *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(short *)(param_1 + 0x14) = *param_2;
  *(short *)(param_1 + 0x16) = param_2[1];
  *(short *)(param_1 + 0x1c) = *param_2 + param_2[2];
  *(short *)(param_1 + 0x1e) = param_2[1];
  *(short *)(param_1 + 0x24) = *param_2;
  *(short *)(param_1 + 0x26) = param_2[1] + param_2[3];
  *(short *)(param_1 + 0x2c) = *param_2 + param_2[2];
  *(short *)(param_1 + 0x2e) = param_2[1] + param_2[3];
  return;
}

