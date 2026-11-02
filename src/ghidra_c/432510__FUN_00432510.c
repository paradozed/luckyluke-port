/* FUN_00432510 @ 00432510 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00432510(char *param_1,uint *param_2,int param_3,int param_4,int param_5)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_a4 [16];
  int local_64;
  undefined4 local_60;
  undefined2 local_5c;
  undefined2 uStack_5a;
  undefined2 local_58;
  undefined2 uStack_56;
  undefined2 local_54;
  undefined2 uStack_52;
  uint local_50;
  uint local_4c;
  uint local_48;
  int local_44;
  int local_40;
  uint local_3c;
  int local_38;
  uint local_34;
  int local_30;
  void *local_2c;
  void *local_28;
  ushort *local_24;
  int local_20;
  int local_1c;
  int local_18;
  byte *local_14;
  char *local_10;
  byte local_c;
  undefined3 uStack_b;
  char *local_8;
  
  puVar6 = local_a4;
  for (iVar4 = 0x28; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = 0xcccccccc;
    puVar6 = puVar6 + 1;
  }
  if ((param_1 != (char *)0x0) &&
     (local_8 = (char *)FUN_00435670(param_1,param_2), local_8 != (char *)0x0)) {
    local_14 = (byte *)(local_8 + 0x80);
    local_10 = local_8;
    if (*local_8 == '\n') {
      local_18 = ((uint)*(ushort *)(local_8 + 8) - (uint)*(ushort *)(local_8 + 4)) + 1;
      local_1c = ((uint)*(ushort *)(local_8 + 10) - (uint)*(ushort *)(local_8 + 6)) + 1;
      if ((uint)(byte)local_8[3] * (uint)(byte)local_8[0x41] == 0x18) {
        local_34 = (uint)(byte)local_8[0x41] * (uint)*(ushort *)(local_8 + 0x42);
        local_30 = local_1c;
        local_2c = (void *)FUN_00494840(local_34);
        local_24 = (ushort *)(*(int *)(DAT_004f58a4 + param_3 * 4) + param_5 * 0x200 + param_4 * 2);
        for (; local_30 != 0; local_30 = local_30 + -1) {
          local_38 = 0;
          local_28 = local_2c;
          while (local_38 < (int)local_34) {
            bVar1 = *local_14;
            _local_c = CONCAT31(uStack_b,bVar1);
            if (bVar1 < 0xc0) {
              local_3c = 1;
              local_14 = local_14 + 1;
            }
            else {
              _local_c = CONCAT31(uStack_b,local_14[1]);
              local_3c = bVar1 & 0x3f;
              local_14 = local_14 + 2;
            }
            while (local_3c != 0) {
              *(byte *)((int)local_2c + local_38) = local_c;
              local_38 = local_38 + 1;
              local_3c = local_3c - 1;
            }
            local_3c = 0xffffffff;
          }
          for (local_20 = 0; local_20 < (int)(uint)*(ushort *)(local_10 + 0x42);
              local_20 = local_20 + 1) {
            local_40 = (int)(uint)*(byte *)((int)local_2c + local_20) >> 3;
            local_44 = (int)(uint)*(byte *)((int)local_2c +
                                           (uint)*(ushort *)(local_10 + 0x42) + local_20) >> 3;
            local_48 = (int)(uint)*(byte *)((int)local_2c +
                                           local_20 + (uint)*(ushort *)(local_10 + 0x42) * 2) >> 3;
            local_4c = (uint)(local_40 + local_44 + local_48 != 0);
            uVar2 = FUN_004318a0(local_40,local_44,local_48,local_4c);
            *local_24 = (ushort)uVar2;
            local_24 = local_24 + 1;
          }
          local_24 = local_24 + (0x100 - (uint)*(ushort *)(local_10 + 0x42));
        }
        FUN_00495280(local_2c);
      }
      else {
        if ((uint)(byte)local_8[3] * (uint)(byte)local_8[0x41] != 8) {
          FUN_00495280(local_8);
          goto LAB_00432a51;
        }
        local_24 = (ushort *)(*(int *)(DAT_004f58a4 + param_3 * 4) + param_5 * 0x200 + param_4 * 2);
        for (local_64 = local_1c; local_64 != 0; local_64 = local_64 + -1) {
          local_20 = 0;
          while (local_20 < local_18) {
            bVar1 = *local_14;
            if (bVar1 < 0xc0) {
              *local_24 = (ushort)bVar1;
              local_24 = local_24 + 1;
              local_20 = local_20 + 1;
              local_14 = local_14 + 1;
            }
            else {
              bVar3 = bVar1 + 0x40;
              local_50 = CONCAT31(local_50._1_3_,bVar3);
              bVar1 = local_14[1];
              local_14 = local_14 + 2;
              local_20 = local_20 + (uint)bVar3;
              while( true ) {
                uVar2 = local_50 & 0xff;
                local_50 = CONCAT31(local_50._1_3_,(char)local_50 + -1);
                if (uVar2 == 0) break;
                *local_24 = (ushort)bVar1;
                local_24 = local_24 + 1;
              }
            }
            _local_c = CONCAT31(uStack_b,bVar1);
          }
          local_24 = local_24 + (0x100 - local_18);
        }
        local_14 = local_14 + 1;
        for (local_20 = 0; local_20 < 0x100; local_20 = local_20 + 1) {
          iVar4 = (int)(uint)*local_14 >> 3;
          _local_54 = CONCAT22(uStack_52,(short)iVar4);
          iVar5 = (int)(uint)local_14[1] >> 3;
          _local_58 = CONCAT22(uStack_56,(short)iVar5);
          uVar2 = (int)(uint)local_14[2] >> 3;
          _local_5c = CONCAT22(uStack_5a,(short)uVar2);
          local_14 = local_14 + 3;
          if (iVar4 + iVar5 + uVar2 == 0) {
            local_60 = (uint)local_60._2_2_ << 0x10;
          }
          else {
            local_60 = CONCAT22(local_60._2_2_,1);
          }
          uVar2 = FUN_004318a0(iVar4,iVar5,uVar2,local_60 & 0xffff);
          *(short *)(&DAT_004f5f20 + local_20 * 2) = (short)uVar2;
        }
        local_64 = local_1c;
        local_24 = (ushort *)(*(int *)(DAT_004f58a4 + param_3 * 4) + param_5 * 0x200 + param_4 * 2);
        for (; local_64 != 0; local_64 = local_64 + -1) {
          for (local_20 = 0; local_20 < local_18; local_20 = local_20 + 1) {
            *local_24 = *(ushort *)(&DAT_004f5f20 + (uint)*local_24 * 2);
            local_24 = local_24 + 1;
          }
          local_24 = local_24 + (0x100 - local_18);
        }
      }
      FUN_00495280(local_8);
    }
    else {
      FUN_00495280(local_8);
    }
  }
LAB_00432a51:
  local_8 = (char *)0x432a61;
  __chkesp();
  return;
}

