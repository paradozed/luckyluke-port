/* FUN_00419a50 @ 00419a50 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_00419a50(undefined4 *param_1,undefined2 param_2,int param_3,undefined2 param_4,ushort param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_60 [16];
  uint local_20;
  int local_1c;
  int local_18;
  short local_14;
  short local_12;
  short local_10;
  int local_c;
  byte *local_8;
  
  puVar2 = local_60;
  for (iVar1 = 0x17; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = *(byte **)param_1[2];
  local_c = **(int **)(param_3 + 8);
  if ((*local_8 & 2) != 0) {
    FUN_00479de0((int)param_1);
  }
  if ((code *)param_1[1] == FUN_0047aae0) {
    (*(code *)*param_1)(param_1);
    __chkesp();
  }
  if (param_5 < 10) {
    local_20 = (uint)param_5;
  }
  else {
    local_20 = param_5 - 10;
  }
  FUN_00419c90(param_4,0xffff,param_2,0xffff,local_20);
  FUN_00486b50((int)local_8,local_c);
  FUN_00419cf0(*(int *)(local_8 + 0xdc),(undefined2 *)(local_8 + 0x5c));
  if (param_5 < 10) {
    if (*(short *)(*(int *)(local_8 + 0xdc) + 10) < 0) {
      local_1c = *(int *)(local_c + 0x20) + *(short *)(*(int *)(local_8 + 0xdc) + 8) * 0x28;
      local_14 = **(short **)(local_1c + 0x10);
      local_12 = *(short *)(*(int *)(local_1c + 0x10) + 2);
      local_10 = *(short *)(*(int *)(local_1c + 0x10) + 4);
    }
    else {
      local_18 = *(int *)(local_c + 0x20) + *(short *)(*(int *)(local_8 + 0xdc) + 8) * 0x28;
      local_14 = *(short *)(*(int *)(local_18 + 8) + *(short *)(*(int *)(local_8 + 0xdc) + 10) * 8);
      local_12 = *(short *)(*(int *)(local_18 + 8) + 2 +
                           *(short *)(*(int *)(local_8 + 0xdc) + 10) * 8);
      local_10 = *(short *)(*(int *)(local_18 + 8) + 4 +
                           *(short *)(*(int *)(local_8 + 0xdc) + 10) * 8);
    }
    FUN_00419e30(*(int *)(local_8 + 0xdc),
                 (*(int *)(local_8 + 0x90) - (int)local_14) - *(int *)(local_c + 0x90),
                 (*(int *)(local_8 + 0x94) - (int)local_12) - *(int *)(local_c + 0x94),
                 (*(int *)(local_8 + 0x98) - (int)local_10) - *(int *)(local_c + 0x98));
  }
  else {
    FUN_00419e30(*(int *)(local_8 + 0xdc),0,0,0);
  }
  local_8 = (byte *)0x419c80;
  __chkesp();
  return;
}

