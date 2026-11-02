/* FUN_00407db0 @ 00407db0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00407db0(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_6c [16];
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  puVar3 = local_6c;
  for (iVar2 = 0x1a; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_28 = **(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  sVar1 = FUN_004074b0(param_2,3);
  local_2c = **(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  local_14 = *(int *)(local_28 + 0x90);
  local_10 = *(int *)(local_28 + 0x94);
  local_c = *(int *)(local_28 + 0x98);
  local_24 = *(int *)(local_2c + 0x90);
  local_20 = *(int *)(local_2c + 0x94);
  local_1c = *(int *)(local_2c + 0x98);
  sVar1 = FUN_004074b0(param_2,4);
  FUN_00407cd0(local_14,local_10,local_c,local_8,local_24,local_20,local_1c,sVar1);
  local_8 = 0x407e94;
  __chkesp();
  return;
}

