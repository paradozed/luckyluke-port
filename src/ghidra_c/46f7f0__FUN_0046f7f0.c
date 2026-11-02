/* FUN_0046f7f0 @ 0046f7f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046f7f0(uint param_1,ushort param_2,ushort param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  ushort uVar4;
  undefined4 *puVar5;
  undefined4 local_88 [16];
  uint local_48;
  uint local_44;
  byte local_40 [4];
  byte local_3c [4];
  char local_38 [4];
  char local_34 [8];
  short local_2c;
  short local_28;
  int local_24;
  int local_20;
  uint local_1c;
  size_t local_18;
  int local_14;
  uint *local_10;
  ushort *local_c;
  ushort *local_8;
  
  puVar5 = local_88;
  for (iVar3 = 0x21; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  local_18 = (uint)param_2 * 100 + 0x34;
  local_8 = (ushort *)FUN_00439a90(DAT_004e85ec,local_18);
  _memset(local_8,0,local_18);
  local_c = local_8 + 0x18;
  *local_8 = param_3;
  local_8[1] = param_2;
  local_8[2] = 0;
  local_44 = (uint)param_3;
  if (param_3 == 0) {
    FUN_0046f780((int)local_8,0x1000,0x1fff,0xfffffc00,0x1fff,0x5dc,0x1fff,10,1,0);
    local_8[4] = 0;
    local_8[5] = 0;
    local_8[6] = 0;
    local_8[7] = 0;
  }
  else if (local_44 == 1) {
    FUN_0046f780((int)local_8,0,0x1fff,0,0x3fff,7000,0xfff,2,0,1);
  }
  if ((char)local_8[3] == '\x01') {
    uVar1 = FUN_0046e8d0(param_1 & 0xffff);
    *(undefined4 *)(local_8 + 0x16) = uVar1;
    local_14 = *(int *)(*(int *)(*(int *)(local_8 + 0x16) + 8) + 4);
  }
  else {
    local_14 = *(int *)(DAT_004e8820 + 4 + (param_1 & 0xffff) * 4);
  }
  local_28 = *(short *)(DAT_004d1e78 + local_14 * 4);
  local_2c = *(short *)(DAT_004d1e78 + 2 + local_14 * 4);
  local_20 = DAT_004d1e7c + local_28 * 0x14;
  local_24 = DAT_004d1e80 + local_2c * 0x10;
  while (uVar4 = param_2 - 1, param_2 != 0) {
    for (local_1c = 0; local_1c < 2; local_1c = local_1c + 1) {
      local_10 = (uint *)(local_c + local_1c * 0x14);
      *local_10 = *local_10 & 0xffffff | 0x9000000;
      *(undefined1 *)((int)local_10 + 7) = 0x2c;
      FUN_00470c70(local_14,local_34,local_38);
      FUN_00470e20(local_14,local_3c,local_40);
      *(char *)(local_10 + 3) = local_34[0];
      *(char *)((int)local_10 + 0xd) = local_38[0];
      *(char *)(local_10 + 5) = local_34[0] + -1 + local_3c[0];
      *(char *)((int)local_10 + 0x15) = local_38[0];
      *(char *)(local_10 + 7) = local_34[0];
      *(char *)((int)local_10 + 0x1d) = local_38[0] + -1 + local_40[0];
      *(char *)(local_10 + 9) = local_34[0] + -1 + local_3c[0];
      *(char *)((int)local_10 + 0x25) = local_38[0] + -1 + local_40[0];
      *(undefined2 *)((int)local_10 + 0x16) = *(undefined2 *)(local_20 + 0xe);
      *(undefined2 *)((int)local_10 + 0xe) = *(undefined2 *)(local_24 + 0xc);
      *(undefined1 *)(local_10 + 1) = 0x80;
      *(undefined1 *)((int)local_10 + 5) = 0x80;
      *(undefined1 *)((int)local_10 + 6) = 0x80;
    }
    uVar1 = *(undefined4 *)(local_8 + 10);
    uVar2 = FUN_004971c0();
    local_c[0x28] = ((ushort)uVar2 & (ushort)*(undefined4 *)(local_8 + 0xc)) - (short)uVar1;
    uVar2 = FUN_004971c0();
    local_c[0x29] =
         (short)*(undefined4 *)(local_8 + 0xe) -
         ((ushort)uVar2 & (ushort)*(undefined4 *)(local_8 + 0x10));
    uVar2 = FUN_004971c0();
    local_c[0x2a] =
         (short)*(undefined4 *)(local_8 + 0x12) +
         ((ushort)uVar2 & (ushort)*(undefined4 *)(local_8 + 0x14));
    local_c[0x28] = local_c[0x28] + (short)DAT_004bd6a0;
    local_48 = (uint)param_3;
    if (param_3 == 0) {
      uVar2 = FUN_004971c0();
      local_c[0x2e] = ((ushort)uVar2 & 0x3f) - 0x20;
      uVar2 = FUN_004971c0();
      local_c[0x2f] = ((ushort)uVar2 & 0x3f) + 0x32;
      local_c[0x30] = 0;
    }
    else if (local_48 == 1) {
      if (uVar4 % 3 == 0) {
        local_c[0x2a] = (short)((int)(short)local_c[0x2a] - *(int *)(local_8 + 0x12) >> 1) + 2000;
      }
      local_c[0x2e] = 0;
      uVar2 = FUN_004971c0();
      local_c[0x2f] = ((ushort)uVar2 & 0x1f) + 10;
      local_c[0x30] =
           (ushort)((ulonglong)uVar4 %
                   (ulonglong)(longlong)(int)(uint)*(ushort *)(*(int *)(local_8 + 0x16) + 2));
    }
    local_c[0x2c] = local_c[0x2e];
    local_c[0x2d] = local_c[0x2f];
    local_c = local_c + 0x32;
    param_2 = uVar4;
  }
  local_8 = (ushort *)0x46fc32;
  __chkesp();
  return;
}

