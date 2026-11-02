/* FUN_00481af0 @ 00481af0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00481af0(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_6c [16];
  int local_2c;
  int local_28;
  int local_24;
  uint local_20;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined2 local_18;
  int local_14;
  undefined1 local_10 [8];
  undefined4 local_8;
  
  puVar3 = local_6c;
  for (iVar2 = 0x1a; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = (undefined2)(local_8 >> 0x10);
  local_8 = local_8 & 0xffff0000;
  local_14 = *(int *)(param_1 + 0xc4);
  if (local_14 == 0) {
    if (*(int *)(param_1 + 0xe0) != 0) {
      local_1c = 0;
      local_1a = 0;
      local_18 = 0;
      (**(code **)(param_1 + 0xe0))(param_1,&local_1c,local_10,*(undefined4 *)(param_1 + 0xe4));
      __chkesp();
    }
  }
  else {
    local_20 = (uint)*(ushort *)(local_14 + 0x28);
    if (local_20 == 0) {
      local_8 = CONCAT22(uVar1,*(short *)(*(int *)(param_1 + 0x20) + 0x44) -
                               (short)*(undefined4 *)(*(int *)(param_1 + 0xc4) + 0x14));
    }
    else if (local_20 == 1) {
      local_8 = CONCAT22(uVar1,*(short *)(*(int *)(param_1 + 0x20) + 0x46) -
                               (short)*(undefined4 *)(*(int *)(param_1 + 0xc4) + 0x18));
    }
    else if (local_20 == 2) {
      local_8 = CONCAT22(uVar1,*(short *)(*(int *)(param_1 + 0x20) + 0x48) -
                               (short)*(undefined4 *)(*(int *)(param_1 + 0xc4) + 0x1c));
    }
    if (*(int *)(param_1 + 0xe0) != 0) {
      if (*(short *)(local_14 + 0x28) == 0) {
        local_24 = (int)(short)local_8;
      }
      else {
        local_24 = 0;
      }
      local_1c = (undefined2)local_24;
      if (*(short *)(local_14 + 0x28) == 1) {
        local_28 = (int)(short)local_8;
      }
      else {
        local_28 = 0;
      }
      local_1a = (undefined2)local_28;
      if (*(short *)(local_14 + 0x28) == 2) {
        local_2c = (int)(short)local_8;
      }
      else {
        local_2c = 0;
      }
      local_18 = (undefined2)local_2c;
      (**(code **)(param_1 + 0xe0))(param_1,&local_1c,local_10,*(undefined4 *)(param_1 + 0xe4));
      __chkesp();
    }
    FUN_00480d10(param_1);
  }
  local_8 = 0x481ca6;
  __chkesp();
  return;
}

