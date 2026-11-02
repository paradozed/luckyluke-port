/* FUN_0044a240 @ 0044a240 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0044a240(LPCSTR param_1,int param_2,int param_3,int param_4)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_94 [16];
  undefined4 local_54;
  int local_50;
  int local_4c;
  int local_48;
  ushort *local_44;
  int local_40;
  uint local_3c;
  int local_38;
  SIZE_T local_34;
  int local_30;
  int local_2c;
  int local_28;
  PVOID local_24;
  PVOID local_20;
  byte *local_1c;
  char *local_18;
  uint local_14;
  byte local_10;
  undefined3 uStack_f;
  char *local_c;
  uint *local_8;
  
  puVar4 = local_94;
  for (iVar3 = 0x24; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_8 = (uint *)FUN_00497d00(param_1,"rb");
  if (local_8 != (uint *)0x0) {
    FUN_004988b0(local_8,0,2);
    local_14 = FUN_00498dc0(local_8);
    FUN_004988b0(local_8,0,0);
    local_c = (char *)FUN_00494c40(local_14,1);
    if (local_c == (char *)0x0) {
      FUN_00497b30((int *)local_8);
    }
    else {
      uVar2 = FUN_004989e0(local_c,1,local_14,(int *)local_8);
      if (uVar2 == local_14) {
        local_18 = local_c;
        local_1c = (byte *)(local_c + 0x80);
        if (*local_c == '\n') {
          if ((uint)(byte)local_c[3] * (uint)(byte)local_c[0x41] == 0x18) {
            local_28 = ((uint)*(ushort *)(local_c + 8) - (uint)*(ushort *)(local_c + 4)) + 1;
            local_30 = ((uint)*(ushort *)(local_c + 10) - (uint)*(ushort *)(local_c + 6)) + 1;
            local_34 = (uint)(byte)local_c[0x41] * (uint)*(ushort *)(local_c + 0x42);
            local_2c = local_30;
            local_24 = (PVOID)FUN_00439af0(local_34);
            local_44 = (ushort *)
                       (*(int *)(DAT_004f58a4 + param_2 * 4) + param_4 * 0x200 + param_3 * 2);
            for (; local_30 != 0; local_30 = local_30 + -1) {
              local_38 = 0;
              while (local_38 < (int)local_34) {
                bVar1 = *local_1c;
                _local_10 = CONCAT31(uStack_f,bVar1);
                if (bVar1 < 0xc0) {
                  local_3c = 1;
                  local_1c = local_1c + 1;
                }
                else {
                  _local_10 = CONCAT31(uStack_f,local_1c[1]);
                  local_3c = bVar1 & 0x3f;
                  local_1c = local_1c + 2;
                }
                while (local_3c != 0) {
                  *(byte *)((int)local_24 + local_38) = local_10;
                  local_38 = local_38 + 1;
                  local_3c = local_3c - 1;
                }
                local_3c = 0xffffffff;
              }
              for (local_40 = 0; local_40 < (int)(uint)*(ushort *)(local_18 + 0x42);
                  local_40 = local_40 + 1) {
                local_48 = (int)(uint)*(byte *)((int)local_24 + local_40) >> 3;
                local_4c = (int)(uint)*(byte *)((int)local_24 +
                                               (uint)*(ushort *)(local_18 + 0x42) + local_40) >> 3;
                local_50 = (int)(uint)*(byte *)((int)local_24 +
                                               local_40 + (uint)*(ushort *)(local_18 + 0x42) * 2) >>
                           3;
                if (local_48 + local_4c + local_50 == 0) {
                  local_54 = 0;
                }
                else {
                  local_54 = 0x8000;
                }
                *local_44 = (ushort)local_54 | (ushort)(local_48 << 10) | (ushort)(local_4c << 5) |
                            (ushort)local_50;
                local_44 = local_44 + 1;
              }
              local_44 = local_44 + (0x100 - (uint)*(ushort *)(local_18 + 0x42));
              local_20 = local_24;
            }
            if (local_c != (char *)0xdddddddd) {
              FUN_00495280(local_c);
            }
            FUN_00439c30(local_24);
            FUN_00497b30((int *)local_8);
          }
          else {
            if (local_c != (char *)0xdddddddd) {
              FUN_00495280(local_c);
            }
            FUN_00497b30((int *)local_8);
          }
        }
        else {
          if (local_c != (char *)0xdddddddd) {
            FUN_00495280(local_c);
          }
          FUN_00497b30((int *)local_8);
        }
      }
      else {
        if (local_c != (char *)0xdddddddd) {
          FUN_00495280(local_c);
        }
        FUN_00497b30((int *)local_8);
      }
    }
  }
  local_8 = (uint *)0x44a5df;
  __chkesp();
  return;
}

