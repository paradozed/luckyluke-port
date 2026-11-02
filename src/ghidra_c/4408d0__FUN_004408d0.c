/* FUN_004408d0 @ 004408d0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004408d0(int param_1,int param_2,char param_3)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  undefined4 *puVar7;
  uint *puVar8;
  undefined4 local_78 [16];
  uint *local_38;
  uint *local_34;
  int local_28;
  int local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar7 = local_78;
  for (iVar3 = 0x1d; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar7 = 0xcccccccc;
    puVar7 = puVar7 + 1;
  }
  if (param_1 != 0) {
    local_1c = *(uint *)(param_1 + 0x194);
    local_28 = 0;
    local_10 = 0;
    for (local_c = 0; local_c < *(int *)(param_1 + 0x1a0); local_c = local_c + 1) {
      if ((local_c == *(int *)(param_1 + 0x1a0) + -1) && ((*(uint *)(param_1 + 0x198) & 0xff) != 0))
      {
        local_18 = *(uint *)(param_1 + 0x198) & 0xff;
      }
      else {
        local_18 = 0x100;
      }
      local_24 = 0;
      for (local_8 = 0; local_8 < *(int *)(param_1 + 0x19c); local_8 = local_8 + 1) {
        if ((local_8 == *(int *)(param_1 + 0x19c) + -1) && ((local_1c & 0xff) != 0)) {
          local_14 = local_1c & 0xff;
        }
        else {
          local_14 = 0x100;
        }
        uVar1 = *(ushort *)(param_1 + 0x16 + local_10 * 0x28);
        local_20 = (uint)uVar1;
        local_34 = *(uint **)(DAT_004f58a4 + local_20 * 4);
        local_38 = (uint *)(param_2 + local_28 * local_1c * 2 + local_24 * 2);
        if (param_3 == '\0') {
          uVar4 = local_14;
          puVar6 = local_38;
          puVar8 = local_34;
          uVar5 = local_18;
          do {
            for (; uVar4 != 0; uVar4 = uVar4 - 1) {
              *(short *)puVar8 = (short)*puVar6;
              puVar6 = (uint *)((int)puVar6 + 2);
              puVar8 = (uint *)((int)puVar8 + 2);
            }
            puVar8 = (uint *)((int)puVar8 + (0x100 - local_14) * 2);
            puVar6 = (uint *)((int)puVar6 + (local_1c - local_14) * 2);
            uVar5 = uVar5 - 1;
            uVar4 = local_14;
          } while (uVar5 != 0);
        }
        else {
          local_38 = (uint *)(param_2 + (local_28 * local_1c + local_24) * 3);
          if (*DAT_004f58a8 == 0x536f6674) {
            uVar4 = local_14;
            puVar6 = local_38;
            puVar8 = local_34;
            uVar5 = local_18;
            do {
              do {
                uVar2 = *puVar6 >> 5;
                *puVar8 = *puVar6 >> 3 & 0x1f | uVar2 & 0x7e0 | (uVar2 & 0x7ffe0) >> 3 & 0xf800;
                puVar6 = (uint *)((int)puVar6 + 3);
                puVar8 = (uint *)((int)puVar8 + 2);
                uVar4 = uVar4 - 1;
              } while (uVar4 != 0);
              puVar8 = (uint *)((int)puVar8 + (0x100 - local_14) * 2);
              puVar6 = (uint *)((int)puVar6 + (local_1c - local_14) * 3);
              uVar5 = uVar5 - 1;
              uVar4 = local_14;
            } while (uVar5 != 0);
          }
          else {
            uVar4 = local_14;
            puVar6 = local_38;
            puVar8 = local_34;
            uVar5 = local_18;
            do {
              do {
                uVar2 = *puVar6 >> 6;
                *puVar8 = *puVar6 >> 3 & 0x1f | uVar2 & 0x3e0 | 0x8000 |
                          (uVar2 & 0x3ffe0) >> 3 & 0x7c00;
                puVar6 = (uint *)((int)puVar6 + 3);
                puVar8 = (uint *)((int)puVar8 + 2);
                uVar4 = uVar4 - 1;
              } while (uVar4 != 0);
              puVar8 = (uint *)((int)puVar8 + (0x100 - local_14) * 2);
              puVar6 = (uint *)((int)puVar6 + (local_1c - local_14) * 3);
              uVar5 = uVar5 - 1;
              uVar4 = local_14;
            } while (uVar5 != 0);
          }
        }
        (*DAT_004e8a24)(uVar1,*(undefined4 *)(DAT_004f58a4 + local_20 * 4));
        __chkesp();
        local_24 = local_24 + local_14;
        local_10 = local_10 + 1;
      }
      local_28 = local_28 + local_18;
    }
  }
  local_8 = 0x440b76;
  __chkesp();
  return;
}

