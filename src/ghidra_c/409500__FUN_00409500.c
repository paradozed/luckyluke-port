/* FUN_00409500 @ 00409500 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00409500(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_6c [16];
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_c;
  int local_8;
  
  puVar3 = local_6c;
  for (iVar2 = 0x1a; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = **(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  sVar1 = FUN_004074b0(param_2,3);
  local_c = **(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  local_1c = *(undefined4 *)(local_c + 0x90);
  local_18 = *(undefined4 *)(local_c + 0x94);
  local_14 = *(undefined4 *)(local_c + 0x98);
  local_2c = *(undefined4 *)(local_8 + 0x90);
  local_28 = *(undefined4 *)(local_8 + 0x94);
  local_24 = *(undefined4 *)(local_8 + 0x98);
  FUN_004074b0(param_2,4);
  local_8 = 0x4095c8;
  __chkesp();
  return;
}

