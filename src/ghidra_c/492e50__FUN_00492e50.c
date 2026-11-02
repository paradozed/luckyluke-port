/* FUN_00492e50 @ 00492e50 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00492e50(int *param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_7c [16];
  int local_3c;
  undefined2 *local_38;
  undefined2 *local_34;
  int local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  int local_20;
  undefined1 *local_1c;
  undefined1 *local_18;
  int local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  puVar2 = local_7c;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1[3] != param_2) {
    if (*(char *)((int)param_1 + 9) == '\b') {
      local_8 = (uint)(param_1[3] << 0x10) / param_2;
      local_c = (param_1[1] * local_8 >> 0x10) + 1;
      local_18 = (undefined1 *)FUN_00494840(local_c);
      if (local_18 != (undefined1 *)0x0) {
        local_20 = *param_1;
        local_14 = 0;
        local_1c = local_18;
        for (local_10 = 0; local_10 < local_c; local_10 = local_10 + 1) {
          *local_1c = *(undefined1 *)(local_20 + (local_14 + 0x7fffU >> 0x10));
          local_1c = local_1c + 1;
          local_14 = local_14 + local_8;
        }
        FUN_00495280((void *)*param_1);
        *param_1 = (int)local_18;
        param_1[1] = local_c;
        param_1[3] = param_2;
      }
    }
    else if (*(char *)((int)param_1 + 9) == '\x10') {
      local_24 = (uint)(param_1[3] << 0x10) / param_2;
      local_28 = (param_1[1] * local_24 >> 0x10) + 1;
      local_34 = (undefined2 *)FUN_00494840(local_28);
      if (local_34 != (undefined2 *)0x0) {
        local_3c = *param_1;
        local_30 = 0;
        local_38 = local_34;
        for (local_2c = 0; local_2c < local_28; local_2c = local_2c + 1) {
          *local_38 = *(undefined2 *)(local_3c + (local_30 + 0x7fffU >> 0x10) * 2);
          local_38 = local_38 + 1;
          local_30 = local_30 + local_24;
        }
        FUN_00495280((void *)*param_1);
        *param_1 = (int)local_34;
        param_1[1] = local_28;
        param_1[3] = param_2;
      }
    }
  }
  local_8 = 0x49303c;
  __chkesp();
  return;
}

