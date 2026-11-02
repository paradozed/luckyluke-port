/* FUN_0048b340 @ 0048b340 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0048b340(int param_1,int param_2,int param_3,int param_4)

{
  char cVar1;
  ushort uVar2;
  ushort uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  char cVar7;
  undefined4 *puVar8;
  longlong lVar9;
  undefined4 local_c0 [16];
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  short local_60;
  short local_5c;
  ushort local_58 [2];
  ushort local_54 [2];
  short local_50;
  short local_4e;
  short local_48;
  short local_46;
  short local_40;
  short local_3e;
  short local_38;
  short local_36;
  undefined1 local_30;
  undefined3 uStack_2f;
  char local_2c;
  undefined3 uStack_2b;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  puVar8 = local_c0;
  for (iVar6 = 0x2f; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar8 = 0xcccccccc;
    puVar8 = puVar8 + 1;
  }
  *(uint *)(param_2 + param_4 * 0x28) = *(uint *)(param_2 + param_4 * 0x28) & 0xffffff | 0x9000000;
  *(undefined1 *)(param_2 + 7 + param_4 * 0x28) = 0x2c;
  *(uint *)(param_2 + 4 + param_4 * 0x28) = *(uint *)(param_1 + 0xc + param_4 * 0x18) & 0x3fffffff;
  local_8 = (uint)*(ushort *)(param_3 + (uint)*(ushort *)(param_1 + 8 + param_4 * 0x18) * 4);
  uVar4 = FUN_00470bd0(local_8);
  *(short *)(param_2 + 0x16 + param_4 * 0x28) = (short)uVar4;
  *(ushort *)(param_2 + 0x16 + param_4 * 0x28) =
       *(ushort *)(param_2 + 0x16 + param_4 * 0x28) |
       (ushort)((int)(*(byte *)(param_1 + 0xf + param_4 * 0x18) & 0xc0) >> 1);
  uVar4 = FUN_00470c20(local_8);
  *(short *)(param_2 + 0xe + param_4 * 0x28) = (short)uVar4;
  FUN_00470c70(local_8,(undefined1 *)local_54,(undefined1 *)local_58);
  local_5c = *(short *)(param_2 + 0x1e + param_4 * 0x28) - (local_54[0] & 0xff);
  local_60 = *(short *)(param_2 + 0x26 + param_4 * 0x28) - (local_58[0] & 0xff);
  cVar7 = (char)local_5c;
  local_c = CONCAT31(local_c._1_3_,*(char *)(param_1 + 0x10 + param_4 * 0x18) + cVar7);
  cVar1 = (char)local_60;
  local_1c = CONCAT31(local_1c._1_3_,*(char *)(param_1 + 0x11 + param_4 * 0x18) + cVar1);
  local_10 = CONCAT31(local_10._1_3_,*(char *)(param_1 + 0x12 + param_4 * 0x18) + cVar7);
  local_20 = CONCAT31(local_20._1_3_,*(char *)(param_1 + 0x13 + param_4 * 0x18) + cVar1);
  local_14 = CONCAT31(local_14._1_3_,*(char *)(param_1 + 0x14 + param_4 * 0x18) + cVar7);
  local_24 = CONCAT31(local_24._1_3_,*(char *)(param_1 + 0x15 + param_4 * 0x18) + cVar1);
  local_18 = CONCAT31(local_18._1_3_,*(char *)(param_1 + 0x16 + param_4 * 0x18) + cVar7);
  local_28 = CONCAT31(local_28._1_3_,*(char *)(param_1 + 0x17 + param_4 * 0x18) + cVar1);
  uVar5 = FUN_0047d760(local_8);
  if ((uVar5 & 0xff) != 0) {
    cVar7 = (char)((int)((local_c & 0xff) + (local_10 & 0xff) + (local_14 & 0xff) +
                        (local_18 & 0xff)) >> 2);
    _local_2c = CONCAT31(uStack_2b,cVar7);
    _local_30 = CONCAT31(uStack_2f,
                         (char)((int)((local_1c & 0xff) + (local_20 & 0xff) + (local_24 & 0xff) +
                                     (local_28 & 0xff)) >> 2));
    uVar2 = (ushort)_local_2c;
    local_38 = ((ushort)local_c & 0xff) - (uVar2 & 0xff);
    uVar3 = (ushort)_local_30;
    local_36 = ((ushort)local_1c & 0xff) - (uVar3 & 0xff);
    local_40 = ((ushort)local_10 & 0xff) - (uVar2 & 0xff);
    local_3e = ((ushort)local_20 & 0xff) - (uVar3 & 0xff);
    local_48 = ((ushort)local_14 & 0xff) - (uVar2 & 0xff);
    local_46 = ((ushort)local_24 & 0xff) - (uVar3 & 0xff);
    local_50 = ((ushort)local_18 & 0xff) - (uVar2 & 0xff);
    local_4e = ((ushort)local_28 & 0xff) - (uVar3 & 0xff);
    local_64 = (int)local_38;
    lVar9 = __ftol();
    local_c = CONCAT31(local_c._1_3_,cVar7 + (char)lVar9);
    cVar7 = (char)_local_30;
    local_68 = (int)local_36;
    lVar9 = __ftol();
    local_1c = CONCAT31(local_1c._1_3_,cVar7 + (char)lVar9);
    cVar7 = (char)_local_2c;
    local_6c = (int)local_40;
    lVar9 = __ftol();
    local_10 = CONCAT31(local_10._1_3_,cVar7 + (char)lVar9);
    cVar7 = (char)_local_30;
    local_70 = (int)local_3e;
    lVar9 = __ftol();
    local_20 = CONCAT31(local_20._1_3_,cVar7 + (char)lVar9);
    cVar7 = (char)_local_2c;
    local_74 = (int)local_48;
    lVar9 = __ftol();
    local_14 = CONCAT31(local_14._1_3_,cVar7 + (char)lVar9);
    cVar7 = (char)_local_30;
    local_78 = (int)local_46;
    lVar9 = __ftol();
    local_24 = CONCAT31(local_24._1_3_,cVar7 + (char)lVar9);
    cVar7 = (char)_local_2c;
    local_7c = (int)local_50;
    lVar9 = __ftol();
    local_18 = CONCAT31(local_18._1_3_,cVar7 + (char)lVar9);
    cVar7 = (char)_local_30;
    local_80 = (int)local_4e;
    lVar9 = __ftol();
    local_28 = CONCAT31(local_28._1_3_,cVar7 + (char)lVar9);
  }
  *(undefined1 *)(param_2 + 0xc + param_4 * 0x28) = (undefined1)local_c;
  *(undefined1 *)(param_2 + 0xd + param_4 * 0x28) = (undefined1)local_1c;
  *(undefined1 *)(param_2 + 0x14 + param_4 * 0x28) = (undefined1)local_10;
  *(undefined1 *)(param_2 + 0x15 + param_4 * 0x28) = (undefined1)local_20;
  *(undefined1 *)(param_2 + 0x1c + param_4 * 0x28) = (undefined1)local_14;
  *(undefined1 *)(param_2 + 0x1d + param_4 * 0x28) = (undefined1)local_24;
  *(undefined1 *)(param_2 + 0x24 + param_4 * 0x28) = (undefined1)local_18;
  *(undefined1 *)(param_2 + 0x25 + param_4 * 0x28) = (undefined1)local_28;
  local_8 = 0x48b842;
  __chkesp();
  return;
}

