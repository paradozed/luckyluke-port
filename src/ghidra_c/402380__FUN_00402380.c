/* FUN_00402380 @ 00402380 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall FUN_00402380(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_8c [16];
  undefined4 local_4c;
  undefined4 *local_48;
  undefined4 local_44;
  undefined4 *local_40;
  undefined4 *local_3c;
  undefined4 *local_38;
  undefined4 *local_34;
  undefined4 *local_30;
  undefined4 *local_2c;
  undefined4 *local_28;
  undefined4 *local_24;
  undefined4 *local_20;
  int local_1c;
  undefined4 *local_18;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004b27d6;
  local_10 = ExceptionList;
  puVar2 = local_8c;
  for (iVar1 = 0x1f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  *(undefined4 *)((int)this + 8) = param_1;
  local_14 = this;
  mixerGetDevCapsA(*(UINT_PTR *)((int)this + 8),(LPMIXERCAPSA)((int)this + 0xc),0x30);
  iVar1 = __chkesp();
  if (iVar1 == 0) {
    *(int *)((int)local_14 + 4) = (int)local_14 + 0x14;
    for (local_1c = 0; local_1c < 0xb; local_1c = local_1c + 1) {
      local_24 = (undefined4 *)FUN_00496760(0xc8c);
      local_8 = 0;
      if (local_24 == (undefined4 *)0x0) {
        local_40 = (undefined4 *)0x0;
      }
      else {
        local_40 = FUN_00402930(local_24);
      }
      local_20 = local_40;
      local_8 = 0xffffffff;
      local_18 = local_40;
      iVar1 = FUN_00402a10(local_40,*(undefined4 *)((int)local_14 + 8),local_1c + 0x1000);
      if (iVar1 == 0) {
        local_2c = local_18;
        local_28 = local_18;
        if (local_18 == (undefined4 *)0x0) {
          local_44 = 0;
        }
        else {
          (**(code **)*local_18)(1);
          local_44 = __chkesp();
        }
      }
      else {
        *(undefined4 **)((int)local_14 + *(int *)((int)local_14 + 0x3c) * 4 + 0x40) = local_18;
        *(int *)((int)local_14 + 0x3c) = *(int *)((int)local_14 + 0x3c) + 1;
      }
    }
    for (local_1c = 0; local_1c < 9; local_1c = local_1c + 1) {
      local_34 = (undefined4 *)FUN_00496760(0xc8c);
      local_8 = 1;
      if (local_34 == (undefined4 *)0x0) {
        local_48 = (undefined4 *)0x0;
      }
      else {
        local_48 = FUN_00402930(local_34);
      }
      local_30 = local_48;
      local_8 = 0xffffffff;
      local_18 = local_48;
      iVar1 = FUN_00402a10(local_48,*(undefined4 *)((int)local_14 + 8),local_1c);
      if (iVar1 == 0) {
        local_3c = local_18;
        local_38 = local_18;
        if (local_18 == (undefined4 *)0x0) {
          local_4c = 0;
        }
        else {
          (**(code **)*local_18)(1);
          local_4c = __chkesp();
        }
      }
      else {
        *(undefined4 **)((int)local_14 + *(int *)((int)local_14 + 0x3c) * 4 + 0x40) = local_18;
        *(int *)((int)local_14 + 0x3c) = *(int *)((int)local_14 + 0x3c) + 1;
      }
    }
  }
  ExceptionList = local_10;
  local_8 = 0x4025bf;
  __chkesp();
  return;
}

