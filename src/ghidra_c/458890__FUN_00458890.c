/* FUN_00458890 @ 00458890 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00458890(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_b4 [16];
  int local_74 [6];
  int local_5c;
  int local_58;
  int local_4c;
  int local_44;
  int local_40;
  int local_3c;
  undefined4 local_34;
  int local_30;
  undefined4 local_2c;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_14;
  int local_10;
  undefined2 local_c;
  int *local_8;
  
  puVar3 = local_b4;
  for (iVar2 = 0x2c; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = (int *)param_2[1];
  local_c = *(undefined2 *)(param_2 + 2);
  local_10 = *param_1;
  local_14 = *local_8;
  FUN_0040da10(param_1,0,&local_5c);
  local_24 = *(undefined4 *)(local_10 + 0x90);
  local_20 = *(undefined4 *)(local_10 + 0x94);
  local_1c = *(undefined4 *)(local_10 + 0x98);
  FUN_0040da10(local_8,0,local_74);
  local_34 = *(undefined4 *)(local_14 + 0x90);
  local_30 = *(int *)(local_14 + 0x94);
  local_2c = *(undefined4 *)(local_14 + 0x98);
  local_44 = local_8[0x19];
  local_40 = local_8[0x1a];
  local_3c = local_8[0x1b];
  uVar1 = FUN_0040d810(&local_5c,local_74);
  if ((((short)uVar1 != 0) && (local_58 <= local_30)) && (local_40 < local_58)) {
    local_30 = local_4c;
    *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) | 0x80;
    *param_2 = FUN_00458720;
    FUN_00457ab0(local_14,local_34,local_58,local_2c);
    local_8[4] = local_8[4] | 0x28;
  }
  local_8 = (int *)0x4589d8;
  __chkesp();
  return;
}

