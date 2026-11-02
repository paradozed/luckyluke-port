/* FUN_0046f4c0 @ 0046f4c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046f4c0(int param_1)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_80 [16];
  int local_40;
  int local_3c;
  int local_38;
  byte local_34 [4];
  byte local_30 [4];
  char local_2c [4];
  char local_28 [4];
  ushort local_24;
  undefined2 uStack_22;
  uint local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar4 = local_80;
  for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_8 = param_1 + 0x30;
  local_14 = *(int *)(param_1 + 0x2c);
  local_1c = CONCAT22(local_1c._2_2_,*(undefined2 *)(param_1 + 4));
  local_40 = *(int *)(param_1 + 0x10) * 6;
  local_18 = local_18 & 0xffff0000;
  while ((local_18 & 0xffff) < (local_1c & 0xffff)) {
    local_c = local_8 + (uint)DAT_004e89d8 * 0x28;
    uVar1 = *(ushort *)(*(int *)(local_14 + 8) + 4 + (uint)*(ushort *)(local_8 + 0x60) * 0xc);
    local_20 = CONCAT22(local_20._2_2_,uVar1);
    FUN_00470c70((uint)uVar1,local_28,local_2c);
    FUN_00470e20(local_20 & 0xffff,local_30,local_34);
    *(char *)(local_c + 0xc) = local_28[0];
    *(char *)(local_c + 0xd) = local_2c[0];
    *(char *)(local_c + 0x14) = local_28[0] + -1 + local_30[0];
    *(char *)(local_c + 0x15) = local_2c[0];
    *(char *)(local_c + 0x1c) = local_28[0];
    *(char *)(local_c + 0x1d) = local_2c[0] + -1 + local_34[0];
    *(char *)(local_c + 0x24) = local_28[0] + -1 + local_30[0];
    *(char *)(local_c + 0x25) = local_2c[0] + -1 + local_34[0];
    local_10 = DAT_004d1e7c + (uint)*(ushort *)(DAT_004d1e78 + (local_20 & 0xffff) * 4) * 0x14;
    *(undefined2 *)(local_c + 0x16) = *(undefined2 *)(local_10 + 0xe);
    if (DAT_004e8988 == 0) {
      if (*(short *)(local_8 + 0x60) == 0) {
        sVar2 = *(short *)(local_14 + 2);
      }
      else {
        sVar2 = *(short *)(local_8 + 0x60);
      }
      uVar1 = sVar2 - 1;
      _local_24 = CONCAT22(uStack_22,uVar1);
      local_38 = *(short *)(*(int *)(local_14 + 8) + 8 + (uint)*(ushort *)(local_8 + 0x60) * 0xc) *
                 local_40 - *(short *)(*(int *)(local_14 + 8) + 8 + (uint)uVar1 * 0xc) * local_40;
      local_3c = *(short *)(*(int *)(local_14 + 8) + 10 + (uint)*(ushort *)(local_8 + 0x60) * 0xc) *
                 local_40 - *(short *)(*(int *)(local_14 + 8) + 10 + (uint)uVar1 * 0xc) * local_40;
      *(short *)(local_8 + 0x50) = *(short *)(local_8 + 0x50) + (short)local_38;
      *(short *)(local_8 + 0x52) = *(short *)(local_8 + 0x52) + (short)local_3c;
      *(short *)(local_8 + 0x60) = *(short *)(local_8 + 0x60) + 1;
      if (*(short *)(local_8 + 0x60) == *(short *)(local_14 + 2)) {
        *(undefined2 *)(local_8 + 0x60) = 0;
      }
    }
    local_8 = local_8 + 100;
    local_18 = CONCAT22(local_18._2_2_,(short)local_18 + 1);
  }
  local_8 = 0x46f774;
  __chkesp();
  return;
}

