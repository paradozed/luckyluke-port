/* FUN_004b11de @ 004b11de */
/* decompiled from Lucky.exe (Game.run) */


undefined1 __fastcall
FUN_004b11de(int *param_1,int param_2,int param_3,int *param_4,int param_5,int param_6,int param_7,
            int param_8,int param_9)

{
  bool bVar1;
  short sVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined3 extraout_var_00;
  sbyte local_60;
  ushort local_5c;
  undefined1 local_54;
  int local_50;
  int local_4c;
  short *local_44;
  byte *local_40;
  sbyte local_38;
  undefined4 local_34 [2];
  uint local_2c;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c [2];
  int local_14;
  int local_c;
  short local_8;
  undefined2 uStack_6;
  
  local_54 = 0;
  if (param_9 != 0) {
    if (DAT_004c7fbc == '\0') {
      local_60 = 10;
      local_38 = 3;
      local_20 = 0x3e0;
      local_5c = 0x7c00;
    }
    else {
      local_60 = 0xb;
      local_38 = 2;
      local_20 = 0x7e0;
      local_5c = 0xf800;
    }
    bVar1 = FUN_004b0264(param_1,local_34);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      do {
        iVar3 = FUN_004ae250(s_goW95LockScreen_dst__dstinfo__004c8c60,0x4c8c30,0x23d);
      } while (iVar3 != 0);
    }
    bVar1 = FUN_004b0264(param_4,local_1c);
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      do {
        iVar3 = FUN_004ae250(s_goW95LockScreen_src__srcinfo__004c8cb0,0x4c8c80,0x23e);
      } while (iVar3 != 0);
    }
    local_44 = (short *)(local_24 + ((local_2c >> 1) * param_3 + param_2) * 2);
    local_40 = (byte *)(local_c + param_6 * local_14 + param_5);
    iVar3 = param_7 - param_5;
    for (local_4c = 0; local_4c < param_8 - param_6; local_4c = local_4c + 1) {
      for (local_50 = 0; local_50 < iVar3; local_50 = local_50 + 1) {
        if (*local_40 != 0) {
          sVar2 = ((ushort)(((int)(uint)*(byte *)(param_9 + (uint)*local_40 * 4) >> 3) << local_60)
                  & local_5c) +
                  ((ushort)(((int)(uint)*(byte *)(param_9 + 1 + (uint)*local_40 * 4) >> local_38) <<
                           5) & (ushort)local_20) +
                  (ushort)(*(byte *)(param_9 + 2 + (uint)*local_40 * 4) >> 3);
          _local_8 = CONCAT22(uStack_6,sVar2);
          *local_44 = sVar2;
        }
        local_44 = local_44 + 1;
        local_40 = local_40 + 1;
      }
      local_44 = local_44 + ((local_2c >> 1) - iVar3);
      local_40 = local_40 + (local_14 - iVar3);
    }
    iVar3 = FUN_004b021a(param_4);
    if (iVar3 == 0) {
      do {
        iVar3 = FUN_004ae250(s_goW95UnlockScreen_src__004c8d00,0x4c8cd0,600);
      } while (iVar3 != 0);
    }
    iVar3 = FUN_004b021a(param_1);
    if (iVar3 == 0) {
      do {
        iVar3 = FUN_004ae250(s_goW95UnlockScreen_dst__004c8d48,0x4c8d18,0x259);
      } while (iVar3 != 0);
    }
    local_54 = 1;
  }
  return local_54;
}

