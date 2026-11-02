/* FUN_00473660 @ 00473660 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00473660(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_60 [16];
  uint local_20;
  ushort *local_1c;
  short local_18;
  short local_14;
  short local_10;
  uint local_8;
  
  puVar2 = local_60;
  for (iVar1 = 0x17; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_10 = 0;
  local_14 = 0;
  local_18 = 0;
  local_1c = *(ushort **)(param_1 + 8);
  DAT_004e8978 = DAT_004e8abc >> 5;
  if (2 < DAT_004e8978 - DAT_004e899c) {
    DAT_004e8996 = DAT_004e8996 + local_1c[7];
    if (0x167 < DAT_004e8996) {
      DAT_004e8996 = 0;
    }
    DAT_004e89a0 = 0;
    DAT_004e899c = DAT_004e8978;
  }
  if ((*(char *)(param_1 + 0x15) != '\0') && ((char)local_1c[1] != '\0')) {
    local_8 = local_8 & 0xffff0000;
    while ((local_8 & 0xffff) < (uint)*local_1c) {
      DAT_004e8998 = DAT_004e8996;
      local_20 = (uint)local_1c[6];
      if (local_20 == 0) {
        local_10 = FUN_00482c60((short)((int)(((int)(short)DAT_004e8996 + (uint)DAT_004e89a0 +
                                              (uint)local_1c[2]) * 0x1000) / 0x168));
        local_10 = local_10 >> ((byte)local_1c[5] & 0x1f);
        local_14 = FUN_00482cb0((short)((int)(((int)(short)DAT_004e8998 + (uint)DAT_004e89a0 +
                                              (uint)local_1c[3]) * 0x1000) / 0x168));
        local_14 = local_14 >> ((byte)local_1c[5] & 0x1f);
        local_18 = 0;
      }
      else if (local_20 == 1) {
        local_18 = FUN_00482c60((short)((int)(((int)(short)DAT_004e8996 + (uint)DAT_004e89a0 +
                                              (uint)local_1c[4]) * 0x1000) / 0x168));
        local_18 = local_18 >> ((byte)local_1c[5] & 0x1f);
        local_14 = FUN_00482cb0((short)((int)(((int)(short)DAT_004e8998 + (uint)DAT_004e89a0 +
                                              (uint)local_1c[3]) * 0x1000) / 0x168));
        local_14 = local_14 >> ((byte)local_1c[5] & 0x1f);
        local_10 = 0;
      }
      else if (local_20 == 2) {
        local_18 = FUN_00482c60((short)((int)(((int)(short)DAT_004e8996 + (uint)DAT_004e89a0 +
                                              (uint)local_1c[2]) * 0x1000) / 0x168));
        local_18 = local_18 >> ((byte)local_1c[5] & 0x1f);
        local_10 = FUN_00482cb0((short)((int)(((int)(short)DAT_004e8998 + (uint)DAT_004e89a0 +
                                              (uint)local_1c[3]) * 0x1000) / 0x168));
        local_10 = local_10 >> ((byte)local_1c[5] & 0x1f);
        local_14 = 0;
      }
      DAT_004e89a0 = DAT_004e89a0 +
                     *(short *)(*(int *)(local_1c + 8) + 0x1c + (local_8 & 0xffff) * 0x20);
      FUN_004739f0(*(int *)(*(int *)(local_1c + 8) + (local_8 & 0xffff) * 0x20),
                   *(int *)(*(int *)(local_1c + 8) + 0xc + (local_8 & 0xffff) * 0x20) +
                   (int)local_10,
                   *(int *)(*(int *)(local_1c + 8) + 0x10 + (local_8 & 0xffff) * 0x20) +
                   (int)local_14,
                   *(int *)(*(int *)(local_1c + 8) + 0x14 + (local_8 & 0xffff) * 0x20) +
                   (int)local_18);
      local_8 = CONCAT22(local_8._2_2_,(short)local_8 + 1);
    }
  }
  local_8 = 0x4739e5;
  __chkesp();
  return;
}

