/* FUN_0047a110 @ 0047a110 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0047a110(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_84 [16];
  int local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  ushort local_14;
  undefined2 uStack_12;
  int local_10;
  int *local_c;
  uint local_8;
  
  puVar2 = local_84;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  _local_14 = CONCAT22(uStack_12,*(ushort *)(DAT_004f1e24 + 1));
  local_18 = local_18 & 0xffff0000;
  local_1c = local_1c & 0xffff0000;
  local_20 = local_20 & 0xffff0000;
  local_24 = local_24 & 0xffff0000;
  local_28 = local_28 & 0xffff0000;
  local_2c = local_2c & 0xffff0000;
  local_30 = local_30 & 0xffff0000;
  local_34 = local_34 & 0xffff0000;
  local_38 = local_38 & 0xffff0000;
  local_3c = local_3c & 0xffff0000;
  local_40 = local_40 & 0xffff0000;
  local_8 = local_8 & 0xffff0000;
  while ((local_8 & 0xffff) < (uint)*(ushort *)(DAT_004f1e24 + 1)) {
    local_c = *(int **)(*DAT_004f1e24 + (local_8 & 0xffff) * 4);
    if ((*(ushort *)((int)local_c + 0xe) & 1) == 0) {
      if (((code *)*local_c == FUN_00473640) || ((code *)*local_c == FUN_00473660)) {
        local_24 = CONCAT22(local_24._2_2_,(short)local_24 + 1);
      }
    }
    else {
      local_10 = *(int *)local_c[2];
      local_28 = CONCAT22(local_28._2_2_,(short)local_28 + 1);
      if (((*(char *)((int)local_c + 0x12) == '\x01') && (*(char *)(local_10 + 1) != '\x05')) &&
         (*(char *)(local_10 + 1) != '\a')) {
        local_18 = CONCAT22(local_18._2_2_,(short)local_18 + 1);
      }
      if (((*(char *)((int)local_c + 0x15) == '\x01') && (*(char *)(local_10 + 1) != '\x05')) &&
         (*(char *)(local_10 + 1) != '\a')) {
        local_1c = CONCAT22(local_1c._2_2_,(short)local_1c + 1);
      }
      if (*(char *)((int)local_c + 0x13) == '\x01') {
        local_20 = CONCAT22(local_20._2_2_,(short)local_20 + 1);
      }
      if (DAT_004e8703 == '\x02') {
        local_44 = *(byte *)(local_10 + 1) - 1;
        switch(local_44) {
        case 0:
        case 7:
          local_2c = CONCAT22(local_2c._2_2_,(short)local_2c + 1);
          break;
        case 1:
          local_30 = CONCAT22(local_30._2_2_,(short)local_30 + 1);
          break;
        case 2:
          local_34 = CONCAT22(local_34._2_2_,(short)local_34 + 1);
          break;
        case 3:
          local_38 = CONCAT22(local_38._2_2_,(short)local_38 + 1);
          break;
        case 4:
          local_3c = CONCAT22(local_3c._2_2_,(short)local_3c + 1);
          break;
        case 6:
          local_40 = CONCAT22(local_40._2_2_,(short)local_40 + 1);
        }
      }
    }
    local_8 = CONCAT22(local_8._2_2_,(short)local_8 + 1);
  }
  FUN_00459540();
  FUN_00459540();
  FUN_00459540();
  if (DAT_004e8703 == '\x02') {
    FUN_00459540();
    FUN_00459540();
    FUN_00459540();
    FUN_00459540();
    FUN_00459540();
    FUN_00459540();
    FUN_00459540();
    FUN_00459540();
  }
  local_8 = 0x47a498;
  __chkesp();
  return;
}

