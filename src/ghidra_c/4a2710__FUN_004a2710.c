/* FUN_004a2710 @ 004a2710 */
/* decompiled from Lucky.exe (Game.run) */


int __cdecl FUN_004a2710(int *param_1,byte *param_2,undefined4 *param_3)

{
  byte bVar1;
  code *pcVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  bool bVar7;
  longlong lVar8;
  int *piVar9;
  int local_228;
  uint local_224;
  uint local_220;
  uint local_21c;
  uint local_218;
  uint local_214;
  uint local_210;
  uint local_20c;
  uint local_200;
  uint local_1fc;
  byte local_1f4;
  undefined1 local_1f3;
  uint local_1f0;
  int local_1ec;
  WCHAR *local_1e8;
  byte *local_1e4;
  int local_1e0;
  uint local_1dc;
  undefined4 *local_1d8;
  byte local_1d4;
  byte local_1d3 [351];
  char local_74;
  int local_70;
  char local_6c;
  char local_68;
  byte local_64 [11];
  undefined1 local_59;
  int local_44;
  WCHAR *local_40;
  char local_3c;
  int local_38;
  undefined8 local_34;
  char local_2c;
  uint local_28;
  int local_24;
  int local_20;
  char local_1c;
  char local_18;
  byte local_14;
  uint local_10;
  uint local_c;
  WCHAR local_8 [2];
  
  if ((param_2 == (byte *)0x0) &&
     (iVar4 = FUN_004999a0(2,0x4bb514,0x109,0,(byte *)"format != NULL"), iVar4 == 1)) {
    pcVar2 = (code *)swi(3);
    iVar4 = (*pcVar2)();
    return iVar4;
  }
  if ((param_1 == (int *)0x0) &&
     (iVar4 = FUN_004999a0(2,0x4bb514,0x10c,0,(byte *)"stream != NULL"), iVar4 == 1)) {
    pcVar2 = (code *)swi(3);
    iVar4 = (*pcVar2)();
    return iVar4;
  }
  local_2c = '\0';
  local_38 = 0;
  local_24 = local_38;
  do {
    if (*param_2 == 0) {
LAB_004a39fa:
      if ((local_1dc == 0xffffffff) && ((local_38 == 0 && (local_2c == '\0')))) {
        local_228 = -1;
        local_38 = local_228;
      }
      return local_38;
    }
    if ((int)DAT_004c71e8 < 2) {
      local_1fc = *(ushort *)(PTR_DAT_004c6fdc + (uint)*param_2 * 2) & 8;
    }
    else {
      local_1fc = FUN_0049c240((uint)*param_2,8);
    }
    if (local_1fc != 0) {
      local_24 = local_24 + -1;
      piVar9 = param_1;
      uVar5 = __whiteout(&local_24,param_1);
      FUN_004a3bb0(uVar5,piVar9);
      do {
        param_2 = param_2 + 1;
        uVar5 = FUN_004a8b00((uint)*param_2);
      } while (uVar5 != 0);
    }
    if (*param_2 == 0x25) {
      local_44 = 0;
      local_c = local_c & 0xffffff00;
      local_70 = 0;
      local_1ec = 0;
      local_20 = 0;
      local_14 = 0;
      local_6c = '\0';
      local_74 = '\0';
      local_1c = '\0';
      local_68 = '\0';
      local_18 = '\0';
      local_3c = '\x01';
      local_1e0 = 0;
LAB_004a2885:
      if (local_1c == '\0') {
        pbVar6 = param_2 + 1;
        local_10 = (uint)*pbVar6;
        if ((int)DAT_004c71e8 < 2) {
          local_200 = *(ushort *)(PTR_DAT_004c6fdc + local_10 * 2) & 4;
        }
        else {
          local_200 = FUN_0049c240(local_10,4);
        }
        if (local_200 == 0) {
          switch(local_10) {
          case 0x2a:
            local_74 = local_74 + '\x01';
            param_2 = pbVar6;
            break;
          case 0x46:
          case 0x4e:
            param_2 = pbVar6;
            break;
          case 0x49:
            if ((param_2[2] == 0x36) && (param_2[3] == 0x34)) {
              local_1e0 = local_1e0 + 1;
              local_34 = 0;
              param_2 = param_2 + 3;
              break;
            }
          default:
            local_1c = local_1c + '\x01';
            param_2 = pbVar6;
            break;
          case 0x4c:
            local_3c = local_3c + '\x01';
            param_2 = pbVar6;
            break;
          case 0x68:
            local_3c = local_3c + -1;
            local_18 = local_18 + -1;
            param_2 = pbVar6;
            break;
          case 0x6c:
            local_3c = local_3c + '\x01';
          case 0x77:
            local_18 = local_18 + '\x01';
            param_2 = pbVar6;
          }
        }
        else {
          local_1ec = local_1ec + 1;
          local_20 = (local_10 - 0x30) + local_20 * 10;
          param_2 = pbVar6;
        }
        goto LAB_004a2885;
      }
      if (local_74 == '\0') {
        local_1d8 = param_3;
        local_40 = (WCHAR *)*param_3;
        param_3 = param_3 + 1;
      }
      local_1c = '\0';
      if (local_18 == '\0') {
        if ((*param_2 == 0x53) || (*param_2 == 0x43)) {
          local_18 = '\x01';
        }
        else {
          local_18 = -1;
        }
      }
      local_10 = *param_2 | 0x20;
      if (local_10 != 0x6e) {
        if ((local_10 == 99) || (local_10 == 0x7b)) {
          local_24 = local_24 + 1;
          local_1dc = __inc(param_1);
        }
        else {
          local_1dc = __whiteout(&local_24,param_1);
        }
      }
      if ((local_1ec != 0) && (local_20 == 0)) {
        local_24 = local_24 + -1;
        FUN_004a3bb0(local_1dc,param_1);
        goto LAB_004a39fa;
      }
      pbVar6 = param_2;
      switch(local_10) {
      case 99:
        if (local_1ec == 0) {
          local_1ec = 1;
          local_20 = local_20 + 1;
        }
        if ('\0' < local_18) {
          local_68 = local_68 + '\x01';
        }
        local_1e4 = &DAT_004c7730;
        local_14 = local_14 - 1;
        goto LAB_004a2b90;
      case 100:
      case 0x6f:
      case 0x75:
        goto switchD_004a2ad4_caseD_64;
      case 0x65:
      case 0x66:
      case 0x67:
        local_1e4 = &local_1d4;
        if (local_1dc == 0x2d) {
          local_1d4 = 0x2d;
          local_1e4 = local_1d3;
LAB_004a34bf:
          local_20 = local_20 + -1;
          local_24 = local_24 + 1;
          local_1dc = __inc(param_1);
        }
        else if (local_1dc == 0x2b) goto LAB_004a34bf;
        if ((local_1ec == 0) || (0x15d < local_20)) {
          local_20 = 0x15d;
        }
        while( true ) {
          if ((int)DAT_004c71e8 < 2) {
            local_21c = *(ushort *)(PTR_DAT_004c6fdc + local_1dc * 2) & 4;
          }
          else {
            local_21c = FUN_0049c240(local_1dc,4);
          }
          if ((local_21c == 0) ||
             (iVar4 = local_20 + -1, bVar7 = local_20 == 0, local_20 = iVar4, bVar7)) break;
          local_70 = local_70 + 1;
          *local_1e4 = (byte)local_1dc;
          local_1e4 = local_1e4 + 1;
          local_24 = local_24 + 1;
          local_1dc = __inc(param_1);
        }
        if ((DAT_004c71ec == (byte)local_1dc) &&
           (iVar4 = local_20 + -1, bVar7 = local_20 != 0, local_20 = iVar4, bVar7)) {
          local_24 = local_24 + 1;
          local_1dc = __inc(param_1);
          *local_1e4 = DAT_004c71ec;
          local_1e4 = local_1e4 + 1;
          while( true ) {
            if ((int)DAT_004c71e8 < 2) {
              local_220 = *(ushort *)(PTR_DAT_004c6fdc + local_1dc * 2) & 4;
            }
            else {
              local_220 = FUN_0049c240(local_1dc,4);
            }
            if ((local_220 == 0) ||
               (iVar4 = local_20 + -1, bVar7 = local_20 == 0, local_20 = iVar4, bVar7)) break;
            local_70 = local_70 + 1;
            *local_1e4 = (byte)local_1dc;
            local_1e4 = local_1e4 + 1;
            local_24 = local_24 + 1;
            local_1dc = __inc(param_1);
          }
        }
        if ((local_70 != 0) &&
           (((local_1dc == 0x65 || (local_1dc == 0x45)) &&
            (iVar4 = local_20 + -1, bVar7 = local_20 != 0, local_20 = iVar4, bVar7)))) {
          *local_1e4 = 0x65;
          local_1e4 = local_1e4 + 1;
          local_24 = local_24 + 1;
          local_1dc = __inc(param_1);
          if (local_1dc == 0x2d) {
            *local_1e4 = 0x2d;
            local_1e4 = local_1e4 + 1;
LAB_004a3727:
            if (local_20 != 0) {
              local_24 = local_24 + 1;
              local_20 = local_20 + -1;
              local_1dc = __inc(param_1);
            }
          }
          else if (local_1dc == 0x2b) goto LAB_004a3727;
          while( true ) {
            if ((int)DAT_004c71e8 < 2) {
              local_224 = *(ushort *)(PTR_DAT_004c6fdc + local_1dc * 2) & 4;
            }
            else {
              local_224 = FUN_0049c240(local_1dc,4);
            }
            if ((local_224 == 0) ||
               (iVar4 = local_20 + -1, bVar7 = local_20 == 0, local_20 = iVar4, bVar7)) break;
            local_70 = local_70 + 1;
            *local_1e4 = (byte)local_1dc;
            local_1e4 = local_1e4 + 1;
            local_24 = local_24 + 1;
            local_1dc = __inc(param_1);
          }
        }
        local_24 = local_24 + -1;
        FUN_004a3bb0(local_1dc,param_1);
        if (local_70 == 0) goto LAB_004a39fa;
        if (local_74 == '\0') {
          local_38 = local_38 + 1;
          *local_1e4 = 0;
          (*(code *)PTR___fptrap_004c7210)(local_3c + -1,local_40,&local_1d4);
        }
        break;
      default:
        if (*param_2 != local_1dc) {
          local_24 = local_24 + -1;
          FUN_004a3bb0(local_1dc,param_1);
          goto LAB_004a39fa;
        }
        local_2c = local_2c + -1;
        if (local_74 == '\0') {
          param_3 = local_1d8;
        }
        break;
      case 0x69:
        local_10 = 100;
      case 0x78:
        if (local_1dc == 0x2d) {
          local_6c = local_6c + '\x01';
LAB_004a2f2f:
          local_20 = local_20 + -1;
          if ((local_20 == 0) && (local_1ec != 0)) {
            local_1c = local_1c + '\x01';
          }
          else {
            local_24 = local_24 + 1;
            local_1dc = __inc(param_1);
          }
        }
        else if (local_1dc == 0x2b) goto LAB_004a2f2f;
        if (local_1dc == 0x30) {
          local_24 = local_24 + 1;
          local_1dc = __inc(param_1);
          if (((byte)local_1dc == 'x') || ((byte)local_1dc == 'X')) {
            local_24 = local_24 + 1;
            local_1dc = __inc(param_1);
            local_10 = 0x78;
          }
          else {
            local_70 = local_70 + 1;
            if (local_10 == 0x78) {
              local_24 = local_24 + -1;
              FUN_004a3bb0(local_1dc,param_1);
              local_1dc = 0x30;
            }
            else {
              local_10 = 0x6f;
            }
          }
        }
        goto LAB_004a306e;
      case 0x6e:
        local_44 = local_24;
        if (local_74 != '\0') break;
        goto LAB_004a3431;
      case 0x70:
        local_3c = '\x01';
switchD_004a2ad4_caseD_64:
        if (local_1dc == 0x2d) {
          local_6c = local_6c + '\x01';
LAB_004a3031:
          local_20 = local_20 + -1;
          if ((local_20 == 0) && (local_1ec != 0)) {
            local_1c = local_1c + '\x01';
          }
          else {
            local_24 = local_24 + 1;
            local_1dc = __inc(param_1);
          }
        }
        else if (local_1dc == 0x2b) goto LAB_004a3031;
LAB_004a306e:
        if (local_1e0 == 0) {
          while (local_1c == '\0') {
            if ((local_10 == 0x78) || (local_10 == 0x70)) {
              if ((int)DAT_004c71e8 < 2) {
                local_214 = *(ushort *)(PTR_DAT_004c6fdc + local_1dc * 2) & 0x80;
              }
              else {
                local_214 = FUN_0049c240(local_1dc,0x80);
              }
              if (local_214 == 0) {
                local_1c = local_1c + '\x01';
              }
              else {
                local_44 = local_44 << 4;
                local_1dc = FUN_004a3af0(local_1dc);
              }
            }
            else {
              if ((int)DAT_004c71e8 < 2) {
                local_218 = *(ushort *)(PTR_DAT_004c6fdc + local_1dc * 2) & 4;
              }
              else {
                local_218 = FUN_0049c240(local_1dc,4);
              }
              if (local_218 == 0) {
                local_1c = local_1c + '\x01';
              }
              else if (local_10 == 0x6f) {
                if ((int)local_1dc < 0x38) {
                  local_44 = local_44 << 3;
                }
                else {
                  local_1c = local_1c + '\x01';
                }
              }
              else {
                local_44 = local_44 * 10;
              }
            }
            if (local_1c == '\0') {
              local_70 = local_70 + 1;
              local_44 = local_44 + -0x30 + local_1dc;
              if ((local_1ec == 0) || (local_20 = local_20 + -1, local_20 != 0)) {
                local_24 = local_24 + 1;
                local_1dc = __inc(param_1);
              }
              else {
                local_1c = '\x01';
              }
            }
            else {
              local_24 = local_24 + -1;
              FUN_004a3bb0(local_1dc,param_1);
            }
          }
          if (local_6c != '\0') {
            local_44 = -local_44;
          }
        }
        else {
          while (local_1c == '\0') {
            if (local_10 == 0x78) {
              if ((int)DAT_004c71e8 < 2) {
                local_20c = *(ushort *)(PTR_DAT_004c6fdc + local_1dc * 2) & 0x80;
              }
              else {
                local_20c = FUN_0049c240(local_1dc,0x80);
              }
              if (local_20c == 0) {
                local_1c = local_1c + '\x01';
              }
              else {
                local_34 = __allshl(4,local_34._4_4_);
                local_1dc = FUN_004a3af0(local_1dc);
              }
            }
            else {
              if ((int)DAT_004c71e8 < 2) {
                local_210 = *(ushort *)(PTR_DAT_004c6fdc + local_1dc * 2) & 4;
              }
              else {
                local_210 = FUN_0049c240(local_1dc,4);
              }
              if (local_210 == 0) {
                local_1c = local_1c + '\x01';
              }
              else if (local_10 == 0x6f) {
                if ((int)local_1dc < 0x38) {
                  local_34 = __allshl(3,local_34._4_4_);
                }
                else {
                  local_1c = local_1c + '\x01';
                }
              }
              else {
                lVar8 = __allshl(2,local_34._4_4_);
                local_34 = __allshl(1,(int)((ulonglong)lVar8 >> 0x20) + local_34._4_4_ +
                                      (uint)CARRY4((uint)lVar8,(uint)local_34));
              }
            }
            if (local_1c == '\0') {
              local_70 = local_70 + 1;
              uVar5 = local_1dc - 0x30;
              local_34 = CONCAT44(local_34._4_4_ + ((int)uVar5 >> 0x1f) +
                                  (uint)CARRY4((uint)local_34,uVar5),(uint)local_34 + uVar5);
              if ((local_1ec == 0) || (local_20 = local_20 + -1, local_20 != 0)) {
                local_24 = local_24 + 1;
                local_1dc = __inc(param_1);
              }
              else {
                local_1c = '\x01';
              }
            }
            else {
              local_24 = local_24 + -1;
              FUN_004a3bb0(local_1dc,param_1);
            }
          }
          if (local_6c != '\0') {
            local_34 = CONCAT44(-(local_34._4_4_ + (uint)((uint)local_34 != 0)),-(uint)local_34);
          }
        }
        if (local_10 == 0x46) {
          local_70 = 0;
        }
        if (local_70 == 0) goto LAB_004a39fa;
        if (local_74 == '\0') {
          local_38 = local_38 + 1;
LAB_004a3431:
          if (local_1e0 == 0) {
            if (local_3c == '\0') {
              *local_40 = (WCHAR)local_44;
            }
            else {
              *(int *)local_40 = local_44;
            }
          }
          else {
            *(uint *)local_40 = (uint)local_34;
            *(int *)(local_40 + 2) = local_34._4_4_;
          }
        }
        break;
      case 0x73:
        if ('\0' < local_18) {
          local_68 = local_68 + '\x01';
        }
        local_1e4 = (byte *)s_____004c7728;
        local_14 = local_14 - 1;
        goto LAB_004a2b90;
      case 0x7b:
        if ('\0' < local_18) {
          local_68 = local_68 + '\x01';
        }
        pbVar6 = param_2 + 1;
        local_1e4 = pbVar6;
        if (*pbVar6 == 0x5e) {
          local_1e4 = param_2 + 2;
          local_14 = local_14 - 1;
        }
LAB_004a2b90:
        param_2 = pbVar6;
        _memset(local_64,0,0x20);
        if ((local_10 == 0x7b) && (*local_1e4 == 0x5d)) {
          local_c = CONCAT31(local_c._1_3_,0x5d);
          local_59 = 0x20;
          local_1e4 = local_1e4 + 1;
        }
        while (*local_1e4 != 0x5d) {
          bVar1 = *local_1e4;
          local_1f0 = CONCAT31(local_1f0._1_3_,bVar1);
          pbVar6 = local_1e4 + 1;
          if (((bVar1 == 0x2d) && ((local_c & 0xff) != 0)) && (*pbVar6 != 0x5d)) {
            bVar1 = *pbVar6;
            local_1e4 = local_1e4 + 2;
            if ((uint)bVar1 <= (local_c & 0xff)) {
              bVar3 = (byte)local_c;
              local_c = CONCAT31(local_c._1_3_,bVar1);
              bVar1 = bVar3;
            }
            local_28 = CONCAT31(local_28._1_3_,bVar1);
            for (local_1f0 = CONCAT31(local_1f0._1_3_,(byte)local_c);
                (local_1f0 & 0xff) <= (local_28 & 0xff);
                local_1f0 = CONCAT31(local_1f0._1_3_,(byte)local_1f0 + 1)) {
              local_64[(int)(local_1f0 & 0xff) >> 3] =
                   local_64[(int)(local_1f0 & 0xff) >> 3] | (byte)(1 << ((byte)local_1f0 & 7));
            }
            local_c = local_c & 0xffffff00;
          }
          else {
            local_c = CONCAT31(local_c._1_3_,bVar1);
            local_64[(int)(uint)bVar1 >> 3] =
                 local_64[(int)(uint)bVar1 >> 3] | (byte)(1 << (bVar1 & 7));
            local_1e4 = pbVar6;
          }
        }
        if (*local_1e4 == 0) goto LAB_004a39fa;
        if (local_10 == 0x7b) {
          param_2 = local_1e4;
        }
        local_1e8 = local_40;
        local_24 = local_24 + -1;
        FUN_004a3bb0(local_1dc,param_1);
        while( true ) {
          if ((local_1ec != 0) &&
             (iVar4 = local_20 + -1, bVar7 = local_20 == 0, local_20 = iVar4, bVar7))
          goto LAB_004a2ec5;
          local_24 = local_24 + 1;
          local_1dc = __inc(param_1);
          if ((local_1dc == 0xffffffff) ||
             (bVar1 = (byte)local_1dc,
             ((int)(char)(local_64[(int)local_1dc >> 3] ^ local_14) & 1 << (bVar1 & 7)) == 0))
          break;
          if (local_74 == '\0') {
            if (local_68 == '\0') {
              *(byte *)local_40 = bVar1;
              local_40 = (WCHAR *)((int)local_40 + 1);
            }
            else {
              local_1f4 = bVar1;
              if ((*(ushort *)(PTR_DAT_004c6fdc + (local_1dc & 0xff) * 2) & 0x8000) != 0) {
                local_24 = local_24 + 1;
                uVar5 = __inc(param_1);
                local_1f3 = (undefined1)uVar5;
              }
              FUN_004a8840(local_8,&local_1f4,DAT_004c71e8);
              *local_40 = local_8[0];
              local_40 = local_40 + 1;
            }
          }
          else {
            local_1e8 = (WCHAR *)((int)local_1e8 + 1);
          }
        }
        local_24 = local_24 + -1;
        FUN_004a3bb0(local_1dc,param_1);
LAB_004a2ec5:
        if (local_1e8 == local_40) goto LAB_004a39fa;
        if ((local_74 == '\0') && (local_38 = local_38 + 1, local_10 != 99)) {
          if (local_68 == '\0') {
            *(byte *)local_40 = 0;
          }
          else {
            *local_40 = L'\0';
          }
        }
      }
      local_2c = local_2c + '\x01';
      pbVar6 = param_2 + 1;
    }
    else {
      local_24 = local_24 + 1;
      bVar1 = *param_2;
      local_1dc = __inc(param_1);
      if (bVar1 != local_1dc) {
        local_24 = local_24 + -1;
        FUN_004a3bb0(local_1dc,param_1);
        goto LAB_004a39fa;
      }
      pbVar6 = param_2 + 1;
      if ((*(ushort *)(PTR_DAT_004c6fdc + (local_1dc & 0xff) * 2) & 0x8000) != 0) {
        local_24 = local_24 + 1;
        bVar1 = param_2[1];
        uVar5 = __inc(param_1);
        if (bVar1 == uVar5) {
          local_24 = local_24 + -1;
          pbVar6 = param_2 + 2;
          goto LAB_004a39d1;
        }
        local_24 = local_24 + -1;
        FUN_004a3bb0(uVar5,param_1);
        local_24 = local_24 + -1;
        FUN_004a3bb0(local_1dc,param_1);
        goto LAB_004a39fa;
      }
    }
LAB_004a39d1:
    param_2 = pbVar6;
    if ((local_1dc == 0xffffffff) && ((*param_2 != 0x25 || (param_2[1] != 0x6e))))
    goto LAB_004a39fa;
  } while( true );
}

