/* FUN_00494450 @ 00494450 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00494450(byte param_1,DWORD param_2,ushort param_3,int param_4,int param_5)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_68 [16];
  uint local_28;
  uint local_24;
  int local_20;
  int local_1c;
  undefined1 local_18 [16];
  undefined4 local_8;
  
  puVar3 = local_68;
  for (iVar2 = 0x19; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (DAT_004e8c40 == '\0') {
    FUN_00493f60();
    FUN_00494170();
    DAT_00508a08 = param_1;
    DAT_00508e28 = param_2;
    DAT_00508e24 = param_3;
    DAT_00508e20 = param_4;
    DAT_00508a10 = param_5;
    DAT_004e8c44 = (void *)FUN_00494840(param_5 * 0x14);
    if (DAT_004e8c44 != (void *)0x0) {
      _memset(DAT_004e8c44,0,param_5 * 0x14);
      local_18._0_2_ = 1;
      local_18._2_2_ = ZEXT12(DAT_00508a08);
      local_18._4_4_ = DAT_00508e28;
      local_18._12_2_ = (ushort)DAT_00508a08 * (short)((int)(uint)DAT_00508e24 >> 3);
      local_18._14_2_ = DAT_00508e24;
      local_18._8_4_ = (ushort)local_18._12_2_ * DAT_00508e28;
      local_8 = (uint)local_8._2_2_ << 0x10;
      waveOutOpen((LPHWAVEOUT)&DAT_00508a0c,0xffffffff,(LPCWAVEFORMATEX)local_18,0x494340,0,0x30000)
      ;
      local_1c = __chkesp();
      if (local_1c == 0) {
        local_20 = (int)(((longlong)DAT_00508e20 * (longlong)(int)DAT_00508e28 & 0xffffffffU) /
                        1000000);
        DAT_00508e2c = local_20 * (uint)DAT_00508e24 * (uint)DAT_00508a08 >> 3;
        local_24 = DAT_00508e2c;
        DAT_004e8c3c = FUN_00494840(DAT_00508e2c * 10);
        if (DAT_004e8c3c == 0) {
          FUN_004943d0();
        }
        else {
          for (local_28 = 0; local_28 < 10; local_28 = local_28 + 1) {
            *(uint *)(&DAT_004e8af0 + local_28 * 0x20) = DAT_004e8c3c + local_28 * DAT_00508e2c;
            (&DAT_004e8c30)[local_28] = 1;
          }
          DAT_004e8c40 = '\x01';
          for (local_28 = 0; local_28 < 3; local_28 = local_28 + 1) {
            cVar1 = FUN_00494220(local_24);
            if (cVar1 == '\0') {
              FUN_004943d0();
              break;
            }
          }
        }
      }
      else {
        FUN_00495280(DAT_004e8c44);
      }
    }
  }
  local_8 = 0x494685;
  __chkesp();
  return;
}

