/* FUN_0047eae0 @ 0047eae0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047eae0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_5c [16];
  int local_1c;
  int local_18;
  int local_14;
  ushort *local_10;
  uint local_c;
  undefined4 local_8;
  
  puVar2 = local_5c;
  for (iVar1 = 0x16; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (*(int *)(param_1 + 8) == 0) {
    local_1c = param_1 + *(int *)(param_1 + 0x44);
  }
  else {
    local_1c = *(int *)(param_1 + 8) + *(int *)(*(int *)(param_1 + 8) + 0x44);
  }
  local_10 = *(ushort **)(param_1 + 0x30);
  local_14 = local_1c + 0x14;
  local_8 = *(undefined4 *)(param_1 + 0xc0);
  local_c = 0;
  local_18 = *(int *)(param_1 + 0x4c);
  do {
    (**(code **)(&DAT_00507f84 + (uint)*local_10 * 0x34))
              (local_10 + 10,local_14,local_10[1],local_8);
    __chkesp();
    (**(code **)(&DAT_00507f80 + (uint)*local_10 * 0x34))
              (local_10 + 10,local_14,local_10[1],local_18,*(undefined4 *)(param_1 + 0xc0),
               *(undefined4 *)(param_1 + 0x3c));
    __chkesp();
    local_14 = local_14 + *(int *)(local_10 + 4);
    local_c = local_c + local_10[1];
    local_18 = local_18 + *(int *)(local_10 + 6);
    if (local_c < *(uint *)(param_1 + 0x2c)) {
      *(uint *)(local_10 + 8) = (int)local_10 + *(int *)(local_10 + 2) * (uint)local_10[1] + 0x14;
    }
    else {
      local_10[8] = 0;
      local_10[9] = 0;
    }
    local_10 = *(ushort **)(local_10 + 8);
  } while (local_10 != (ushort *)0x0);
  local_8 = 0x47ec4b;
  __chkesp();
  return;
}

