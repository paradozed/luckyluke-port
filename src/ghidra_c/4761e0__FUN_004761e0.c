/* FUN_004761e0 @ 004761e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004761e0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_84 [16];
  uint local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar3 = local_84;
  for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_c = *(int *)(&DAT_004f13c0 + param_1 * 0x2c);
  if ((*(ushort *)(&DAT_004f13ca + param_1 * 0x2c) & 2) == 0) {
    for (local_40 = 0; local_40 < (int)(uint)*(ushort *)(&DAT_004f13e0 + param_1 * 0x2c);
        local_40 = local_40 + 1) {
      local_44 = (uint)*(ushort *)(&DAT_004f13e2 + local_40 * 2 + param_1 * 0x2c);
      if ((*(int *)(&DAT_004f1e40 + local_44 * 4) != 0) &&
         (((*(ushort *)(*(int *)(&DAT_004f1e40 + local_44 * 4) + 0xe) & 4) != 0 ||
          ((*(ushort *)(*(int *)(&DAT_004f1e40 + local_44 * 4) + 0xe) & 2) != 0)))) {
        local_8 = **(int **)(*(int *)(&DAT_004f1e40 + local_44 * 4) + 8);
        FUN_00475890(local_8,&local_24);
        FUN_00475890(local_c,&local_3c);
        local_30 = local_30 + *(int *)(local_c + 0x90);
        local_3c = local_3c + *(int *)(local_c + 0x90);
        local_2c = local_2c + *(int *)(local_c + 0x94);
        local_38 = local_38 + *(int *)(local_c + 0x94);
        local_28 = local_28 + *(int *)(local_c + 0x98);
        local_34 = local_34 + *(int *)(local_c + 0x98);
        local_18 = local_18 + *(int *)(local_8 + 0x90);
        local_24 = local_24 + *(int *)(local_8 + 0x90);
        local_14 = local_14 + *(int *)(local_8 + 0x94);
        local_20 = local_20 + *(int *)(local_8 + 0x94);
        local_10 = local_10 + *(int *)(local_8 + 0x98);
        local_1c = local_1c + *(int *)(local_8 + 0x98);
        uVar1 = FUN_0040d810(&local_24,&local_3c);
        if ((short)uVar1 != 0) {
          *(undefined2 *)(&DAT_004f13ca + param_1 * 0x2c) = 0;
          if ((*(ushort *)(*(int *)(&DAT_004f1e40 + local_44 * 4) + 0xe) & 2) == 0) {
            *(ushort *)(*(int *)(&DAT_004f1e40 + local_44 * 4) + 0xe) =
                 *(ushort *)(*(int *)(&DAT_004f1e40 + local_44 * 4) + 0xe) | 1;
            *(short *)(&DAT_004f13e0 + param_1 * 0x2c) =
                 *(short *)(&DAT_004f13e0 + param_1 * 0x2c) + -1;
            DAT_004f5554 = (undefined2)local_44;
            DAT_004f13b0 = (undefined2)param_1;
          }
          else {
            FUN_00468c20(1,1);
          }
          break;
        }
      }
    }
  }
  else {
    for (local_40 = 0; local_40 < 0xfa; local_40 = local_40 + 1) {
      if (((*(int *)(&DAT_004f1e40 + local_40 * 4) != 0) &&
          ((*(ushort *)(*(int *)(&DAT_004f1e40 + local_40 * 4) + 0xe) & 4) != 0)) &&
         (local_44 = (uint)*(ushort *)(*(int *)(&DAT_004f1e40 + local_40 * 4) + 0xc),
         (*(uint *)(*(int *)(&DAT_004f1e40 + local_40 * 4) + 8) & 0xa0000000) == 0)) {
        local_8 = **(int **)(*(int *)(&DAT_004f1e40 + local_40 * 4) + 8);
        FUN_00475890(local_8,&local_24);
        FUN_00475890(local_c,&local_3c);
        local_30 = local_30 + *(int *)(local_c + 0x90);
        local_3c = local_3c + *(int *)(local_c + 0x90);
        local_2c = local_2c + *(int *)(local_c + 0x94);
        local_38 = local_38 + *(int *)(local_c + 0x94);
        local_28 = local_28 + *(int *)(local_c + 0x98);
        local_34 = local_34 + *(int *)(local_c + 0x98);
        local_18 = local_18 + *(int *)(local_8 + 0x90);
        local_24 = local_24 + *(int *)(local_8 + 0x90);
        local_14 = local_14 + *(int *)(local_8 + 0x94);
        local_20 = local_20 + *(int *)(local_8 + 0x94);
        local_10 = local_10 + *(int *)(local_8 + 0x98);
        local_1c = local_1c + *(int *)(local_8 + 0x98);
        uVar1 = FUN_0040d810(&local_24,&local_3c);
        if ((short)uVar1 != 0) {
          *(undefined2 *)(&DAT_004f13ca + param_1 * 0x2c) = 0;
          *(ushort *)(*(int *)(&DAT_004f1e40 + local_40 * 4) + 0xe) =
               *(ushort *)(*(int *)(&DAT_004f1e40 + local_40 * 4) + 0xe) | 1;
          DAT_004f16bc = (undefined2)param_1;
          DAT_004e8982 = (undefined2)local_44;
          break;
        }
      }
    }
  }
  local_8 = 0x476616;
  __chkesp();
  return;
}

