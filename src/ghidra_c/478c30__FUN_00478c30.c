/* FUN_00478c30 @ 00478c30 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00478c30(int param_1)

{
  short sVar1;
  int *piVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 local_b0 [28];
  uint local_40;
  int local_38;
  int local_34;
  uint local_2c;
  ushort *local_28;
  int local_20;
  int *local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  puVar8 = local_b0;
  for (iVar5 = 0x2b; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar8 = 0xcccccccc;
    puVar8 = puVar8 + 1;
  }
  if ((DAT_004f555c != (int *)0x0) && (*DAT_004f555c != -0x22222223)) {
    for (local_8 = 0; local_8 < (int)(uint)*(ushort *)(DAT_004e89f0 + param_1 * 0x20);
        local_8 = local_8 + 1) {
      bVar3 = false;
      iVar5 = *(int *)(*(int *)(DAT_004e89f0 + 0x14 + param_1 * 0x20) + local_8 * 4);
      if (*(int *)(iVar5 + 8) == 0) {
        local_20 = iVar5 + *(int *)(iVar5 + 0x44);
      }
      else {
        local_20 = *(int *)(iVar5 + 8) + *(int *)(*(int *)(iVar5 + 8) + 0x44);
      }
      if (((DAT_004e8914 == 0x11) && (*(int *)(iVar5 + 0x10) == 0x5c)) &&
         (*(int *)(iVar5 + 0x2c) == 0x70)) {
        bVar3 = true;
      }
      local_28 = *(ushort **)(iVar5 + 0x30);
      local_34 = local_20 + 0x14;
      local_2c = 0;
      local_38 = *(int *)(iVar5 + 0x4c);
      do {
        switch(*local_28) {
        case 2:
          local_c = (uint)local_28[1];
          while (local_c = local_c - 1, -1 < (int)local_c) {
            if ((bVar3) && ((local_2c + local_c == 0x25 || (local_2c + local_c == 0xb)))) {
              local_40 = 0x20000;
            }
            else {
              local_40 = 0;
            }
            for (local_14 = DAT_004e8908; local_14 != (int *)0x0; local_14 = (int *)local_14[1]) {
              piVar2 = (int *)*local_14;
              sVar1 = *(short *)(*(int *)(iVar5 + 0x3c) +
                                (uint)*(ushort *)(local_34 + 6 + local_c * 0x14) * 4);
              for (local_10 = 0;
                  (piVar2 != (int *)0x0 && (local_10 < (int)(uint)*(ushort *)(piVar2 + 1)));
                  local_10 = local_10 + 1) {
                iVar6 = *(int *)(*piVar2 + local_10 * 4);
                if ((iVar6 != 0) && (sVar1 == *(short *)(*(int *)(iVar6 + 4) + 0x10))) {
                  iVar6 = *(int *)(DAT_004e89f0 + 0x18 + param_1 * 0x20);
                  *(uint *)(*(int *)(DAT_004e89f0 + 0x1c + param_1 * 0x20) + 8 + iVar6 * 0x14) =
                       local_c | local_40;
                  *(int *)(*(int *)(DAT_004e89f0 + 0x1c + param_1 * 0x20) + iVar6 * 0x14) = iVar5;
                  *(uint *)(*(int *)(DAT_004e89f0 + 0x1c + param_1 * 0x20) + 4 + iVar6 * 0x14) =
                       (uint)*local_28;
                  *(int *)(*(int *)(DAT_004e89f0 + 0x1c + param_1 * 0x20) + 0xc + iVar6 * 0x14) =
                       local_34;
                  *(int *)(*(int *)(DAT_004e89f0 + 0x1c + param_1 * 0x20) + 0x10 + iVar6 * 0x14) =
                       local_38;
                  *(int *)(DAT_004e89f0 + 0x18 + param_1 * 0x20) =
                       *(int *)(DAT_004e89f0 + 0x18 + param_1 * 0x20) + 1;
                }
              }
            }
          }
          break;
        case 3:
          local_c = (uint)local_28[1];
          while (local_c = local_c - 1, -1 < (int)local_c) {
            for (local_14 = DAT_004e8908; local_14 != (int *)0x0; local_14 = (int *)local_14[1]) {
              piVar2 = (int *)*local_14;
              uVar4 = (uint)*(ushort *)
                             (*(int *)(iVar5 + 0x3c) +
                             (uint)*(ushort *)(local_34 + 8 + local_c * 0x18) * 4);
              iVar7 = local_38 + local_c * 0x28;
              iVar6 = DAT_004d1e7c + uVar4 * 0x14;
              *(ushort *)(iVar7 + 0x1e) = (ushort)*(byte *)(iVar6 + 0x10);
              *(ushort *)(iVar7 + 0x26) = (ushort)*(byte *)(iVar6 + 0x11);
              for (local_10 = 0;
                  (piVar2 != (int *)0x0 && (local_10 < (int)(uint)*(ushort *)(piVar2 + 1)));
                  local_10 = local_10 + 1) {
                iVar6 = *(int *)(*piVar2 + local_10 * 4);
                if ((iVar6 != 0) && (uVar4 == *(ushort *)(*(int *)(iVar6 + 4) + 0x10))) {
                  iVar6 = *(int *)(DAT_004e89f0 + 0x18 + param_1 * 0x20);
                  *(uint *)(*(int *)(DAT_004e89f0 + 0x1c + param_1 * 0x20) + 8 + iVar6 * 0x14) =
                       local_c;
                  *(int *)(*(int *)(DAT_004e89f0 + 0x1c + param_1 * 0x20) + iVar6 * 0x14) = iVar5;
                  *(uint *)(*(int *)(DAT_004e89f0 + 0x1c + param_1 * 0x20) + 4 + iVar6 * 0x14) =
                       (uint)*local_28;
                  *(int *)(*(int *)(DAT_004e89f0 + 0x1c + param_1 * 0x20) + 0xc + iVar6 * 0x14) =
                       local_34;
                  *(int *)(*(int *)(DAT_004e89f0 + 0x1c + param_1 * 0x20) + 0x10 + iVar6 * 0x14) =
                       local_38;
                  *(int *)(DAT_004e89f0 + 0x18 + param_1 * 0x20) =
                       *(int *)(DAT_004e89f0 + 0x18 + param_1 * 0x20) + 1;
                }
              }
            }
          }
          break;
        case 6:
          local_c = (uint)local_28[1];
          while (local_c = local_c - 1, -1 < (int)local_c) {
            for (local_14 = DAT_004e8908; local_14 != (int *)0x0; local_14 = (int *)local_14[1]) {
              piVar2 = (int *)*local_14;
              sVar1 = *(short *)(*(int *)(iVar5 + 0x3c) +
                                (uint)*(ushort *)(local_34 + 0x14 + local_c * 0x1c) * 4);
              for (local_10 = 0;
                  (piVar2 != (int *)0x0 && (local_10 < (int)(uint)*(ushort *)(piVar2 + 1)));
                  local_10 = local_10 + 1) {
                iVar6 = *(int *)(*piVar2 + local_10 * 4);
                if ((iVar6 != 0) && (sVar1 == *(short *)(*(int *)(iVar6 + 4) + 0x10))) {
                  iVar6 = *(int *)(DAT_004e89f0 + 0x18 + param_1 * 0x20);
                  *(uint *)(*(int *)(DAT_004e89f0 + 0x1c + param_1 * 0x20) + 8 + iVar6 * 0x14) =
                       local_c;
                  *(int *)(*(int *)(DAT_004e89f0 + 0x1c + param_1 * 0x20) + iVar6 * 0x14) = iVar5;
                  *(uint *)(*(int *)(DAT_004e89f0 + 0x1c + param_1 * 0x20) + 4 + iVar6 * 0x14) =
                       (uint)*local_28;
                  *(int *)(*(int *)(DAT_004e89f0 + 0x1c + param_1 * 0x20) + 0xc + iVar6 * 0x14) =
                       local_34;
                  *(int *)(*(int *)(DAT_004e89f0 + 0x1c + param_1 * 0x20) + 0x10 + iVar6 * 0x14) =
                       local_38;
                  *(int *)(DAT_004e89f0 + 0x18 + param_1 * 0x20) =
                       *(int *)(DAT_004e89f0 + 0x18 + param_1 * 0x20) + 1;
                }
              }
            }
          }
          break;
        case 7:
          local_c = (uint)local_28[1];
          while (local_c = local_c - 1, -1 < (int)local_c) {
            for (local_14 = DAT_004e8908; local_14 != (int *)0x0; local_14 = (int *)local_14[1]) {
              piVar2 = (int *)*local_14;
              sVar1 = *(short *)(*(int *)(iVar5 + 0x3c) +
                                (uint)*(ushort *)(local_34 + 0x18 + local_c * 0x24) * 4);
              for (local_10 = 0;
                  (piVar2 != (int *)0x0 && (local_10 < (int)(uint)*(ushort *)(piVar2 + 1)));
                  local_10 = local_10 + 1) {
                iVar6 = *(int *)(*piVar2 + local_10 * 4);
                if ((iVar6 != 0) && (sVar1 == *(short *)(*(int *)(iVar6 + 4) + 0x10))) {
                  iVar6 = *(int *)(DAT_004e89f0 + 0x18 + param_1 * 0x20);
                  *(uint *)(*(int *)(DAT_004e89f0 + 0x1c + param_1 * 0x20) + 8 + iVar6 * 0x14) =
                       local_c;
                  *(int *)(*(int *)(DAT_004e89f0 + 0x1c + param_1 * 0x20) + iVar6 * 0x14) = iVar5;
                  *(uint *)(*(int *)(DAT_004e89f0 + 0x1c + param_1 * 0x20) + 4 + iVar6 * 0x14) =
                       (uint)*local_28;
                  *(int *)(*(int *)(DAT_004e89f0 + 0x1c + param_1 * 0x20) + 0xc + iVar6 * 0x14) =
                       local_34;
                  *(int *)(*(int *)(DAT_004e89f0 + 0x1c + param_1 * 0x20) + 0x10 + iVar6 * 0x14) =
                       local_38;
                  *(int *)(DAT_004e89f0 + 0x18 + param_1 * 0x20) =
                       *(int *)(DAT_004e89f0 + 0x18 + param_1 * 0x20) + 1;
                }
              }
            }
          }
        }
        local_34 = local_34 + *(int *)(local_28 + 4);
        local_2c = local_2c + local_28[1];
        local_38 = local_38 + *(int *)(local_28 + 6);
        if (local_2c < *(uint *)(iVar5 + 0x2c)) {
          *(uint *)(local_28 + 8) =
               (int)local_28 + *(int *)(local_28 + 2) * (uint)local_28[1] + 0x14;
        }
        else {
          local_28[8] = 0;
          local_28[9] = 0;
        }
        local_28 = *(ushort **)(local_28 + 8);
        if (bVar3) {
          _DAT_004e8a00 = 1;
        }
      } while (local_28 != (ushort *)0x0);
    }
  }
  return;
}

