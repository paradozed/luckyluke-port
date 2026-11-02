/* FUN_004928f0 @ 004928f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004928f0(int *param_1,char param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_7c [16];
  uint local_3c;
  short *local_38;
  undefined2 *local_34;
  undefined2 *local_30;
  uint local_2c;
  undefined2 *local_28;
  undefined2 *local_24;
  uint local_20;
  byte *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  uint local_10;
  undefined1 *local_c;
  undefined1 *local_8;
  
  puVar2 = local_7c;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((char)param_1[2] == param_2) goto LAB_00492c7b;
  if (*(char *)((int)param_1 + 9) == '\b') {
    if (((char)param_1[2] == '\x01') && (param_2 == '\x02')) {
      local_8 = (undefined1 *)FUN_00494840(param_1[1] << 1);
      if (local_8 != (undefined1 *)0x0) {
        local_c = local_8;
        for (local_10 = 0; local_10 < (uint)param_1[1]; local_10 = local_10 + 1) {
          *local_c = *(undefined1 *)(*param_1 + local_10);
          local_c[1] = *(undefined1 *)(*param_1 + local_10);
          local_c = local_c + 2;
        }
        FUN_00495280((void *)*param_1);
        *param_1 = (int)local_8;
        param_1[1] = param_1[1] << 1;
        *(undefined1 *)(param_1 + 2) = 2;
      }
      goto LAB_00492c7b;
    }
    if (((char)param_1[2] == '\x02') && (param_2 == '\x01')) {
      local_14 = (undefined1 *)FUN_00494840((uint)param_1[1] >> 1);
      if (local_14 != (undefined1 *)0x0) {
        local_1c = (byte *)*param_1;
        local_18 = local_14;
        for (local_20 = 0; local_20 < (uint)param_1[1]; local_20 = local_20 + 2) {
          *local_18 = (char)((int)((uint)*local_1c + (uint)local_1c[1]) >> 1);
          local_18 = local_18 + 1;
          local_1c = local_1c + 2;
        }
        FUN_00495280((void *)*param_1);
        *param_1 = (int)local_14;
        param_1[1] = (uint)param_1[1] >> 1;
        *(undefined1 *)(param_1 + 2) = 1;
      }
      goto LAB_00492c7b;
    }
  }
  if (*(char *)((int)param_1 + 9) == '\x10') {
    if (((char)param_1[2] == '\x01') && (param_2 == '\x02')) {
      local_24 = (undefined2 *)FUN_00494840(param_1[1] << 1);
      if (local_24 != (undefined2 *)0x0) {
        local_28 = local_24;
        for (local_2c = 0; local_2c < (uint)param_1[1]; local_2c = local_2c + 2) {
          *local_28 = *(undefined2 *)(*param_1 + local_2c);
          local_28[1] = *(undefined2 *)(*param_1 + local_2c);
          local_28 = local_28 + 2;
        }
        FUN_00495280((void *)*param_1);
        *param_1 = (int)local_24;
        param_1[1] = param_1[1] << 1;
        *(undefined1 *)(param_1 + 2) = 2;
      }
    }
    else if ((((char)param_1[2] == '\x02') && (param_2 == '\x01')) &&
            (local_30 = (undefined2 *)FUN_00494840((uint)param_1[1] >> 1),
            local_30 != (undefined2 *)0x0)) {
      local_38 = (short *)*param_1;
      local_34 = local_30;
      for (local_3c = 0; local_3c < (uint)param_1[1]; local_3c = local_3c + 4) {
        *local_34 = (short)((int)*local_38 + (int)local_38[1] >> 1);
        local_34 = local_34 + 1;
        local_38 = local_38 + 2;
      }
      FUN_00495280((void *)*param_1);
      *param_1 = (int)local_30;
      param_1[1] = (uint)param_1[1] >> 1;
      *(undefined1 *)(param_1 + 2) = 1;
    }
  }
LAB_00492c7b:
  local_8 = (undefined1 *)0x492c88;
  __chkesp();
  return;
}

