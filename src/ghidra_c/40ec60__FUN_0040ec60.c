/* FUN_0040ec60 @ 0040ec60 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040ec60(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_6c [16];
  int local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 uStack_8;
  
  puVar3 = local_6c;
  for (iVar2 = 0x1a; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_18 = **(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  local_14 = *(int *)(local_18 + 0x90);
  local_10 = *(undefined4 *)(local_18 + 0x94);
  local_c = *(undefined4 *)(local_18 + 0x98);
  sVar1 = FUN_004074b0(param_2,5);
  if (local_14 < DAT_004bd6a0 + sVar1) {
    sVar1 = FUN_004074b0(param_2,3);
    local_2c = **(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
    local_28 = *(int *)(local_2c + 0x90);
    local_24 = *(undefined4 *)(local_2c + 0x94);
    local_20 = *(undefined4 *)(local_2c + 0x98);
    uVar4 = local_10;
    uVar5 = local_c;
    sVar1 = FUN_004074b0(param_2,4);
    FUN_0040f060(local_18,local_28 + sVar1,uVar4,uVar5);
  }
  uStack_8 = 0x40ed46;
  __chkesp();
  return;
}

