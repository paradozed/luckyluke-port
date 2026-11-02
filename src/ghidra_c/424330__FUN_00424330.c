/* FUN_00424330 @ 00424330 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall FUN_00424330(void *this,ushort *param_1)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  undefined2 uVar5;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  undefined2 *puVar6;
  undefined2 extraout_var_03;
  undefined2 extraout_var_04;
  uint uVar7;
  void *pvVar8;
  undefined4 uVar9;
  int iVar10;
  undefined2 extraout_var_05;
  undefined2 extraout_var_06;
  undefined2 extraout_var_07;
  undefined2 extraout_var_08;
  undefined2 extraout_var_09;
  undefined2 extraout_var_10;
  undefined2 extraout_var_11;
  undefined4 *puVar11;
  undefined4 local_114 [16];
  short *local_d4;
  short *local_d0;
  short *local_cc;
  short *local_c8;
  short *local_c4;
  short *local_c0;
  short *local_bc;
  short *local_b8;
  uint local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  uint local_a4;
  uint local_a0;
  uint local_9c;
  void *local_98;
  void *local_94;
  void *local_90;
  undefined2 local_8c;
  ushort local_88;
  undefined2 uStack_86;
  undefined2 local_84;
  undefined2 local_80;
  ushort local_7c;
  undefined2 uStack_7a;
  undefined2 local_78;
  undefined2 local_74;
  ushort local_70;
  undefined2 uStack_6e;
  undefined2 local_6c;
  ushort local_68;
  undefined2 uStack_66;
  undefined2 local_64;
  uint local_60;
  undefined2 local_5c;
  short local_58;
  short local_54;
  ushort local_50;
  ushort local_4c;
  ushort local_48;
  ushort local_44;
  short local_40;
  short local_3c;
  short local_38;
  ushort local_34;
  ushort local_30;
  int local_2c;
  undefined2 *local_28;
  uint local_24;
  short local_20;
  short local_1c;
  short local_18;
  undefined2 *local_14;
  undefined2 *local_10;
  ushort local_c;
  undefined2 uStack_a;
  void *local_8;
  
  puVar11 = local_114;
  for (iVar10 = 0x44; iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar11 = 0xcccccccc;
    puVar11 = puVar11 + 1;
  }
  local_8 = this;
  iVar10 = FUN_00424300((int)this);
  local_b4 = (uint)*(byte *)(iVar10 + (uint)*param_1);
  switch(local_b4) {
  case 0:
    FUN_00417250(local_8,2,1);
    break;
  case 1:
    goto LAB_0042563f;
  case 2:
    uVar3 = FUN_00425940((int)local_8 + 8);
    *param_1 = uVar3;
    uVar3 = FUN_00425940((int)local_8 + 8);
    _local_c = CONCAT22(uStack_a,uVar3);
    uVar7 = (uint)uVar3;
    pvVar8 = (void *)FUN_00409d00((int)local_8);
    uVar9 = FUN_00421420(pvVar8,uVar7);
    *(undefined4 *)((int)local_8 + 0x78) = uVar9;
    break;
  case 3:
    sVar4 = FUN_00425940((int)local_8 + 8);
    if (sVar4 == 0) {
      iVar10 = FUN_00424300((int)local_8);
      *param_1 = *(ushort *)(iVar10 + 1 + (uint)*param_1);
    }
    else {
      *param_1 = *param_1 + 3;
    }
    break;
  case 4:
    iVar10 = FUN_00424300((int)local_8);
    *param_1 = *(ushort *)(iVar10 + 1 + (uint)*param_1);
    break;
  case 5:
    iVar10 = FUN_00424300((int)local_8);
    FUN_004258f0((void *)((int)local_8 + 8),*(undefined2 *)(iVar10 + 1 + (uint)*param_1));
    *param_1 = *param_1 + 3;
    break;
  case 6:
    iVar10 = FUN_00424300((int)local_8);
    FUN_004258f0((void *)((int)local_8 + 8),*(undefined2 *)(iVar10 + 1 + (uint)*param_1));
    *param_1 = *param_1 + 3;
    break;
  case 7:
    iVar10 = FUN_00424300((int)local_8);
    local_10 = (undefined2 *)
               FUN_00421fc0(*(void **)((int)local_8 + 0x78),
                            CONCAT22((short)((uint)iVar10 >> 0x10),
                                     *(undefined2 *)(iVar10 + 1 + (uint)*param_1)));
    FUN_004258f0((void *)((int)local_8 + 8),*local_10);
    *param_1 = *param_1 + 3;
    break;
  case 8:
    iVar10 = FUN_00424300((int)local_8);
    uVar7 = CONCAT22((short)((uint)iVar10 >> 0x10),*(undefined2 *)(iVar10 + 3 + (uint)*param_1));
    iVar10 = FUN_00424300((int)local_8);
    pvVar8 = (void *)FUN_00421420(*(void **)((int)local_8 + 0x90),
                                  (uint)*(ushort *)(iVar10 + 1 + (uint)*param_1));
    local_14 = (undefined2 *)FUN_00421fc0(pvVar8,uVar7);
    FUN_004258f0((void *)((int)local_8 + 8),*local_14);
    *param_1 = *param_1 + 5;
    break;
  case 9:
    iVar10 = FUN_00424300((int)local_8);
    FUN_004258f0((void *)((int)local_8 + 8),*(undefined2 *)(iVar10 + 1 + (uint)*param_1));
    *param_1 = *param_1 + 3;
    break;
  case 10:
    iVar10 = FUN_00424300((int)local_8);
    FUN_004258f0((void *)((int)local_8 + 8),*(undefined2 *)(iVar10 + 1 + (uint)*param_1));
    iVar10 = FUN_00424300((int)local_8);
    FUN_004258f0((void *)((int)local_8 + 8),*(undefined2 *)(iVar10 + 3 + (uint)*param_1));
    *param_1 = *param_1 + 5;
    break;
  case 0xb:
    local_18 = FUN_00425940((int)local_8 + 8);
    sVar4 = local_18;
    uVar5 = FUN_00425940((int)local_8 + 8);
    uVar5 = FUN_00422060(*(void **)((int)local_8 + 0x90),CONCAT22(extraout_var,uVar5),sVar4);
    FUN_004258f0((void *)((int)local_8 + 8),uVar5);
    *param_1 = *param_1 + 1;
    break;
  case 0xc:
    local_1c = FUN_00425940((int)local_8 + 8);
    sVar4 = local_1c;
    uVar5 = FUN_004074b0((void *)((int)local_8 + 8),1);
    uVar5 = FUN_00422060(*(void **)((int)local_8 + 0x90),CONCAT22(extraout_var_00,uVar5),sVar4);
    FUN_004258f0((void *)((int)local_8 + 8),uVar5);
    *param_1 = *param_1 + 1;
    break;
  case 0xd:
    local_20 = FUN_00425940((int)local_8 + 8);
    uVar5 = FUN_00425940((int)local_8 + 8);
    local_24 = CONCAT22(local_24._2_2_,uVar5);
    uVar7 = FUN_00422060(*(void **)((int)local_8 + 0x90),CONCAT22(extraout_var_01,uVar5),local_20);
    pvVar8 = (void *)FUN_00421420(*(void **)((int)local_8 + 0x90),local_24 & 0xffff);
    local_28 = (undefined2 *)FUN_00421fc0(pvVar8,uVar7);
    FUN_004258f0((void *)((int)local_8 + 8),*local_28);
    *param_1 = *param_1 + 1;
    break;
  case 0xe:
    sVar4 = *(short *)((int)local_8 + 0x70);
    iVar10 = FUN_00424300((int)local_8);
    if (sVar4 == *(short *)(iVar10 + 1 + (uint)*param_1)) {
      iVar10 = FUN_00424300((int)local_8);
      *param_1 = *(ushort *)(iVar10 + 3 + (uint)*param_1);
    }
    else {
      iVar10 = FUN_00424300((int)local_8);
      FUN_004258f0((void *)((int)local_8 + 8),*(undefined2 *)(iVar10 + 1 + (uint)*param_1));
      *param_1 = *param_1 + 5;
    }
    break;
  case 0xf:
    sVar4 = FUN_00425940((int)local_8 + 8);
    if (sVar4 == 0) {
      FUN_00425940((int)local_8 + 8);
    }
    else {
      sVar4 = FUN_00425940((int)local_8 + 8);
      FUN_004242a0(local_8,sVar4);
    }
    *param_1 = *param_1 + 1;
    break;
  case 0x10:
    FUN_00417250(local_8,4,1);
    *param_1 = *param_1 + 1;
    break;
  case 0x11:
    FUN_00417250(local_8,4,0);
    *param_1 = *param_1 + 1;
    break;
  case 0x12:
    uVar3 = FUN_00424270(*(int *)((int)local_8 + 0x78));
    sVar4 = FUN_00425940((int)local_8 + 8);
    if ((uint)uVar3 == (int)sVar4) {
      FUN_004258f0((void *)((int)local_8 + 8),1);
    }
    else {
      FUN_004258f0((void *)((int)local_8 + 8),0);
    }
    *param_1 = *param_1 + 1;
    break;
  case 0x13:
    sVar4 = FUN_00425940((int)local_8 + 8);
    local_2c = FUN_00421420(*(void **)((int)local_8 + 0x90),(int)sVar4);
    uVar3 = FUN_00424270(local_2c);
    sVar4 = FUN_00425940((int)local_8 + 8);
    if ((uint)uVar3 == (int)sVar4) {
      FUN_004258f0((void *)((int)local_8 + 8),1);
    }
    else {
      FUN_004258f0((void *)((int)local_8 + 8),0);
    }
    *param_1 = *param_1 + 1;
    break;
  case 0x14:
    sVar4 = FUN_00425940((int)local_8 + 8);
    FUN_004258f0((void *)((int)local_8 + 8),(ushort)(sVar4 == 0));
    *param_1 = *param_1 + 1;
    break;
  case 0x15:
    sVar4 = FUN_00425940((int)local_8 + 8);
    local_30 = sVar4;
    sVar1 = FUN_00425940((int)local_8 + 8);
    local_30 = (ushort)(sVar4 == sVar1);
    FUN_004258f0((void *)((int)local_8 + 8),local_30);
    *param_1 = *param_1 + 1;
    break;
  case 0x16:
    sVar4 = FUN_00425940((int)local_8 + 8);
    local_34 = sVar4;
    sVar1 = FUN_00425940((int)local_8 + 8);
    local_34 = (ushort)(sVar4 != sVar1);
    FUN_004258f0((void *)((int)local_8 + 8),local_34);
    *param_1 = *param_1 + 1;
    break;
  case 0x17:
    sVar4 = FUN_00425940((int)local_8 + 8);
    if (sVar4 == 0) {
      FUN_00425940((int)local_8 + 8);
      FUN_004258f0((void *)((int)local_8 + 8),0);
    }
    else {
      sVar4 = FUN_00425940((int)local_8 + 8);
      if (sVar4 == 0) {
        FUN_004258f0((void *)((int)local_8 + 8),0);
      }
      else {
        FUN_004258f0((void *)((int)local_8 + 8),1);
      }
    }
    *param_1 = *param_1 + 1;
    break;
  case 0x18:
    sVar4 = FUN_00425940((int)local_8 + 8);
    if (sVar4 == 0) {
      sVar4 = FUN_00425940((int)local_8 + 8);
      if (sVar4 == 0) {
        FUN_004258f0((void *)((int)local_8 + 8),0);
      }
      else {
        FUN_004258f0((void *)((int)local_8 + 8),1);
      }
    }
    else {
      FUN_00425940((int)local_8 + 8);
      FUN_004258f0((void *)((int)local_8 + 8),1);
    }
    *param_1 = *param_1 + 1;
    break;
  case 0x19:
    local_38 = FUN_00425940((int)local_8 + 8);
    sVar4 = FUN_00425940((int)local_8 + 8);
    local_38 = local_38 - sVar4;
    FUN_004258f0((void *)((int)local_8 + 8),local_38);
    *param_1 = *param_1 + 1;
    break;
  case 0x1a:
    sVar4 = FUN_00425940((int)local_8 + 8);
    sVar1 = FUN_00425940((int)local_8 + 8);
    FUN_004258f0((void *)((int)local_8 + 8),sVar4 + sVar1);
    *param_1 = *param_1 + 1;
    break;
  case 0x1b:
    sVar4 = FUN_00425940((int)local_8 + 8);
    local_3c = sVar4;
    local_3c = FUN_00425940((int)local_8 + 8);
    local_3c = sVar4 / local_3c;
    FUN_004258f0((void *)((int)local_8 + 8),local_3c);
    *param_1 = *param_1 + 1;
    break;
  case 0x1c:
    sVar4 = FUN_00425940((int)local_8 + 8);
    sVar1 = FUN_00425940((int)local_8 + 8);
    FUN_004258f0((void *)((int)local_8 + 8),sVar4 * sVar1);
    *param_1 = *param_1 + 1;
    break;
  case 0x1d:
    local_40 = FUN_00425940((int)local_8 + 8);
    iVar10 = (int)local_40;
    sVar4 = FUN_00425940((int)local_8 + 8);
    local_40 = (short)(iVar10 % (int)sVar4);
    FUN_004258f0((void *)((int)local_8 + 8),local_40);
    *param_1 = *param_1 + 1;
    break;
  case 0x1e:
    sVar4 = FUN_00425940((int)local_8 + 8);
    local_44 = sVar4;
    sVar1 = FUN_00425940((int)local_8 + 8);
    local_44 = (ushort)(sVar4 < sVar1);
    FUN_004258f0((void *)((int)local_8 + 8),local_44);
    *param_1 = *param_1 + 1;
    break;
  case 0x1f:
    sVar4 = FUN_00425940((int)local_8 + 8);
    local_48 = sVar4;
    sVar1 = FUN_00425940((int)local_8 + 8);
    local_48 = (ushort)(sVar1 < sVar4);
    FUN_004258f0((void *)((int)local_8 + 8),local_48);
    *param_1 = *param_1 + 1;
    break;
  case 0x20:
    sVar4 = FUN_00425940((int)local_8 + 8);
    local_4c = sVar4;
    sVar1 = FUN_00425940((int)local_8 + 8);
    local_4c = (ushort)(sVar4 <= sVar1);
    FUN_004258f0((void *)((int)local_8 + 8),local_4c);
    *param_1 = *param_1 + 1;
    break;
  case 0x21:
    sVar4 = FUN_00425940((int)local_8 + 8);
    local_50 = sVar4;
    sVar1 = FUN_00425940((int)local_8 + 8);
    local_50 = (ushort)(sVar1 <= sVar4);
    FUN_004258f0((void *)((int)local_8 + 8),local_50);
    *param_1 = *param_1 + 1;
    break;
  case 0x22:
    sVar4 = FUN_00425940((int)local_8 + 8);
    FUN_004258f0((void *)((int)local_8 + 8),-sVar4);
    *param_1 = *param_1 + 1;
    break;
  case 0x23:
    uVar3 = FUN_00425940((int)local_8 + 8);
    uVar2 = FUN_00425940((int)local_8 + 8);
    FUN_004258f0((void *)((int)local_8 + 8),uVar3 & uVar2);
    *param_1 = *param_1 + 1;
    break;
  case 0x24:
    uVar3 = FUN_00425940((int)local_8 + 8);
    uVar2 = FUN_00425940((int)local_8 + 8);
    FUN_004258f0((void *)((int)local_8 + 8),uVar3 | uVar2);
    *param_1 = *param_1 + 1;
    break;
  case 0x25:
    local_54 = FUN_00425940((int)local_8 + 8);
    uVar5 = FUN_00425940((int)local_8 + 8);
    local_54 = local_54 << ((byte)uVar5 & 0x1f);
    FUN_004258f0((void *)((int)local_8 + 8),local_54);
    *param_1 = *param_1 + 1;
    break;
  case 0x26:
    local_58 = FUN_00425940((int)local_8 + 8);
    uVar5 = FUN_00425940((int)local_8 + 8);
    local_58 = local_58 >> ((byte)uVar5 & 0x1f);
    FUN_004258f0((void *)((int)local_8 + 8),local_58);
    *param_1 = *param_1 + 1;
    break;
  case 0x28:
    local_5c = FUN_00425940((int)local_8 + 8);
    uVar5 = FUN_004074b0((void *)((int)local_8 + 8),1);
    puVar6 = (undefined2 *)
             FUN_00421fc0(*(void **)((int)local_8 + 0x78),CONCAT22(extraout_var_05,local_5c));
    *puVar6 = uVar5;
    *param_1 = *param_1 + 1;
    break;
  case 0x29:
    local_64 = FUN_00425940((int)local_8 + 8);
    uVar5 = FUN_00425940((int)local_8 + 8);
    local_60 = CONCAT22(local_60._2_2_,uVar5);
    uVar5 = FUN_004074b0((void *)((int)local_8 + 8),1);
    uVar7 = CONCAT22(extraout_var_02,local_64);
    pvVar8 = (void *)FUN_00421420(*(void **)((int)local_8 + 0x90),local_60 & 0xffff);
    puVar6 = (undefined2 *)FUN_00421fc0(pvVar8,uVar7);
    *puVar6 = uVar5;
    *param_1 = *param_1 + 1;
    break;
  case 0x2a:
    uVar5 = FUN_00425940((int)local_8 + 8);
    local_b8 = (short *)FUN_00421fc0(*(void **)((int)local_8 + 0x78),CONCAT22(extraout_var_03,uVar5)
                                    );
    *local_b8 = *local_b8 + 1;
    *param_1 = *param_1 + 1;
    break;
  case 0x2b:
    local_6c = FUN_00425940((int)local_8 + 8);
    uVar3 = FUN_00425940((int)local_8 + 8);
    _local_68 = CONCAT22(uStack_66,uVar3);
    uVar7 = CONCAT22(extraout_var_06,local_6c);
    pvVar8 = (void *)FUN_00421420(*(void **)((int)local_8 + 0x90),(uint)uVar3);
    local_bc = (short *)FUN_00421fc0(pvVar8,uVar7);
    *local_bc = *local_bc + 1;
    *param_1 = *param_1 + 1;
    break;
  case 0x2c:
    uVar5 = FUN_00425940((int)local_8 + 8);
    local_c0 = (short *)FUN_00421fc0(*(void **)((int)local_8 + 0x78),CONCAT22(extraout_var_04,uVar5)
                                    );
    *local_c0 = *local_c0 + -1;
    *param_1 = *param_1 + 1;
    break;
  case 0x2d:
    local_74 = FUN_00425940((int)local_8 + 8);
    uVar3 = FUN_00425940((int)local_8 + 8);
    _local_70 = CONCAT22(uStack_6e,uVar3);
    uVar7 = CONCAT22(extraout_var_10,local_74);
    pvVar8 = (void *)FUN_00421420(*(void **)((int)local_8 + 0x90),(uint)uVar3);
    local_c4 = (short *)FUN_00421fc0(pvVar8,uVar7);
    *local_c4 = *local_c4 + -1;
    *param_1 = *param_1 + 1;
    break;
  case 0x2e:
    local_78 = FUN_00425940((int)local_8 + 8);
    local_c8 = (short *)FUN_00421fc0(*(void **)((int)local_8 + 0x78),
                                     CONCAT22(extraout_var_11,local_78));
    sVar4 = FUN_00425940((int)local_8 + 8);
    *local_c8 = *local_c8 + sVar4;
    *param_1 = *param_1 + 1;
    break;
  case 0x2f:
    local_80 = FUN_00425940((int)local_8 + 8);
    uVar3 = FUN_00425940((int)local_8 + 8);
    _local_7c = CONCAT22(uStack_7a,uVar3);
    uVar7 = CONCAT22(extraout_var_07,local_80);
    pvVar8 = (void *)FUN_00421420(*(void **)((int)local_8 + 0x90),(uint)uVar3);
    local_cc = (short *)FUN_00421fc0(pvVar8,uVar7);
    sVar4 = FUN_00425940((int)local_8 + 8);
    *local_cc = *local_cc + sVar4;
    *param_1 = *param_1 + 1;
    break;
  case 0x30:
    local_84 = FUN_00425940((int)local_8 + 8);
    local_d0 = (short *)FUN_00421fc0(*(void **)((int)local_8 + 0x78),
                                     CONCAT22(extraout_var_08,local_84));
    sVar4 = FUN_00425940((int)local_8 + 8);
    *local_d0 = *local_d0 - sVar4;
    *param_1 = *param_1 + 1;
    break;
  case 0x31:
    local_8c = FUN_00425940((int)local_8 + 8);
    uVar3 = FUN_00425940((int)local_8 + 8);
    _local_88 = CONCAT22(uStack_86,uVar3);
    uVar7 = CONCAT22(extraout_var_09,local_8c);
    pvVar8 = (void *)FUN_00421420(*(void **)((int)local_8 + 0x90),(uint)uVar3);
    local_d4 = (short *)FUN_00421fc0(pvVar8,uVar7);
    sVar4 = FUN_00425940((int)local_8 + 8);
    *local_d4 = *local_d4 - sVar4;
    *param_1 = *param_1 + 1;
    break;
  case 0x32:
    FUN_00417250(local_8,8,0);
    *param_1 = *param_1 + 1;
    break;
  case 0x34:
    FUN_00417250(*(void **)((int)local_8 + 0x78),1,1);
    FUN_00417250(*(void **)((int)local_8 + 0x78),8,0);
    *param_1 = *param_1 + 1;
    break;
  case 0x35:
    sVar4 = FUN_00425940((int)local_8 + 8);
    local_90 = (void *)FUN_00421420(*(void **)((int)local_8 + 0x90),(int)sVar4);
    FUN_00417250(local_90,1,0);
    *param_1 = *param_1 + 1;
    break;
  case 0x36:
    sVar4 = FUN_00425940((int)local_8 + 8);
    local_94 = (void *)FUN_00421420(*(void **)((int)local_8 + 0x90),(int)sVar4);
    FUN_00417250(local_94,1,1);
    *param_1 = *param_1 + 1;
    break;
  case 0x37:
    sVar4 = FUN_00425940((int)local_8 + 8);
    FUN_004242a0(*(void **)((int)local_8 + 0x78),sVar4);
    iVar10 = FUN_00421c90(*(int *)((int)local_8 + 0x78));
    if (iVar10 != 0) {
      FUN_00417250(*(void **)((int)local_8 + 0x78),8,0);
    }
    *param_1 = *param_1 + 1;
    break;
  case 0x38:
    sVar4 = FUN_00425940((int)local_8 + 8);
    local_98 = (void *)FUN_00421420(*(void **)((int)local_8 + 0x90),(int)sVar4);
    sVar4 = FUN_00425940((int)local_8 + 8);
    FUN_004242a0(local_98,sVar4);
    iVar10 = FUN_00421c90((int)local_98);
    if (iVar10 != 0) {
      FUN_00417250(local_98,8,0);
    }
    *param_1 = *param_1 + 1;
    break;
  case 0x39:
    uVar5 = FUN_00425940((int)local_8 + 8);
    local_9c = CONCAT22(local_9c._2_2_,uVar5);
    uVar9 = FUN_004214c0(*(undefined4 **)((int)local_8 + 0x78));
    FUN_004258f0((void *)((int)local_8 + 8),(short)uVar9);
    *param_1 = *param_1 + 1;
    FUN_004258f0((void *)((int)local_8 + 8),*param_1);
    *param_1 = *(ushort *)(*(int *)(*(int *)((int)local_8 + 0x78) + 0x88) + (local_9c & 0xffff) * 2)
    ;
    break;
  case 0x3a:
    uVar5 = FUN_00425940((int)local_8 + 8);
    local_a0 = CONCAT22(local_a0._2_2_,uVar5);
    uVar5 = FUN_00425940((int)local_8 + 8);
    local_a4 = CONCAT22(local_a4._2_2_,uVar5);
    uVar9 = FUN_004214c0(*(undefined4 **)((int)local_8 + 0x78));
    FUN_004258f0((void *)((int)local_8 + 8),(short)uVar9);
    *param_1 = *param_1 + 1;
    FUN_004258f0((void *)((int)local_8 + 8),*param_1);
    uVar7 = local_a0 & 0xffff;
    pvVar8 = (void *)FUN_00409d00((int)local_8);
    uVar9 = FUN_00421420(pvVar8,uVar7);
    *(undefined4 *)((int)local_8 + 0x78) = uVar9;
    *param_1 = *(ushort *)(*(int *)(*(int *)((int)local_8 + 0x78) + 0x88) + (local_a4 & 0xffff) * 2)
    ;
    break;
  case 0x3b:
    FUN_00425940((int)local_8 + 8);
    *param_1 = *param_1 + 1;
    break;
  case 0x3c:
  case 0x3d:
  case 0x3e:
  case 0x3f:
  case 0x40:
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x47:
  case 0x48:
  case 0x49:
  case 0x4a:
    local_a8 = 0;
    (*DAT_004d28a4)(local_8,(int)local_8 + 8,&local_a8);
    __chkesp();
    iVar10 = FUN_00424300((int)local_8);
    FUN_00425990((void *)((int)local_8 + 8),(*(byte *)(iVar10 + (uint)*param_1) - 0x3b) + local_a8);
    *param_1 = *param_1 + 1;
    break;
  case 0x50:
  case 0x51:
  case 0x52:
  case 0x53:
  case 0x54:
  case 0x55:
  case 0x56:
  case 0x57:
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x5b:
  case 0x5c:
  case 0x5d:
  case 0x5e:
    local_ac = 0;
    (*DAT_004d28a0)(local_8,(int)local_8 + 8,&local_ac);
    uVar9 = __chkesp();
    local_b0 = (int)(short)uVar9;
    iVar10 = FUN_00424300((int)local_8);
    FUN_00425990((void *)((int)local_8 + 8),(*(byte *)(iVar10 + (uint)*param_1) - 0x4f) + local_ac);
    FUN_004258f0((void *)((int)local_8 + 8),(undefined2)local_b0);
    *param_1 = *param_1 + 1;
  }
LAB_0042563f:
  local_8 = (void *)0x42564f;
  __chkesp();
  return;
}

