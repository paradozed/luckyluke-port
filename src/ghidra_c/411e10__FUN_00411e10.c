/* FUN_00411e10 @ 00411e10 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00411e10(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_5c [16];
  short local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_8;
  
  puVar3 = local_5c;
  for (iVar2 = 0x16; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = **(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  local_1c = FUN_00411f20(local_8);
  local_18 = *(int *)(local_8 + 0x90);
  local_14 = *(undefined4 *)(local_8 + 0x94);
  local_10 = *(undefined4 *)(local_8 + 0x98);
  sVar1 = FUN_004074b0(param_2,3);
  local_18 = local_18 - sVar1;
  sVar1 = FUN_004074b0(param_2,6);
  iVar2 = sVar1 * 100;
  sVar1 = FUN_004074b0(param_2,5);
  FUN_00411c90(local_8,local_18,sVar1 * 100,iVar2);
  if (local_1c < 0) {
    sVar1 = FUN_004074b0(param_2,4);
    local_18 = local_18 + sVar1;
    sVar1 = FUN_004074b0(param_2,6);
    iVar2 = sVar1 * 100;
    sVar1 = FUN_004074b0(param_2,5);
    FUN_00411c90(local_8,local_18,sVar1 * 100,iVar2);
  }
  local_8 = 0x411f1b;
  __chkesp();
  return;
}

