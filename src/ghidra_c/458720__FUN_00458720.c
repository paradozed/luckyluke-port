/* FUN_00458720 @ 00458720 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00458720(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_b0 [16];
  int local_70 [4];
  undefined4 local_60;
  int local_58;
  undefined4 local_54;
  int local_40;
  int local_3c;
  int local_38;
  int local_30;
  undefined4 local_2c;
  int local_28;
  int local_20;
  undefined4 local_1c;
  int local_18;
  int local_10;
  int local_c;
  int *local_8;
  
  puVar3 = local_b0;
  for (iVar2 = 0x2b; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = (int *)param_2[1];
  local_c = *param_1;
  local_10 = *local_8;
  FUN_0040da10(param_1,0,&local_58);
  local_20 = *(int *)(local_c + 0x90);
  local_1c = *(undefined4 *)(local_c + 0x94);
  local_18 = *(int *)(local_c + 0x98);
  local_40 = param_1[0x19];
  local_3c = param_1[0x1a];
  local_38 = param_1[0x1b];
  FUN_0040da10(local_8,0,local_70);
  local_30 = *(int *)(local_10 + 0x90);
  local_2c = *(undefined4 *)(local_10 + 0x94);
  local_28 = *(int *)(local_10 + 0x98);
  local_60 = local_54;
  uVar1 = FUN_0040d810(&local_58,local_70);
  if (((short)uVar1 == 0) || ((local_8[4] & 0x20U) == 0)) {
    *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0xff7f;
    *param_2 = FUN_00458890;
    local_8[4] = local_8[4] & 0xffffffd7;
  }
  else {
    local_30 = local_30 + (local_20 - local_40);
    local_2c = local_54;
    local_28 = local_28 + (local_18 - local_38);
    FUN_00457ab0(local_10,local_30,local_54,local_28);
  }
  local_8 = (int *)0x45887e;
  __chkesp();
  return;
}

