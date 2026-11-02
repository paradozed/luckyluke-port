/* FUN_00419230 @ 00419230 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00419230(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_54 [16];
  int local_14;
  short *local_10;
  uint local_c;
  undefined4 local_8;
  
  puVar2 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_00417250(param_1,2,0);
  iVar1 = FUN_00407580((int)param_1);
  local_c = (uint)*(ushort *)(*(int *)(iVar1 + 8) + 0x18);
  local_10 = (short *)(DAT_004e8820 + *(int *)(DAT_004e8820 + 4 + local_c * 4));
  local_14 = **(int **)(iVar1 + 8);
  *(short *)(*(int *)(local_14 + 0xc4) + 0x34) = *local_10 + -1;
  local_8 = 0x4192b4;
  __chkesp();
  return;
}

