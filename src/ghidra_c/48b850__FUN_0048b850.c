/* FUN_0048b850 @ 0048b850 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0048b850(int param_1,int param_2,int param_3,int param_4)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  uint uVar4;
  char cVar5;
  int iVar6;
  undefined4 *puVar7;
  longlong lVar8;
  undefined4 local_b0 [16];
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
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
  
  puVar7 = local_b0;
  for (iVar6 = 0x2b; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar7 = 0xcccccccc;
    puVar7 = puVar7 + 1;
  }
  *(uint *)(param_2 + param_4 * 0x28) = *(uint *)(param_2 + param_4 * 0x28) & 0xffffff | 0x9000000;
  *(undefined1 *)(param_2 + 7 + param_4 * 0x28) = 0x2c;
  *(uint *)(param_2 + 4 + param_4 * 0x28) = *(uint *)(param_1 + 0xc + param_4 * 0x18) & 0x3fffffff;
  local_8 = (uint)*(ushort *)(param_3 + (uint)*(ushort *)(param_1 + 8 + param_4 * 0x18) * 4);
  uVar3 = FUN_00470bd0(local_8);
  *(short *)(param_2 + 0x16 + param_4 * 0x28) = (short)uVar3;
  *(ushort *)(param_2 + 0x16 + param_4 * 0x28) =
       *(ushort *)(param_2 + 0x16 + param_4 * 0x28) |
       (ushort)((int)(*(byte *)(param_1 + 0xf + param_4 * 0x18) & 0xc0) >> 1);
  uVar3 = FUN_00470c20(local_8);
  *(short *)(param_2 + 0xe + param_4 * 0x28) = (short)uVar3;
  if ((local_8 == 0x5f) && (DAT_004be3d4 == 7)) {
    local_c = local_c & 0xffffff00;
  }
  local_c = CONCAT31(local_c._1_3_,*(undefined1 *)(param_1 + 0x10 + param_4 * 0x18));
  local_1c = CONCAT31(local_1c._1_3_,*(undefined1 *)(param_1 + 0x11 + param_4 * 0x18));
  local_10 = CONCAT31(local_10._1_3_,*(undefined1 *)(param_1 + 0x12 + param_4 * 0x18));
  local_20 = CONCAT31(local_20._1_3_,*(undefined1 *)(param_1 + 0x13 + param_4 * 0x18));
  local_14 = CONCAT31(local_14._1_3_,*(undefined1 *)(param_1 + 0x14 + param_4 * 0x18));
  local_24 = CONCAT31(local_24._1_3_,*(undefined1 *)(param_1 + 0x15 + param_4 * 0x18));
  local_18 = CONCAT31(local_18._1_3_,*(undefined1 *)(param_1 + 0x16 + param_4 * 0x18));
  local_28 = CONCAT31(local_28._1_3_,*(undefined1 *)(param_1 + 0x17 + param_4 * 0x18));
  uVar4 = FUN_0047d760(local_8);
  if ((uVar4 & 0xff) != 0) {
    cVar5 = (char)((int)((local_c & 0xff) + (local_10 & 0xff) + (local_14 & 0xff) +
                        (local_18 & 0xff)) >> 2);
    _local_2c = CONCAT31(uStack_2b,cVar5);
    _local_30 = CONCAT31(uStack_2f,
                         (char)((int)((local_1c & 0xff) + (local_20 & 0xff) + (local_24 & 0xff) +
                                     (local_28 & 0xff)) >> 2));
    uVar1 = (ushort)_local_2c;
    local_38 = ((ushort)local_c & 0xff) - (uVar1 & 0xff);
    uVar2 = (ushort)_local_30;
    local_36 = ((ushort)local_1c & 0xff) - (uVar2 & 0xff);
    local_40 = ((ushort)local_10 & 0xff) - (uVar1 & 0xff);
    local_3e = ((ushort)local_20 & 0xff) - (uVar2 & 0xff);
    local_48 = ((ushort)local_14 & 0xff) - (uVar1 & 0xff);
    local_46 = ((ushort)local_24 & 0xff) - (uVar2 & 0xff);
    local_50 = ((ushort)local_18 & 0xff) - (uVar1 & 0xff);
    local_4e = ((ushort)local_28 & 0xff) - (uVar2 & 0xff);
    local_54 = (int)local_38;
    lVar8 = __ftol();
    local_c = CONCAT31(local_c._1_3_,cVar5 + (char)lVar8);
    cVar5 = (char)_local_30;
    local_58 = (int)local_36;
    lVar8 = __ftol();
    local_1c = CONCAT31(local_1c._1_3_,cVar5 + (char)lVar8);
    cVar5 = (char)_local_2c;
    local_5c = (int)local_40;
    lVar8 = __ftol();
    local_10 = CONCAT31(local_10._1_3_,cVar5 + (char)lVar8);
    cVar5 = (char)_local_30;
    local_60 = (int)local_3e;
    lVar8 = __ftol();
    local_20 = CONCAT31(local_20._1_3_,cVar5 + (char)lVar8);
    cVar5 = (char)_local_2c;
    local_64 = (int)local_48;
    lVar8 = __ftol();
    local_14 = CONCAT31(local_14._1_3_,cVar5 + (char)lVar8);
    cVar5 = (char)_local_30;
    local_68 = (int)local_46;
    lVar8 = __ftol();
    local_24 = CONCAT31(local_24._1_3_,cVar5 + (char)lVar8);
    cVar5 = (char)_local_2c;
    local_6c = (int)local_50;
    lVar8 = __ftol();
    local_18 = CONCAT31(local_18._1_3_,cVar5 + (char)lVar8);
    cVar5 = (char)_local_30;
    local_70 = (int)local_4e;
    lVar8 = __ftol();
    local_28 = CONCAT31(local_28._1_3_,cVar5 + (char)lVar8);
  }
  *(undefined1 *)(param_2 + 0xc + param_4 * 0x28) = (undefined1)local_c;
  *(undefined1 *)(param_2 + 0xd + param_4 * 0x28) = (undefined1)local_1c;
  *(undefined1 *)(param_2 + 0x14 + param_4 * 0x28) = (undefined1)local_10;
  *(undefined1 *)(param_2 + 0x15 + param_4 * 0x28) = (undefined1)local_20;
  *(undefined1 *)(param_2 + 0x1c + param_4 * 0x28) = (undefined1)local_14;
  *(undefined1 *)(param_2 + 0x1d + param_4 * 0x28) = (undefined1)local_24;
  *(undefined1 *)(param_2 + 0x24 + param_4 * 0x28) = (undefined1)local_18;
  *(undefined1 *)(param_2 + 0x25 + param_4 * 0x28) = (undefined1)local_28;
  local_8 = 0x48bcda;
  __chkesp();
  return;
}

