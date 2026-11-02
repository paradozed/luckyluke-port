/* FUN_00484ba0 @ 00484ba0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00484ba0(int *param_1)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_50 [16];
  undefined2 *local_10;
  int local_c;
  uint local_8;
  
  puVar3 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  puVar1 = (undefined2 *)param_1[0x12];
  if (puVar1 == (undefined2 *)0xdddddddd) {
    local_10 = (undefined2 *)0xdddddddd;
  }
  else {
    *puVar1 = *(undefined2 *)param_1[3];
    param_1[3] = param_1[0x12];
    param_1[0x10] = 0;
    local_c = *(int *)(*param_1 + 0x20);
    local_10 = puVar1 + 2;
    local_8 = 0;
    while( true ) {
      if (*(uint *)(*param_1 + 0x1c) <= local_8) break;
      local_10[local_8 * 10] = (ushort)*(byte *)(local_c + 0x14 + local_8 * 0x28);
      puVar1[local_8 * 10 + 3] = *(undefined2 *)(local_c + 0x16 + local_8 * 0x28);
      puVar1[local_8 * 10 + 4] = *(undefined2 *)(local_c + 0x18 + local_8 * 0x28);
      puVar1[local_8 * 10 + 5] = *(undefined2 *)(local_c + 0x1a + local_8 * 0x28);
      puVar1[local_8 * 10 + 6] = *(undefined2 *)(local_c + 0x1c + local_8 * 0x28);
      puVar1[local_8 * 10 + 7] = *(undefined2 *)(local_c + 0x1e + local_8 * 0x28);
      puVar1[local_8 * 10 + 8] = *(undefined2 *)(local_c + 0x20 + local_8 * 0x28);
      puVar1[local_8 * 10 + 9] = *(undefined2 *)(local_c + 0x22 + local_8 * 0x28);
      puVar1[local_8 * 10 + 10] = *(undefined2 *)(local_c + 0x24 + local_8 * 0x28);
      puVar1[local_8 * 10 + 0xb] = *(undefined2 *)(local_c + 0x26 + local_8 * 0x28);
      local_8 = local_8 + 1;
    }
    FUN_00483db0(*param_1,local_8,(int)param_1);
    local_10[1] = 0;
    local_10[2] = 0;
    local_10[3] = 0;
    local_10[0xe] = (short)param_1[5];
    local_10[0xf] = (short)param_1[6];
    local_10[0x10] = (short)param_1[7];
  }
  local_8 = 0x484da6;
  __chkesp();
  return;
}

