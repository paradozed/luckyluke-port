/* FUN_004479e0 @ 004479e0 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __cdecl FUN_004479e0(int param_1,int param_2)

{
  undefined3 uVar3;
  undefined4 uVar1;
  int3 iVar4;
  uint uVar2;
  int iVar5;
  undefined4 *puVar6;
  longlong lVar7;
  undefined4 local_134 [16];
  int local_f4;
  uint local_f0;
  int local_ec;
  uint local_e8;
  int local_e4;
  uint local_e0;
  int local_dc;
  uint local_d8;
  int local_d4;
  uint local_d0;
  int local_cc;
  uint local_c8;
  int local_c4;
  uint local_c0;
  undefined4 uStack_bc;
  int local_b8;
  uint local_b4;
  int local_b0;
  uint local_ac;
  int local_a8;
  uint local_a4;
  int local_a0;
  uint local_9c;
  int local_98;
  uint local_94;
  int local_90;
  uint local_8c;
  int local_88;
  int local_84;
  int local_80;
  uint local_7c;
  int local_78;
  uint local_74;
  int local_70;
  uint local_6c;
  int local_68;
  uint local_64;
  int local_60;
  uint local_5c;
  int local_58;
  uint local_54;
  int local_50;
  uint local_4c;
  undefined4 uStack_48;
  int local_44;
  uint local_40;
  int local_3c;
  uint local_38;
  int local_34;
  uint local_30;
  int local_2c;
  uint local_28;
  int local_24;
  uint local_20;
  int local_1c;
  uint local_18;
  int local_14;
  int local_10;
  float local_c;
  float local_8;
  
  puVar6 = local_134;
  for (iVar5 = 0x4c; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0xcccccccc;
    puVar6 = puVar6 + 1;
  }
  uVar3 = (undefined3)((uint)param_1 >> 8);
  if ((uint)(int)*(short *)(param_1 + 8) < DAT_004be3c8) {
    iVar4 = (int3)(char)((ushort)*(short *)(param_1 + 0x10) >> 8);
    if (*(short *)(param_1 + 0x10) < 0) {
      uVar1 = CONCAT31(iVar4,1);
    }
    else if ((uint)(int)*(short *)(param_1 + 10) < DAT_004be3cc) {
      if (*(short *)(param_1 + 0x1a) < 0) {
        uVar1 = CONCAT31(uVar3,1);
      }
      else {
        if (*(short *)(param_1 + 8) < 0) {
          local_10 = -(int)*(short *)(param_1 + 8);
          local_14 = (int)*(short *)(param_1 + 0x10) - (int)*(short *)(param_1 + 8);
          local_8 = (float)local_10 / (float)local_14;
          local_18 = (uint)*(byte *)(param_2 + 4);
          local_1c = (uint)*(byte *)(param_1 + 0xc) - (uint)*(byte *)(param_1 + 4);
          lVar7 = __ftol();
          *(char *)(param_2 + 4) = (char)lVar7;
          local_20 = (uint)*(byte *)(param_2 + 5);
          local_24 = (uint)*(byte *)(param_1 + 0xd) - (uint)*(byte *)(param_1 + 5);
          lVar7 = __ftol();
          *(char *)(param_2 + 5) = (char)lVar7;
          local_28 = (uint)*(byte *)(param_2 + 6);
          local_2c = (uint)*(byte *)(param_1 + 0xe) - (uint)*(byte *)(param_1 + 6);
          lVar7 = __ftol();
          *(char *)(param_2 + 6) = (char)lVar7;
          local_30 = (uint)*(byte *)(param_2 + 0x14);
          local_34 = (uint)*(byte *)(param_1 + 0x1c) - (uint)*(byte *)(param_1 + 0x14);
          lVar7 = __ftol();
          *(char *)(param_2 + 0x14) = (char)lVar7;
          local_38 = (uint)*(byte *)(param_2 + 0x15);
          local_3c = (uint)*(byte *)(param_1 + 0x1d) - (uint)*(byte *)(param_1 + 0x15);
          lVar7 = __ftol();
          *(char *)(param_2 + 0x15) = (char)lVar7;
          local_40 = (uint)*(byte *)(param_2 + 0x16);
          local_44 = (uint)*(byte *)(param_1 + 0x1e) - (uint)*(byte *)(param_1 + 0x16);
          lVar7 = __ftol();
          *(char *)(param_2 + 0x16) = (char)lVar7;
          *(undefined2 *)(param_2 + 8) = 0;
          *(undefined2 *)(param_2 + 0x18) = 0;
        }
        if (DAT_004be3c8 <= (uint)(int)*(short *)(param_1 + 0x10)) {
          local_4c = (int)*(short *)(param_1 + 0x10) - DAT_004be3c8;
          uStack_48 = 0;
          local_50 = (int)*(short *)(param_1 + 0x10) - (int)*(short *)(param_1 + 8);
          local_8 = (float)local_4c / (float)local_50;
          local_54 = (uint)*(byte *)(param_2 + 0xc);
          local_58 = (uint)*(byte *)(param_1 + 0xc) - (uint)*(byte *)(param_1 + 4);
          lVar7 = __ftol();
          *(char *)(param_2 + 0xc) = (char)lVar7;
          local_5c = (uint)*(byte *)(param_2 + 0xd);
          local_60 = (uint)*(byte *)(param_1 + 0xd) - (uint)*(byte *)(param_1 + 5);
          lVar7 = __ftol();
          *(char *)(param_2 + 0xd) = (char)lVar7;
          local_64 = (uint)*(byte *)(param_2 + 0xe);
          local_68 = (uint)*(byte *)(param_1 + 0xe) - (uint)*(byte *)(param_1 + 6);
          lVar7 = __ftol();
          *(char *)(param_2 + 0xe) = (char)lVar7;
          local_6c = (uint)*(byte *)(param_2 + 0x1c);
          local_70 = (uint)*(byte *)(param_1 + 0x1c) - (uint)*(byte *)(param_1 + 0x14);
          lVar7 = __ftol();
          *(char *)(param_2 + 0x1c) = (char)lVar7;
          local_74 = (uint)*(byte *)(param_2 + 0x1d);
          local_78 = (uint)*(byte *)(param_1 + 0x1d) - (uint)*(byte *)(param_1 + 0x15);
          lVar7 = __ftol();
          *(char *)(param_2 + 0x1d) = (char)lVar7;
          local_7c = (uint)*(byte *)(param_2 + 0x1e);
          local_80 = (uint)*(byte *)(param_1 + 0x1e) - (uint)*(byte *)(param_1 + 0x16);
          lVar7 = __ftol();
          *(char *)(param_2 + 0x1e) = (char)lVar7;
          *(short *)(param_2 + 0x10) = (short)DAT_004be3c8 + -1;
          *(short *)(param_2 + 0x20) = (short)DAT_004be3c8 + -1;
        }
        if (*(short *)(param_1 + 10) < 0) {
          local_84 = -(int)*(short *)(param_1 + 10);
          local_88 = (int)*(short *)(param_1 + 0x1a) - (int)*(short *)(param_1 + 10);
          local_c = (float)local_84 / (float)local_88;
          local_8c = (uint)*(byte *)(param_2 + 4);
          local_90 = (uint)*(byte *)(param_1 + 0x14) - (uint)*(byte *)(param_1 + 4);
          lVar7 = __ftol();
          *(char *)(param_2 + 4) = (char)lVar7;
          local_94 = (uint)*(byte *)(param_2 + 5);
          local_98 = (uint)*(byte *)(param_1 + 0x15) - (uint)*(byte *)(param_1 + 5);
          lVar7 = __ftol();
          *(char *)(param_2 + 5) = (char)lVar7;
          local_9c = (uint)*(byte *)(param_2 + 6);
          local_a0 = (uint)*(byte *)(param_1 + 0x16) - (uint)*(byte *)(param_1 + 6);
          lVar7 = __ftol();
          *(char *)(param_2 + 6) = (char)lVar7;
          local_a4 = (uint)*(byte *)(param_2 + 0xc);
          local_a8 = (uint)*(byte *)(param_1 + 0x1c) - (uint)*(byte *)(param_1 + 0xc);
          lVar7 = __ftol();
          *(char *)(param_2 + 0xc) = (char)lVar7;
          local_ac = (uint)*(byte *)(param_2 + 0xd);
          local_b0 = (uint)*(byte *)(param_1 + 0x1d) - (uint)*(byte *)(param_1 + 0xd);
          lVar7 = __ftol();
          *(char *)(param_2 + 0xd) = (char)lVar7;
          local_b4 = (uint)*(byte *)(param_2 + 0xe);
          local_b8 = (uint)*(byte *)(param_1 + 0x1e) - (uint)*(byte *)(param_1 + 0xe);
          lVar7 = __ftol();
          *(char *)(param_2 + 0xe) = (char)lVar7;
          *(undefined2 *)(param_2 + 10) = 0;
          *(undefined2 *)(param_2 + 0x12) = 0;
        }
        uVar2 = (int)*(short *)(param_1 + 0x1a);
        if (DAT_004be3cc <= (uint)(int)*(short *)(param_1 + 0x1a)) {
          local_c0 = (int)*(short *)(param_1 + 0x1a) - DAT_004be3cc;
          uStack_bc = 0;
          local_c4 = (int)*(short *)(param_1 + 0x1a) - (int)*(short *)(param_1 + 10);
          local_c = (float)local_c0 / (float)local_c4;
          local_c8 = (uint)*(byte *)(param_2 + 0x14);
          local_cc = (uint)*(byte *)(param_1 + 0x14) - (uint)*(byte *)(param_1 + 4);
          lVar7 = __ftol();
          *(char *)(param_2 + 0x14) = (char)lVar7;
          local_d0 = (uint)*(byte *)(param_2 + 0x15);
          local_d4 = (uint)*(byte *)(param_1 + 0x15) - (uint)*(byte *)(param_1 + 5);
          lVar7 = __ftol();
          *(char *)(param_2 + 0x15) = (char)lVar7;
          local_d8 = (uint)*(byte *)(param_2 + 0x16);
          local_dc = (uint)*(byte *)(param_1 + 0x16) - (uint)*(byte *)(param_1 + 6);
          lVar7 = __ftol();
          *(char *)(param_2 + 0x16) = (char)lVar7;
          local_e0 = (uint)*(byte *)(param_2 + 0x1c);
          local_e4 = (uint)*(byte *)(param_1 + 0x1c) - (uint)*(byte *)(param_1 + 0xc);
          lVar7 = __ftol();
          *(char *)(param_2 + 0x1c) = (char)lVar7;
          local_e8 = (uint)*(byte *)(param_2 + 0x1d);
          local_ec = (uint)*(byte *)(param_1 + 0x1d) - (uint)*(byte *)(param_1 + 0xd);
          lVar7 = __ftol();
          *(char *)(param_2 + 0x1d) = (char)lVar7;
          local_f0 = (uint)*(byte *)(param_2 + 0x1e);
          local_f4 = (uint)*(byte *)(param_1 + 0x1e) - (uint)*(byte *)(param_1 + 0xe);
          lVar7 = __ftol();
          *(char *)(param_2 + 0x1e) = (char)lVar7;
          *(short *)(param_2 + 0x1a) = (short)DAT_004be3cc + -1;
          *(short *)(param_2 + 0x22) = (short)DAT_004be3cc + -1;
          uVar2 = param_2;
        }
        uVar1 = CONCAT31((int3)(uVar2 >> 8),1);
      }
    }
    else {
      uVar1 = CONCAT31(iVar4,1);
    }
  }
  else {
    uVar1 = CONCAT31(uVar3,1);
  }
  return uVar1;
}

