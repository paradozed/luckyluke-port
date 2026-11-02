/* FUN_00448170 @ 00448170 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __cdecl FUN_00448170(int param_1,int param_2)

{
  undefined4 uVar1;
  int3 iVar3;
  uint uVar2;
  int iVar4;
  undefined4 *puVar5;
  longlong lVar6;
  undefined4 local_b4 [16];
  int local_74;
  uint local_70;
  int local_6c;
  uint local_68;
  int local_64;
  uint local_60;
  undefined4 uStack_5c;
  int local_58;
  uint local_54;
  int local_50;
  uint local_4c;
  int local_48;
  int local_44;
  int local_40;
  uint local_3c;
  int local_38;
  uint local_34;
  int local_30;
  uint local_2c;
  undefined4 uStack_28;
  int local_24;
  uint local_20;
  int local_1c;
  uint local_18;
  int local_14;
  int local_10;
  float local_c;
  float local_8;
  
  puVar5 = local_b4;
  for (iVar4 = 0x2c; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  if (DAT_004e8914 == 0x19) {
    uVar1 = 1;
  }
  else if ((uint)(int)*(short *)(param_1 + 8) < DAT_004be3c8) {
    if (*(short *)(param_1 + 0x10) < 0) {
      uVar1 = CONCAT31((int3)((uint)param_1 >> 8),1);
    }
    else {
      iVar3 = (int3)(char)((ushort)*(short *)(param_1 + 10) >> 8);
      if ((uint)(int)*(short *)(param_1 + 10) < DAT_004be3cc) {
        if (*(short *)(param_1 + 0x1a) < 0) {
          uVar1 = CONCAT31(iVar3,1);
        }
        else {
          if (*(short *)(param_1 + 8) < 0) {
            local_10 = -(int)*(short *)(param_1 + 8);
            local_14 = (int)*(short *)(param_1 + 0x10) - (int)*(short *)(param_1 + 8);
            local_8 = (float)local_10 / (float)local_14;
            local_18 = (uint)*(byte *)(param_2 + 0xc);
            local_1c = (uint)*(byte *)(param_1 + 0x14) - (uint)*(byte *)(param_1 + 0xc);
            lVar6 = __ftol();
            *(char *)(param_2 + 0xc) = (char)lVar6;
            local_20 = (uint)*(byte *)(param_2 + 0x1c);
            local_24 = (uint)*(byte *)(param_1 + 0x24) - (uint)*(byte *)(param_1 + 0x1c);
            lVar6 = __ftol();
            *(char *)(param_2 + 0x1c) = (char)lVar6;
            *(undefined2 *)(param_2 + 8) = 0;
            *(undefined2 *)(param_2 + 0x18) = 0;
          }
          if (DAT_004be3c8 <= (uint)(int)*(short *)(param_1 + 0x10)) {
            local_2c = (int)*(short *)(param_1 + 0x10) - DAT_004be3c8;
            uStack_28 = 0;
            local_30 = (int)*(short *)(param_1 + 0x10) - (int)*(short *)(param_1 + 8);
            local_8 = (float)local_2c / (float)local_30;
            local_34 = (uint)*(byte *)(param_2 + 0x14);
            local_38 = (uint)*(byte *)(param_1 + 0x14) - (uint)*(byte *)(param_1 + 0xc);
            lVar6 = __ftol();
            *(char *)(param_2 + 0x14) = (char)lVar6;
            local_3c = (uint)*(byte *)(param_2 + 0x24);
            local_40 = (uint)*(byte *)(param_1 + 0x24) - (uint)*(byte *)(param_1 + 0x1c);
            lVar6 = __ftol();
            *(char *)(param_2 + 0x24) = (char)lVar6;
            *(short *)(param_2 + 0x10) = (short)DAT_004be3c8 + -1;
            *(short *)(param_2 + 0x20) = (short)DAT_004be3c8 + -1;
          }
          if (*(short *)(param_1 + 10) < 0) {
            local_44 = -(int)*(short *)(param_1 + 10);
            local_48 = (int)*(short *)(param_1 + 0x1a) - (int)*(short *)(param_1 + 10);
            local_c = (float)local_44 / (float)local_48;
            local_4c = (uint)*(byte *)(param_2 + 0xd);
            local_50 = (uint)*(byte *)(param_1 + 0x1d) - (uint)*(byte *)(param_1 + 0xd);
            lVar6 = __ftol();
            *(char *)(param_2 + 0xd) = (char)lVar6;
            local_54 = (uint)*(byte *)(param_2 + 0x15);
            local_58 = (uint)*(byte *)(param_1 + 0x25) - (uint)*(byte *)(param_1 + 0x15);
            lVar6 = __ftol();
            *(char *)(param_2 + 0x15) = (char)lVar6;
            *(undefined2 *)(param_2 + 10) = 0;
            *(undefined2 *)(param_2 + 0x12) = 0;
          }
          uVar2 = (int)*(short *)(param_1 + 0x1a);
          if (DAT_004be3cc <= (uint)(int)*(short *)(param_1 + 0x1a)) {
            local_60 = (int)*(short *)(param_1 + 0x1a) - DAT_004be3cc;
            uStack_5c = 0;
            local_64 = (int)*(short *)(param_1 + 0x1a) - (int)*(short *)(param_1 + 10);
            local_c = (float)local_60 / (float)local_64;
            local_68 = (uint)*(byte *)(param_2 + 0x1d);
            local_6c = (uint)*(byte *)(param_1 + 0x1d) - (uint)*(byte *)(param_1 + 0xd);
            lVar6 = __ftol();
            *(char *)(param_2 + 0x1d) = (char)lVar6;
            local_70 = (uint)*(byte *)(param_2 + 0x25);
            local_74 = (uint)*(byte *)(param_1 + 0x25) - (uint)*(byte *)(param_1 + 0x15);
            lVar6 = __ftol();
            *(char *)(param_2 + 0x25) = (char)lVar6;
            *(short *)(param_2 + 0x1a) = (short)DAT_004be3cc + -1;
            *(short *)(param_2 + 0x22) = (short)DAT_004be3cc + -1;
            uVar2 = param_2;
          }
          uVar1 = CONCAT31((int3)(uVar2 >> 8),1);
        }
      }
      else {
        uVar1 = CONCAT31(iVar3,1);
      }
    }
  }
  else {
    uVar1 = CONCAT31((uint3)(byte)((ushort)DAT_004e8914 >> 8),1);
  }
  return uVar1;
}

