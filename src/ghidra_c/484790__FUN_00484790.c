/* FUN_00484790 @ 00484790 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00484790(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_6c [16];
  uint local_2c;
  int local_28;
  undefined4 local_24;
  ushort *local_20;
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  uint local_c;
  undefined4 local_8;
  
  iVar1 = 0x1a;
  puVar2 = local_6c;
  while( true ) {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_1c = *param_1;
  if ((char)param_1[1] != '\0') {
    FUN_00484ba0(param_1);
    FUN_00484db0(local_1c);
    *(undefined1 *)(param_1 + 1) = 0;
    param_1[4] = DAT_004e8abc;
  }
  local_20 = (ushort *)param_1[2];
  local_24 = CONCAT22(local_24._2_2_,*(ushort *)((int)param_1 + 0x32));
  if (local_20 != (ushort *)0xdddddddd) {
    if (param_1[3] == 0) {
      FUN_00483e30(param_1);
    }
    else {
      if (*local_20 <= *(ushort *)((int)param_1 + 0x32)) {
        local_24 = (uint)local_24._2_2_ << 0x10;
      }
      if ((uint)local_20[1] < *(uint *)(local_1c + 0x1c)) {
        local_2c = (uint)local_20[1];
      }
      else {
        local_2c = *(uint *)(local_1c + 0x1c);
      }
      local_8 = CONCAT22(local_8._2_2_,(undefined2)local_2c);
      FUN_004840c0((int)param_1,local_24 & 0xffff);
      local_14 = param_1[0x13];
      if (local_14 == param_1[3]) {
        param_1[4] = DAT_004e8abc;
        FUN_00483e30(param_1);
        FUN_00483b60((int)param_1,local_20,(short *)&local_24);
      }
      else {
        local_10 = FUN_00484b40((int)param_1);
        local_c = DAT_004e8abc - param_1[4];
        if (local_10 <= local_c) {
          while ((local_10 <= local_c &&
                 ((*(char *)((int)param_1 + 0x36) != '\0' ||
                  ((*(char *)((int)param_1 + 0x36) == '\0' &&
                   ((local_24 & 0xffff) != (uint)*(ushort *)(param_1 + 0xd)))))))) {
            iVar1 = param_1[0x12];
            param_1[0x12] = param_1[0x13];
            param_1[0x13] = iVar1;
            local_28 = param_1[0x10];
            param_1[0x10] = param_1[0x11];
            param_1[0x11] = local_28;
            param_1[3] = param_1[0x12];
            FUN_00483b60((int)param_1,local_20,(short *)&local_24);
            FUN_004840c0((int)param_1,(uint)*(ushort *)((int)param_1 + 0x32));
            local_14 = param_1[0x13];
            local_c = local_c - local_10;
            param_1[4] = DAT_004e8abc - local_c;
            local_10 = FUN_00484b40((int)param_1);
          }
        }
        if (local_c < local_10) {
          local_c = (local_c << 0x10) / local_10;
          local_18 = *(int *)(local_1c + 0x20);
          if ((char)param_1[9] == '\0') {
            FUN_00484150(param_1,local_18,param_1[0x12] + 4,param_1[0x13] + 4,local_c,
                         CONCAT22((short)((uint)local_18 >> 0x10),(undefined2)local_8),1);
          }
          else {
            FUN_004845e0((int)param_1,local_18,param_1[0x12] + 4,param_1[0x13] + 4,local_c,
                         (undefined2)local_8);
          }
        }
        else {
          param_1[3] = local_14;
          param_1[4] = DAT_004e8abc;
          *(short *)((int)param_1 + 0x32) = (short)param_1[0xd];
          FUN_00483e30(param_1);
        }
      }
    }
  }
  local_8 = 0x484b33;
  __chkesp();
  return;
}

