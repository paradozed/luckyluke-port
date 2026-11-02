/* FUN_0044aaa0 @ 0044aaa0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044aaa0(void)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  ushort uVar6;
  undefined4 *puVar7;
  undefined4 local_c4 [16];
  int local_84;
  uint local_80;
  uint local_7c;
  undefined4 *local_78;
  SIZE_T local_74;
  int local_70;
  uint local_6c;
  int local_68;
  int local_64;
  uint local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  ushort local_48;
  undefined2 uStack_46;
  ushort local_44;
  undefined2 uStack_42;
  ushort *local_40;
  int local_3c;
  uint local_38;
  int local_34;
  int local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  int local_20;
  int local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  puVar7 = local_c4;
  for (iVar5 = 0x30; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = 0xcccccccc;
    puVar7 = puVar7 + 1;
  }
  FUN_00458ec0();
  local_8 = DAT_004d1e88 * 0xa4;
  DAT_004f2e00 = (void *)FUN_00494c40(local_8,1);
  _memset(DAT_004f2e00,0,local_8);
  FUN_00458ec0();
  for (local_8 = 0; local_8 < DAT_004d1e88; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < DAT_004d1e84; local_c = local_c + 1) {
      if (*(ushort *)(DAT_004d1e78 + local_c * 4) == local_8) {
        local_18 = (uint)*(ushort *)(DAT_004d1e78 + 2 + local_c * 4);
        local_10 = 0;
        while ((local_10 < *(uint *)((int)DAT_004f2e00 + local_8 * 0xa4 + 0xa0) &&
               (local_18 != *(uint *)((int)DAT_004f2e00 + local_10 * 4 + local_8 * 0xa4)))) {
          local_10 = local_10 + 1;
        }
        if (local_10 == 0x28) {
          MessageBoxA((HWND)0x0,"Too many CLUTs, increase table","Error",0);
          __chkesp();
        }
        if (local_10 == *(uint *)((int)DAT_004f2e00 + local_8 * 0xa4 + 0xa0)) {
          *(uint *)((int)DAT_004f2e00 +
                   *(int *)((int)DAT_004f2e00 + local_8 * 0xa4 + 0xa0) * 4 + local_8 * 0xa4) =
               local_18;
          *(int *)((int)DAT_004f2e00 + local_8 * 0xa4 + 0xa0) =
               *(int *)((int)DAT_004f2e00 + local_8 * 0xa4 + 0xa0) + 1;
        }
      }
    }
  }
  FUN_00458ec0();
  for (local_14 = 0; local_14 < DAT_004d1e88; local_14 = local_14 + 1) {
    *(undefined1 *)((int)DAT_004d1e7c + local_14 * 0x14 + 0x12) = 0;
  }
  FUN_00458ec0();
  FUN_0044a5f0();
  FUN_00458ec0();
  for (local_14 = 0; local_14 < DAT_004d1e88; local_14 = local_14 + 1) {
    local_18 = *(uint *)((int)DAT_004f2e00 +
                        (uint)*(byte *)((int)DAT_004d1e7c + local_14 * 0x14 + 0x12) * 4 +
                        local_14 * 0xa4);
    local_30 = (int)*(short *)(DAT_004d1e80 + local_18 * 0x10);
    local_34 = (int)*(short *)(DAT_004d1e80 + 2 + local_18 * 0x10);
    local_38 = *(ushort *)(DAT_004d1e80 + 0xc + local_18 * 0x10) & 0x1f;
    local_3c = *(int *)(DAT_004f58a4 + local_38 * 4) + (local_34 * 0x100 + local_30 * 4) * 2;
    local_1c = *(short *)(DAT_004d1e7c + local_14 * 5) * 4;
    local_20 = (int)*(short *)((int)DAT_004d1e7c + local_14 * 0x14 + 2);
    sVar1 = *(short *)(DAT_004d1e7c + local_14 * 5 + 1);
    local_24 = sVar1 * 4;
    local_28 = (uint)*(short *)((int)DAT_004d1e7c + local_14 * 0x14 + 6);
    local_2c = *(ushort *)((int)DAT_004d1e7c + local_14 * 0x14 + 0xe) & 0x1f;
    local_40 = (ushort *)(*(int *)(DAT_004f58a4 + local_2c * 4) + (local_20 * 0x100 + local_1c) * 2)
    ;
    for (local_c = 0; local_c < local_28; local_c = local_c + 1) {
      for (local_8 = 0; local_8 < local_24; local_8 = local_8 + 1) {
        uVar6 = *local_40;
        _local_44 = CONCAT22(uStack_42,uVar6);
        uVar2 = *(ushort *)(local_3c + (uint)uVar6 * 8) |
                *(short *)(local_3c + 2 + (uint)uVar6 * 8) << 4;
        uVar6 = uVar2 | *(short *)(local_3c + 4 + (uint)uVar6 * 8) << 8 |
                *(short *)(local_3c + 6 + (uint)uVar6 * 8) << 0xc;
        local_4c = CONCAT22(local_4c._2_2_,uVar6) & 0xffff001f;
        uVar4 = (int)(uint)uVar6 >> 5;
        local_50 = CONCAT22(local_50._2_2_,(short)uVar4) & 0xffff001f;
        local_54 = CONCAT22(local_54._2_2_,(short)((int)(uint)uVar6 >> 10)) & 0xffff001f;
        local_58 = CONCAT22(local_58._2_2_,(short)((int)(uint)uVar6 >> 0xf));
        if (*DAT_004f58a8 == 0x536f6674) {
          sVar3 = (short)local_50;
          local_50 = CONCAT22(local_50._2_2_,(short)local_50 << 1);
          uVar6 = (ushort)local_54 | sVar3 << 6 | uVar2 << 0xb;
          *local_40 = uVar6;
        }
        else {
          if ((uVar6 & 0x1f) + (uVar4 & 0x1f) + ((int)(uint)uVar6 >> 10 & 0x1fU) == 0) {
            local_58 = (uint)local_58._2_2_ << 0x10;
          }
          else {
            local_58 = CONCAT22(local_58._2_2_,1);
          }
          uVar6 = (ushort)local_54 | (ushort)((uVar4 & 0x1f) << 5) | (uVar2 & 0x1f) << 10 |
                  (ushort)((local_58 & 0xffff) << 0xf);
          *local_40 = uVar6;
        }
        local_40 = local_40 + 1;
        _local_48 = CONCAT22(uStack_46,uVar6);
        if (DAT_004e8914 == 6) {
          local_6c = local_1c + local_8;
          local_70 = local_20 + local_c;
          local_60 = local_6c & 7;
          local_64 = (int)(local_6c + ((int)local_6c >> 0x1f & 7U)) >> 3;
          local_68 = local_70 * 0x20 + local_64 + local_2c * 0x2000;
          if (local_68 < 0x20000) {
            *(byte *)(DAT_004f2e08 + local_68) =
                 *(byte *)(DAT_004f2e08 + local_68) | (byte)(1 << (sbyte)local_60);
          }
        }
      }
      local_40 = local_40 + sVar1 * -4 + 0x100;
    }
  }
  for (local_14 = 0; local_14 < DAT_004d1e88; local_14 = local_14 + 1) {
    *(undefined1 *)((int)DAT_004d1e7c + local_14 * 0x14 + 0x12) =
         *(undefined1 *)(DAT_004d1e7c + local_14 * 5 + 4);
  }
  if (DAT_004e8914 == 0xf) {
    *(char *)(DAT_004d1e7c + 0x3ec) = *(char *)(DAT_004d1e7c + 0x3ec) + '\x01';
    *(char *)(DAT_004d1e7c + 0x3f1) = *(char *)(DAT_004d1e7c + 0x3f1) + '\x01';
    *(char *)(DAT_004d1e7c + 0x3f6) = *(char *)(DAT_004d1e7c + 0x3f6) + '\x01';
  }
  if (DAT_004e8914 == 0x12) {
    DAT_004d1e88 = DAT_004d1e88 + 1;
    local_74 = DAT_004d1e88 * 0x14;
    local_78 = DAT_004d1e7c;
    DAT_004d1e7c = (undefined4 *)FUN_00439af0(local_74);
    FUN_00497690(DAT_004d1e7c,local_78,local_74 - 0x14);
    *(undefined2 *)((int)DAT_004d1e7c + (DAT_004d1e88 - 1) * 0x14 + 0xe) = 6;
    *(short *)(DAT_004d1e78 + 0x1b0) = (short)DAT_004d1e88 + -1;
  }
  if (DAT_004e8914 == 6) {
    FUN_00458ec0();
    for (local_10 = 0; local_10 < 0x10; local_10 = local_10 + 1) {
      for (local_c = 0; local_c < 0x100; local_c = local_c + 1) {
        for (local_8 = 0; local_8 < 0x100; local_8 = local_8 + 1) {
          local_7c = local_8 & 7;
          local_80 = local_8 >> 3;
          local_84 = local_c * 0x20 + local_80 + local_10 * 0x2000;
          if ((local_84 < 0x20000) &&
             (((uint)*(byte *)(DAT_004f2e08 + local_84) & 1 << (sbyte)local_7c) == 0)) {
            *(undefined2 *)(*(int *)(DAT_004f58a4 + local_10 * 4) + (local_c * 0x100 + local_8) * 2)
                 = 0;
          }
        }
      }
    }
  }
  FUN_00458ec0();
  FUN_00441560();
  if (DAT_004f2e00 != (void *)0xdddddddd) {
    FUN_00495280(DAT_004f2e00);
  }
  local_8 = 0x44b299;
  __chkesp();
  return;
}

