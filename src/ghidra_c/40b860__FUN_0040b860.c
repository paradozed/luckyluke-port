/* FUN_0040b860 @ 0040b860 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040b860(undefined4 param_1,void *param_2)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined2 uVar5;
  undefined4 local_74 [16];
  undefined2 local_34;
  ushort local_32;
  ushort local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_18;
  int local_14;
  int local_10;
  int local_8;
  
  puVar4 = local_74;
  for (iVar3 = 0x1c; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = **(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  local_18 = *(int *)(local_8 + 0x90);
  local_14 = *(int *)(local_8 + 0x94);
  local_10 = *(int *)(local_8 + 0x98);
  sVar1 = FUN_004074b0(param_2,3);
  local_2c = *(int *)(local_8 + 0x20) + sVar1 * 0x28;
  local_28 = (int)**(short **)(local_2c + 0x10);
  local_24 = (int)*(short *)(*(int *)(local_2c + 0x10) + 2);
  local_20 = (int)*(short *)(*(int *)(local_2c + 0x10) + 4);
  local_18 = local_18 + local_28;
  local_14 = local_14 + local_24;
  local_10 = local_10 + local_20;
  local_34 = 0;
  local_32 = FUN_004074b0(param_2,6);
  local_32 = local_32 & 0xfff;
  local_30 = FUN_004074b0(param_2,5);
  local_30 = local_30 & 0xfff;
  uVar5 = 1;
  uVar2 = FUN_004074b0(param_2,7);
  FUN_00476b40(&local_18,(int)&local_34,uVar2,uVar5);
  local_8 = 0x40b972;
  __chkesp();
  return;
}

