/* FUN_00481360 @ 00481360 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00481360(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_6c [16];
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  short *local_10;
  short *local_c;
  undefined4 local_8;
  
  puVar4 = local_6c;
  for (iVar3 = 0x1a; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_14 = *(int *)(param_1 + 0x90);
  local_18 = *(int *)(param_1 + 0x94);
  local_1c = *(undefined4 *)(param_1 + 0x98);
  if (*(int *)(param_1 + 0xcc) != 0) {
    FUN_00485430(param_1);
  }
  local_c = *(short **)(*(int *)(param_1 + 0x20) + 4);
  local_10 = *(short **)(param_1 + 0xc0);
  sVar1 = *(short *)(param_1 + 0x10);
  if (DAT_004be3d4 == 1) {
    while (sVar1 != 0) {
      iVar3 = ((int)((int)local_c[1] + ((int)local_c[1] >> 0x1f & 0xfU)) >> 4) * 0x170;
      iVar2 = ((int)((int)*local_c + ((int)*local_c >> 0x1f & 0xfU)) >> 4) * DAT_004be3c8;
      iVar3 = ((int)(iVar3 + (iVar3 >> 0x1f & 0x1ffU)) >> 9) * DAT_004be3cc;
      local_28 = (int)(local_14 * DAT_004be3c8 + (local_14 * DAT_004be3c8 >> 0x1f & 0x1ffU)) >> 9;
      local_2c = (int)(local_18 * DAT_004be3cc + (local_18 * DAT_004be3cc >> 0x1f & 0xffU)) >> 8;
      local_20 = ((int)(iVar2 + (iVar2 >> 0x1f & 0x1ffU)) >> 9) + local_28;
      local_24 = ((int)(iVar3 + (iVar3 >> 0x1f & 0xffU)) >> 8) + local_2c;
      *local_10 = (short)local_20;
      local_10[1] = (short)local_24;
      *(undefined4 *)(local_10 + 2) = local_1c;
      local_c = local_c + 4;
      local_10 = local_10 + 4;
      sVar1 = sVar1 + -1;
    }
  }
  else {
    while (sVar1 != 0) {
      *local_10 = (short)((int)((int)*local_c + ((int)*local_c >> 0x1f & 0xfU)) >> 4) +
                  (short)local_14;
      iVar3 = ((int)((int)local_c[1] + ((int)local_c[1] >> 0x1f & 0xfU)) >> 4) * 0x170;
      local_10[1] = (short)((int)(iVar3 + (iVar3 >> 0x1f & 0x1ffU)) >> 9) + (short)local_18;
      *(undefined4 *)(local_10 + 2) = local_1c;
      local_c = local_c + 4;
      local_10 = local_10 + 4;
      sVar1 = sVar1 + -1;
    }
  }
  local_8 = 0x48156b;
  __chkesp();
  return;
}

