/* FUN_00431fe0 @ 00431fe0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00431fe0(char *param_1,uint *param_2)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_a8 [16];
  int local_68;
  undefined4 local_64;
  undefined2 local_60;
  undefined2 uStack_5e;
  undefined2 local_5c;
  undefined2 uStack_5a;
  undefined2 local_58;
  undefined2 uStack_56;
  uint local_54;
  uint local_50;
  uint local_4c;
  int local_48;
  int local_44;
  uint local_40;
  int local_3c;
  uint local_38;
  int local_34;
  void *local_30;
  void *local_2c;
  ushort *local_28;
  ushort *local_24;
  int local_20;
  int local_1c;
  int local_18;
  byte *local_14;
  char *local_10;
  byte local_c;
  undefined3 uStack_b;
  char *local_8;
  
  puVar6 = local_a8;
  for (iVar4 = 0x29; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = 0xcccccccc;
    puVar6 = puVar6 + 1;
  }
  if ((param_1 != (char *)0x0) &&
     (local_8 = (char *)FUN_00435670(param_1,param_2), local_8 != (char *)0x0)) {
    local_14 = (byte *)(local_8 + 0x80);
    local_10 = local_8;
    if (*local_8 == '\n') {
      DAT_004e8488 = ((uint)*(ushort *)(local_8 + 8) - (uint)*(ushort *)(local_8 + 4)) + 1;
      DAT_004e848c = ((uint)*(ushort *)(local_8 + 10) - (uint)*(ushort *)(local_8 + 6)) + 1;
      local_1c = DAT_004e848c;
      local_18 = DAT_004e8488;
      local_24 = (ushort *)FUN_00494c40(DAT_004e8488 * DAT_004e848c * 2,1);
      if (local_24 == (ushort *)0x0) {
        FUN_00495280(local_8);
      }
      else {
        local_28 = local_24;
        if ((uint)(byte)local_10[3] * (uint)(byte)local_10[0x41] == 0x18) {
          local_34 = local_1c;
          local_38 = (uint)(byte)local_10[0x41] * (uint)*(ushort *)(local_10 + 0x42);
          local_30 = (void *)FUN_00494840(local_38);
          for (; local_34 != 0; local_34 = local_34 + -1) {
            local_3c = 0;
            local_2c = local_30;
            while (local_3c < (int)local_38) {
              bVar1 = *local_14;
              _local_c = CONCAT31(uStack_b,bVar1);
              if (bVar1 < 0xc0) {
                local_40 = 1;
                local_14 = local_14 + 1;
              }
              else {
                _local_c = CONCAT31(uStack_b,local_14[1]);
                local_40 = bVar1 & 0x3f;
                local_14 = local_14 + 2;
              }
              while (local_40 != 0) {
                *(byte *)((int)local_30 + local_3c) = local_c;
                local_3c = local_3c + 1;
                local_40 = local_40 - 1;
              }
              local_40 = 0xffffffff;
            }
            for (local_20 = 0;
                (local_20 < (int)(uint)*(ushort *)(local_10 + 0x42) && (local_20 < local_18));
                local_20 = local_20 + 1) {
              local_44 = (int)(uint)*(byte *)((int)local_30 + local_20) >> 3;
              local_48 = (int)(uint)*(byte *)((int)local_30 +
                                             (uint)*(ushort *)(local_10 + 0x42) + local_20) >> 3;
              local_4c = (int)(uint)*(byte *)((int)local_30 +
                                             local_20 + (uint)*(ushort *)(local_10 + 0x42) * 2) >> 3
              ;
              local_50 = (uint)(local_44 + local_48 + local_4c != 0);
              uVar3 = FUN_004318a0(local_44,local_48,local_4c,local_50);
              *local_28 = (ushort)uVar3;
              local_28 = local_28 + 1;
            }
          }
          FUN_00495280(local_30);
        }
        else {
          if ((uint)(byte)local_10[3] * (uint)(byte)local_10[0x41] != 8) {
            FUN_00495280(local_8);
            goto LAB_004324f4;
          }
          for (local_68 = local_1c; local_68 != 0; local_68 = local_68 + -1) {
            local_20 = 0;
            while (local_20 < local_18) {
              bVar1 = *local_14;
              if (bVar1 < 0xc0) {
                *local_28 = (ushort)bVar1;
                local_28 = local_28 + 1;
                local_20 = local_20 + 1;
                local_14 = local_14 + 1;
              }
              else {
                bVar2 = bVar1 + 0x40;
                local_54 = CONCAT31(local_54._1_3_,bVar2);
                bVar1 = local_14[1];
                local_14 = local_14 + 2;
                local_20 = local_20 + (uint)bVar2;
                while( true ) {
                  uVar3 = local_54 & 0xff;
                  local_54 = CONCAT31(local_54._1_3_,(char)local_54 + -1);
                  if (uVar3 == 0) break;
                  *local_28 = (ushort)bVar1;
                  local_28 = local_28 + 1;
                }
              }
              _local_c = CONCAT31(uStack_b,bVar1);
            }
            for (; local_20 < (int)(uint)*(ushort *)(local_10 + 0x42); local_20 = local_20 + 1) {
              local_14 = local_14 + 1;
            }
          }
          local_14 = local_14 + 1;
          for (local_20 = 0; local_20 < 0x100; local_20 = local_20 + 1) {
            iVar4 = (int)(uint)*local_14 >> 3;
            _local_58 = CONCAT22(uStack_56,(short)iVar4);
            iVar5 = (int)(uint)local_14[1] >> 3;
            _local_5c = CONCAT22(uStack_5a,(short)iVar5);
            uVar3 = (int)(uint)local_14[2] >> 3;
            _local_60 = CONCAT22(uStack_5e,(short)uVar3);
            local_14 = local_14 + 3;
            if (iVar4 + iVar5 + uVar3 == 0) {
              local_64 = (uint)local_64._2_2_ << 0x10;
            }
            else {
              local_64 = CONCAT22(local_64._2_2_,1);
            }
            uVar3 = FUN_004318a0(iVar4,iVar5,uVar3,local_64 & 0xffff);
            *(short *)(&DAT_004f5f20 + local_20 * 2) = (short)uVar3;
          }
          local_28 = local_24;
          for (local_68 = local_1c; local_68 != 0; local_68 = local_68 + -1) {
            for (local_20 = 0; local_20 < local_18; local_20 = local_20 + 1) {
              *local_28 = *(ushort *)(&DAT_004f5f20 + (uint)*local_28 * 2);
              local_28 = local_28 + 1;
            }
          }
        }
        FUN_00495280(local_8);
      }
    }
    else {
      FUN_00495280(local_8);
    }
  }
LAB_004324f4:
  local_8 = (char *)0x432504;
  __chkesp();
  return;
}

