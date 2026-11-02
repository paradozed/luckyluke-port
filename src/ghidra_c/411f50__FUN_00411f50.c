/* FUN_00411f50 @ 00411f50 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00411f50(void *param_1,void *param_2)

{
  short sVar1;
  undefined2 uVar2;
  ushort *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_60 [16];
  int local_20;
  undefined4 *local_1c;
  ushort *local_18;
  ushort *local_14;
  undefined4 *local_10;
  uint local_c;
  undefined4 local_8;
  
  puVar6 = local_60;
  for (iVar5 = 0x17; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0xcccccccc;
    puVar6 = puVar6 + 1;
  }
  sVar1 = FUN_004074b0(param_2,3);
  local_c = FUN_00473240(DAT_004f1804,sVar1);
  local_8 = CONCAT22(local_8._2_2_,(ushort)local_c);
  puVar3 = (ushort *)FUN_00475460((ushort)local_c);
  local_18 = (ushort *)0x0;
  local_14 = puVar3;
  while ((int)local_18 < (int)(uint)*local_14) {
    uVar4 = CONCAT22((short)((uint)puVar3 >> 0x10),local_18._0_2_);
    sVar1 = FUN_004074b0(param_2,3);
    local_10 = (undefined4 *)FUN_00473140(DAT_004f1804,sVar1,uVar4);
    if (local_10 == (undefined4 *)0x0) {
      local_10 = (undefined4 *)0x0;
    }
    else {
      *(undefined4 *)(*(int *)(local_14 + 2) + (int)local_18 * 0x2c) = *local_10;
      *(undefined4 *)(*(int *)(local_14 + 2) + 4 + (int)local_18 * 0x2c) = local_10[1];
      *(undefined4 *)(*(int *)(local_14 + 2) + 8 + (int)local_18 * 0x2c) = local_10[2];
      *(undefined4 *)(*(int *)(local_14 + 2) + 0xc + (int)local_18 * 0x2c) = local_10[3];
      *(undefined4 *)(*(int *)(local_14 + 2) + 0x10 + (int)local_18 * 0x2c) = local_10[4];
      *(undefined4 *)(*(int *)(local_14 + 2) + 0x14 + (int)local_18 * 0x2c) = local_10[5];
      local_10 = local_10 + 6;
      uVar2 = FUN_004074b0(param_2,4);
      *(char *)(*(int *)(local_14 + 2) + 0x18 + (int)local_18 * 0x2c) = (char)uVar2;
      uVar2 = FUN_004074b0(param_2,5);
      *(char *)(*(int *)(local_14 + 2) + 0x19 + (int)local_18 * 0x2c) = (char)uVar2;
      if (*(int *)(*(int *)(local_14 + 2) + (int)local_18 * 0x2c) +
          *(int *)(*(int *)(local_14 + 2) + 0xc + (int)local_18 * 0x2c) < 0) {
        local_20 = -(*(int *)(*(int *)(local_14 + 2) + (int)local_18 * 0x2c) +
                    *(int *)(*(int *)(local_14 + 2) + 0xc + (int)local_18 * 0x2c));
      }
      else {
        local_20 = *(int *)(*(int *)(local_14 + 2) + (int)local_18 * 0x2c) +
                   *(int *)(*(int *)(local_14 + 2) + 0xc + (int)local_18 * 0x2c);
      }
      *(int *)(*(int *)(local_14 + 2) + 0x1c + (int)local_18 * 0x2c) = local_20 / 2;
    }
    puVar3 = (ushort *)((int)local_18 + 1);
    local_18 = puVar3;
  }
  local_1c = (undefined4 *)FUN_004714a0(DAT_004f1e24);
  uVar2 = FUN_004074b0(param_2,2);
  *(undefined2 *)(local_1c + 3) = uVar2;
  local_1c[1] = FUN_00475580;
  *(undefined1 *)(local_1c + 4) = 1;
  *local_1c = FUN_004755a0;
  *(undefined1 *)((int)local_1c + 0x11) = 1;
  local_1c[2] = local_14;
  FUN_00412c50(param_1,local_1c);
  FUN_00412ee0(param_1,FUN_004754c0);
  local_8 = 0x4121cb;
  __chkesp();
  return;
}

