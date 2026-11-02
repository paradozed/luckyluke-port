/* FUN_00431910 @ 00431910 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00431910(LPCSTR param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_124 [16];
  int local_e4;
  undefined4 local_e0;
  undefined2 local_dc;
  undefined2 uStack_da;
  uint local_d8;
  uint local_d4;
  uint local_d0;
  uint local_cc;
  uint local_c8;
  int local_c4;
  int local_c0;
  uint local_bc;
  int local_b8;
  uint local_b4;
  int local_b0;
  void *local_ac;
  void *local_a8;
  uint *local_a4;
  ushort *local_a0;
  ushort *local_9c;
  int local_98;
  int local_94;
  int local_90;
  undefined4 local_8c;
  undefined2 local_88;
  undefined1 uStack_86;
  undefined1 uStack_85;
  ushort local_84;
  ushort uStack_82;
  uint local_4b;
  byte local_c;
  undefined3 uStack_b;
  undefined4 uStack_8;
  
  puVar5 = local_124;
  for (iVar4 = 0x48; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  local_a4 = (uint *)FUN_00497d00(param_1,"rb");
  if (local_a4 != (uint *)0x0) {
    FUN_004989e0((char *)&local_8c,1,0x80,(int *)local_a4);
    if ((local_8c & 0xff) == 10) {
      DAT_004e8488 = ((uint)local_84 - (CONCAT12(uStack_86,local_88) & 0xffff)) + 1;
      DAT_004e848c = ((uint)uStack_82 - (uint)CONCAT11(uStack_85,uStack_86)) + 1;
      local_94 = DAT_004e848c;
      local_90 = DAT_004e8488;
      local_9c = (ushort *)FUN_00494c40(DAT_004e8488 * DAT_004e848c * 2,1);
      if (local_9c == (ushort *)0x0) {
        FUN_00497b30((int *)local_a4);
      }
      else {
        local_a0 = local_9c;
        if ((uint)local_8c._3_1_ * (local_4b & 0xff) == 0x18) {
          local_b0 = local_94;
          local_b4 = (local_4b & 0xff) * (local_4b >> 8 & 0xffff);
          local_ac = (void *)FUN_00494840(local_b4);
          for (; local_b0 != 0; local_b0 = local_b0 + -1) {
            local_b8 = 0;
            local_a8 = local_ac;
            while (local_b8 < (int)local_b4) {
              local_bc = FUN_00498340((int *)local_a4);
              _local_c = CONCAT31(uStack_b,(char)local_bc);
              if ((local_bc & 0xff) < 0xc0) {
                local_bc = 1;
              }
              else {
                local_bc = local_bc & 0x3f;
                uVar2 = FUN_00498340((int *)local_a4);
                _local_c = CONCAT31(uStack_b,(char)uVar2);
              }
              while (local_bc != 0) {
                *(byte *)((int)local_a8 + local_b8) = local_c;
                local_b8 = local_b8 + 1;
                local_bc = local_bc - 1;
              }
              local_bc = 0xffffffff;
            }
            for (local_98 = 0; (local_98 < (int)(local_4b >> 8 & 0xffff) && (local_98 < local_90));
                local_98 = local_98 + 1) {
              local_c0 = (int)(uint)*(byte *)((int)local_ac + local_98) >> 3;
              local_c4 = (int)(uint)*(byte *)((int)local_ac + (local_4b >> 8 & 0xffff) + local_98)
                         >> 3;
              local_c8 = (int)(uint)*(byte *)((int)local_ac +
                                             local_98 + (local_4b >> 8 & 0xffff) * 2) >> 3;
              local_cc = (uint)(local_c0 + local_c4 + local_c8 != 0);
              uVar2 = FUN_004318a0(local_c0,local_c4,local_c8,local_cc);
              *local_a0 = (ushort)uVar2;
              local_a0 = local_a0 + 1;
            }
          }
          FUN_00495280(local_ac);
        }
        else {
          if ((uint)local_8c._3_1_ * (local_4b & 0xff) != 8) {
            FUN_00497b30((int *)local_a4);
            goto LAB_00431fbd;
          }
          for (local_e4 = local_94; local_e4 != 0; local_e4 = local_e4 + -1) {
            local_98 = 0;
            while (local_98 < local_90) {
              uVar2 = FUN_00498340((int *)local_a4);
              bVar1 = (byte)uVar2;
              _local_c = CONCAT31(uStack_b,bVar1);
              if ((uVar2 & 0xff) < 0xc0) {
                *local_a0 = (ushort)bVar1;
                local_a0 = local_a0 + 1;
                local_98 = local_98 + 1;
              }
              else {
                local_d0 = CONCAT31(local_d0._1_3_,bVar1 + 0x40);
                uVar2 = FUN_00498340((int *)local_a4);
                _local_c = CONCAT31(uStack_b,(byte)uVar2);
                local_98 = local_98 + (local_d0 & 0xff);
                while( true ) {
                  uVar3 = local_d0 & 0xff;
                  local_d0 = CONCAT31(local_d0._1_3_,(char)local_d0 + -1);
                  if (uVar3 == 0) break;
                  *local_a0 = (ushort)(byte)uVar2;
                  local_a0 = local_a0 + 1;
                }
              }
            }
            FUN_004988b0(local_a4,(local_4b >> 8 & 0xffff) - local_98,1);
          }
          FUN_004988b0(local_a4,-0x300,2);
          for (local_98 = 0; local_98 < 0x100; local_98 = local_98 + 1) {
            uVar2 = FUN_00498340((int *)local_a4);
            local_d4 = CONCAT22(local_d4._2_2_,(short)((int)uVar2 >> 3));
            uVar2 = FUN_00498340((int *)local_a4);
            local_d8 = CONCAT22(local_d8._2_2_,(short)((int)uVar2 >> 3));
            uVar2 = FUN_00498340((int *)local_a4);
            uVar2 = (int)uVar2 >> 3;
            _local_dc = CONCAT22(uStack_da,(short)uVar2);
            if ((local_d4 & 0xffff) + (local_d8 & 0xffff) + (uVar2 & 0xffff) == 0) {
              local_e0 = (uint)local_e0._2_2_ << 0x10;
            }
            else {
              local_e0 = CONCAT22(local_e0._2_2_,1);
            }
            uVar2 = FUN_004318a0(local_d4 & 0xffff,local_d8 & 0xffff,uVar2 & 0xffff,
                                 local_e0 & 0xffff);
            *(short *)(&DAT_004f5f20 + local_98 * 2) = (short)uVar2;
          }
          local_a0 = local_9c;
          for (local_e4 = local_94; local_e4 != 0; local_e4 = local_e4 + -1) {
            for (local_98 = 0; local_98 < local_90; local_98 = local_98 + 1) {
              *local_a0 = *(ushort *)(&DAT_004f5f20 + (uint)*local_a0 * 2);
              local_a0 = local_a0 + 1;
            }
          }
        }
        FUN_00497b30((int *)local_a4);
      }
    }
    else {
      FUN_00497b30((int *)local_a4);
    }
  }
LAB_00431fbd:
  uStack_8 = 0x431fcd;
  __chkesp();
  return;
}

