/* FUN_0048d190 @ 0048d190 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0048d190(int param_1,int param_2,int param_3,int param_4)

{
  ushort uVar1;
  ushort uVar2;
  char cVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  longlong lVar8;
  undefined4 local_98 [16];
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  short local_40;
  short local_3e;
  short local_38;
  short local_36;
  short local_30;
  short local_2e;
  undefined1 local_28;
  undefined3 uStack_27;
  char local_24;
  undefined3 uStack_23;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  puVar7 = local_98;
  for (iVar6 = 0x25; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar7 = 0xcccccccc;
    puVar7 = puVar7 + 1;
  }
  *(uint *)(param_2 + param_4 * 0x20) = *(uint *)(param_2 + param_4 * 0x20) & 0xffffff | 0x7000000;
  *(undefined1 *)(param_2 + 7 + param_4 * 0x20) = 0x24;
  *(uint *)(param_2 + 4 + param_4 * 0x20) = *(uint *)(param_1 + 8 + param_4 * 0x14) & 0x3fffffff;
  local_8 = (uint)*(ushort *)(param_3 + (uint)*(ushort *)(param_1 + 6 + param_4 * 0x14) * 4);
  uVar4 = FUN_00470bd0(local_8);
  *(short *)(param_2 + 0x16 + param_4 * 0x20) = (short)uVar4;
  *(ushort *)(param_2 + 0x16 + param_4 * 0x20) =
       *(ushort *)(param_2 + 0x16 + param_4 * 0x20) |
       (ushort)((int)(*(byte *)(param_1 + 0xb + param_4 * 0x14) & 0xc0) >> 1);
  uVar4 = FUN_00470c20(local_8);
  *(short *)(param_2 + 0xe + param_4 * 0x20) = (short)uVar4;
  if ((local_8 == 0x5f) && (DAT_004be3d4 == 7)) {
    local_c = local_c & 0xffffff00;
  }
  local_c = CONCAT31(local_c._1_3_,*(undefined1 *)(param_1 + 0xc + param_4 * 0x14));
  local_18 = CONCAT31(local_18._1_3_,*(undefined1 *)(param_1 + 0xd + param_4 * 0x14));
  local_10 = CONCAT31(local_10._1_3_,*(undefined1 *)(param_1 + 0xe + param_4 * 0x14));
  local_1c = CONCAT31(local_1c._1_3_,*(undefined1 *)(param_1 + 0xf + param_4 * 0x14));
  local_14 = CONCAT31(local_14._1_3_,*(undefined1 *)(param_1 + 0x10 + param_4 * 0x14));
  local_20 = CONCAT31(local_20._1_3_,*(undefined1 *)(param_1 + 0x11 + param_4 * 0x14));
  uVar5 = FUN_0047d760(local_8);
  if ((uVar5 & 0xff) != 0) {
    cVar3 = (char)((ulonglong)((local_c & 0xff) + (local_10 & 0xff) + (local_14 & 0xff)) / 3);
    _local_24 = CONCAT31(uStack_23,cVar3);
    _local_28 = CONCAT31(uStack_27,
                         (char)((ulonglong)
                                ((local_18 & 0xff) + (local_1c & 0xff) + (local_20 & 0xff)) / 3));
    uVar1 = (ushort)_local_24;
    local_30 = ((ushort)local_c & 0xff) - (uVar1 & 0xff);
    uVar2 = (ushort)_local_28;
    local_2e = ((ushort)local_18 & 0xff) - (uVar2 & 0xff);
    local_38 = ((ushort)local_10 & 0xff) - (uVar1 & 0xff);
    local_36 = ((ushort)local_1c & 0xff) - (uVar2 & 0xff);
    local_40 = ((ushort)local_14 & 0xff) - (uVar1 & 0xff);
    local_3e = ((ushort)local_20 & 0xff) - (uVar2 & 0xff);
    local_44 = (int)local_30;
    lVar8 = __ftol();
    local_c = CONCAT31(local_c._1_3_,cVar3 + (char)lVar8);
    cVar3 = (char)_local_28;
    local_48 = (int)local_2e;
    lVar8 = __ftol();
    local_18 = CONCAT31(local_18._1_3_,cVar3 + (char)lVar8);
    cVar3 = (char)_local_24;
    local_4c = (int)local_38;
    lVar8 = __ftol();
    local_10 = CONCAT31(local_10._1_3_,cVar3 + (char)lVar8);
    cVar3 = (char)_local_28;
    local_50 = (int)local_36;
    lVar8 = __ftol();
    local_1c = CONCAT31(local_1c._1_3_,cVar3 + (char)lVar8);
    cVar3 = (char)_local_24;
    local_54 = (int)local_40;
    lVar8 = __ftol();
    local_14 = CONCAT31(local_14._1_3_,cVar3 + (char)lVar8);
    cVar3 = (char)_local_28;
    local_58 = (int)local_3e;
    lVar8 = __ftol();
    local_20 = CONCAT31(local_20._1_3_,cVar3 + (char)lVar8);
  }
  *(undefined1 *)(param_2 + 0xc + param_4 * 0x20) = (undefined1)local_c;
  *(undefined1 *)(param_2 + 0xd + param_4 * 0x20) = (undefined1)local_18;
  *(undefined1 *)(param_2 + 0x14 + param_4 * 0x20) = (undefined1)local_10;
  *(undefined1 *)(param_2 + 0x15 + param_4 * 0x20) = (undefined1)local_1c;
  *(undefined1 *)(param_2 + 0x1c + param_4 * 0x20) = (undefined1)local_14;
  *(undefined1 *)(param_2 + 0x1d + param_4 * 0x20) = (undefined1)local_20;
  local_8 = 0x48d54f;
  __chkesp();
  return;
}

