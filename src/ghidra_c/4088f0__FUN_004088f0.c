/* FUN_004088f0 @ 004088f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004088f0(int param_1,void *param_2)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_70 [16];
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar4 = local_70;
  for (iVar3 = 0x1b; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_28 = FUN_00407580(param_1);
  local_2c = **(int **)(local_28 + 8);
  sVar1 = FUN_004074b0(param_2,2);
  local_30 = **(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  local_24 = *(int *)(local_30 + 0x90);
  local_20 = *(undefined4 *)(local_30 + 0x94);
  local_1c = *(undefined4 *)(local_30 + 0x98);
  local_14 = *(int *)(local_2c + 0x90);
  local_10 = *(undefined4 *)(local_2c + 0x94);
  local_c = *(undefined4 *)(local_2c + 0x98);
  sVar1 = FUN_004074b0(param_2,3);
  uVar2 = (sVar1 * DAT_004e89e4) / (int)(DAT_004be2e5 + 1);
  iVar3 = local_2c;
  sVar1 = FUN_004074b0(param_2,4);
  FUN_00408630(local_14,local_10,local_c,local_8,local_24 + sVar1,iVar3,uVar2);
  local_8 = 0x4089ed;
  __chkesp();
  return;
}

