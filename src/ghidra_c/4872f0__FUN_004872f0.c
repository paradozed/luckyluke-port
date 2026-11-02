/* FUN_004872f0 @ 004872f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004872f0(byte *param_1)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_a8 [16];
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  undefined2 local_54 [16];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_18;
  int local_14;
  int local_10;
  int *local_8;
  
  puVar5 = local_a8;
  for (iVar4 = 0x29; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  local_34 = *(undefined4 *)(param_1 + 0x90);
  local_30 = *(undefined4 *)(param_1 + 0x94);
  local_2c = *(undefined4 *)(param_1 + 0x98);
  local_8 = *(int **)(param_1 + 0xdc);
  local_68 = local_8[4];
  switch(local_68) {
  case 0:
    *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(*local_8 + 0x90);
    *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(*local_8 + 0x94);
    *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(*local_8 + 0x98);
    FUN_00487dc0((undefined2 *)(local_8 + 5),(undefined2 *)(*local_8 + 0x5c));
    break;
  case 1:
    FUN_00487e60((undefined2 *)(param_1 + 0x7c),(undefined2 *)(local_8 + 5));
    break;
  case 2:
    FUN_00482640((undefined4 *)(*local_8 + 0x7c),(int)(local_8 + 5),(undefined4 *)(param_1 + 0x7c));
    break;
  case 3:
    *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(*local_8 + 0x90);
    *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(*local_8 + 0x94);
    *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(*local_8 + 0x98);
    FUN_004869e0(*local_8,(int)(local_8 + 2),(undefined2 *)(param_1 + 0x5c));
    FUN_00487dc0((undefined2 *)(local_8 + 5),(undefined2 *)(param_1 + 0x5c));
    break;
  case 4:
    *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(*local_8 + 0x90);
    *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(*local_8 + 0x94);
    *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(*local_8 + 0x98);
    FUN_00487dc0((undefined2 *)(local_8 + 5),(undefined2 *)(*local_8 + 0x5c));
    FUN_00482930(local_8 + 5,(int)(param_1 + 0x5c));
    FUN_0047c7f0(local_54,0,0xc00,0);
    FUN_00482930(local_8 + 5,(int)local_54);
  }
  if (*(short *)((int)local_8 + 10) < 0) {
    if (*local_8 == -0x22222223) goto LAB_00487732;
    local_5c = *(int *)(*local_8 + 0x20) + (short)local_8[2] * 0x28;
    sVar1 = **(short **)(local_5c + 0x10);
    sVar2 = *(short *)(*(int *)(local_5c + 0x10) + 2);
    sVar3 = *(short *)(*(int *)(local_5c + 0x10) + 4);
  }
  else {
    local_58 = *(int *)(*local_8 + 0x20) + (short)local_8[2] * 0x28;
    sVar1 = *(short *)(*(int *)(local_58 + 8) + *(short *)((int)local_8 + 10) * 8);
    sVar2 = *(short *)(*(int *)(local_58 + 8) + 2 + *(short *)((int)local_8 + 10) * 8);
    sVar3 = *(short *)(*(int *)(local_58 + 8) + 4 + *(short *)((int)local_8 + 10) * 8);
  }
  local_10 = (int)sVar3;
  local_14 = (int)sVar2;
  local_18 = (int)sVar1;
  *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + local_18;
  *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + local_14;
  *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + local_10;
  FUN_00487230(param_1);
  if (0 < (short)local_8[3]) {
    if (*(short *)((int)local_8 + 0xe) < 0) {
      local_64 = *(int *)(param_1 + 0x20) + (short)local_8[3] * 0x28;
      sVar1 = **(short **)(local_64 + 0x10);
      sVar2 = *(short *)(*(int *)(local_64 + 0x10) + 2);
      sVar3 = *(short *)(*(int *)(local_64 + 0x10) + 4);
    }
    else {
      local_60 = *(int *)(param_1 + 0x20) + (short)local_8[3] * 0x28;
      sVar1 = *(short *)(*(int *)(local_60 + 8) + *(short *)((int)local_8 + 0xe) * 8);
      sVar2 = *(short *)(*(int *)(local_60 + 8) + 2 + *(short *)((int)local_8 + 0xe) * 8);
      sVar3 = *(short *)(*(int *)(local_60 + 8) + 4 + *(short *)((int)local_8 + 0xe) * 8);
    }
    local_20 = (int)sVar3;
    local_24 = (int)sVar2;
    local_28 = (int)sVar1;
    *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) - local_28;
    *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) - local_24;
    *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) - local_20;
  }
  if (*(int *)(param_1 + 0xc4) != 0) {
    *(short *)(*(int *)(param_1 + 0xc4) + 0x2a) =
         (short)*(undefined4 *)(param_1 + 0x90) - (short)local_34;
    *(short *)(*(int *)(param_1 + 0xc4) + 0x2c) =
         (short)*(undefined4 *)(param_1 + 0x94) - (short)local_30;
    *(short *)(*(int *)(param_1 + 0xc4) + 0x2e) =
         (short)*(undefined4 *)(param_1 + 0x98) - (short)local_2c;
  }
LAB_00487732:
  local_8 = (int *)0x487742;
  __chkesp();
  return;
}

