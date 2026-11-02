/* FUN_0046fd90 @ 0046fd90 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046fd90(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 local_80 [16];
  uint local_40;
  short local_3c;
  short local_38;
  undefined4 local_34;
  int local_30;
  int local_2c;
  int local_28;
  uint local_24;
  int local_1c;
  int local_18 [2];
  short *local_10;
  short *local_c;
  short *local_8;
  
  puVar3 = local_80;
  for (iVar1 = 0x1f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = *(short **)(param_1 + 8);
  local_40 = CONCAT22(local_40._2_2_,local_8[2]);
  local_c = local_8 + 0x18;
  if ((DAT_004e8988 == 1) && ((char)local_8[3] == '\x01')) {
    FUN_0046f4c0((int)local_8);
  }
  FUN_004823a0((undefined4 *)&DAT_00508180);
  local_34 = DAT_00508194;
  DAT_00508194 = -DAT_004bd6a0;
  FUN_004824a0(0x508180);
  DAT_00508194 = local_34;
  local_30 = DAT_004bdaac * *(int *)(local_8 + 8);
  while( true ) {
    uVar2 = local_40 & 0xffff;
    local_40 = CONCAT22(local_40._2_2_,(short)local_40 + -1);
    if (uVar2 == 0) break;
    local_24 = FUN_00482e60(local_c + 0x28,(short *)local_18,&local_1c);
    local_24 = local_24 >> 2;
    if (((local_24 < 0x1000) && (local_24 != 0)) && (local_c[0x29] != 0x3e9)) {
      local_38 = (short)local_18[0];
      local_3c = (short)((uint)local_18[0] >> 0x10);
      if (((*local_8 == 1) || (-1 < local_18[0])) || ((uint)(int)local_3c < DAT_004be3cc)) {
        if (local_38 < 0) {
          local_18[0] = local_18[0] + DAT_004be3c8;
        }
        else if (DAT_004be3c8 < (uint)(int)local_38) {
          local_18[0] = local_18[0] - DAT_004be3c8;
        }
        local_10 = local_c + (uint)DAT_004e89d8 * 0x14;
        local_28 = (int)(((uint)*(byte *)(local_10 + 10) - (uint)*(byte *)(local_10 + 6)) * local_30
                        ) / (int)local_c[0x2a] + 1;
        local_2c = (int)(((uint)*(byte *)((int)local_10 + 0x1d) -
                         (uint)*(byte *)((int)local_10 + 0xd)) * local_30) / (int)local_c[0x2a] + 1;
        *(int *)(local_10 + 4) = local_18[0];
        *(int *)(local_10 + 8) = local_18[0] + local_28;
        local_18[0] = local_18[0] + local_28 + (local_2c * 0x10000 - local_28);
        *(int *)(local_10 + 0xc) = local_18[0];
        local_18[0] = local_18[0] + local_2c;
        *(int *)(local_10 + 0x10) = local_18[0];
        FUN_0047d8b0();
        FUN_0047d910(local_10,0,0,0,0,3);
      }
    }
    else {
      local_c[0x29] = 0x3e9;
    }
    local_c = local_c + 0x32;
  }
  local_8 = (short *)0x46ffff;
  __chkesp();
  return;
}

