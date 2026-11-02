/* FUN_00403060 @ 00403060 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00403060(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_ac [16];
  undefined4 local_6c;
  undefined4 *local_68;
  undefined4 *local_64;
  undefined4 *local_60;
  undefined4 *local_5c;
  undefined4 *local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  undefined4 *local_38;
  int local_34;
  undefined1 local_30 [4];
  undefined4 local_2c;
  undefined1 local_24 [4];
  MCIDEVICEID local_20;
  char *local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004b27eb;
  local_10 = ExceptionList;
  puVar2 = local_ac;
  for (iVar1 = 0x27; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_10;
  FUN_00458ec0();
  local_1c = "cdaudio";
  mciSendCommandA(0,0x803,0x2000,(DWORD_PTR)local_24);
  iVar1 = __chkesp();
  if (iVar1 == 0) {
    DAT_004d1d60 = local_20;
    FUN_00458ec0();
    local_2c = 2;
    mciSendCommandA(DAT_004d1d60,0x80d,0x400,(DWORD_PTR)local_30);
    iVar1 = __chkesp();
    if (iVar1 == 0) {
      FUN_00458ec0();
      DAT_004d1cdc = FUN_00403e00();
      if ((DAT_004d1cdc < 0x14) || (iVar1 = FUN_00403e70(&DAT_004d1d68), iVar1 == 0)) {
        mciSendCommandA(DAT_004d1d60,0x804,0,0);
        __chkesp();
      }
      else {
        FUN_00458ec0();
        DAT_004d1d6c = param_1;
        DAT_004d1d64 = 1;
        FUN_00458ec0();
        DAT_004d1cd0 = 0;
        mixerGetNumDevs();
        local_34 = __chkesp();
        FUN_00458ec0();
        FUN_00458ec0();
        for (local_3c = 0; local_3c < local_34; local_3c = local_3c + 1) {
          local_5c = (undefined4 *)FUN_00496760(0x90);
          local_8 = 0;
          if (local_5c == (undefined4 *)0x0) {
            local_68 = (undefined4 *)0x0;
          }
          else {
            local_68 = FUN_004021d0(local_5c);
          }
          local_58 = local_68;
          local_8 = 0xffffffff;
          local_38 = local_68;
          iVar1 = FUN_00402380(local_68,local_3c);
          if (iVar1 == 0) {
            local_64 = local_38;
            local_60 = local_38;
            if (local_38 == (undefined4 *)0x0) {
              local_6c = 0;
            }
            else {
              (**(code **)*local_38)(1);
              local_6c = __chkesp();
            }
          }
          else {
            *(undefined4 **)(&DAT_004d1ce0 + local_3c * 4) = local_38;
            DAT_004d1cd0 = DAT_004d1cd0 + 1;
            FUN_004025d0(*(int *)(&DAT_004d1ce0 + local_3c * 4));
            FUN_00458ec0();
          }
        }
        DAT_004d1cc4 = -1;
        DAT_004d1cc8 = -1;
        DAT_004d1ccc = -1;
        FUN_00458ec0();
        for (local_3c = 0; local_3c < DAT_004d1cd0; local_3c = local_3c + 1) {
          local_44 = FUN_00402600(*(int *)(&DAT_004d1ce0 + local_3c * 4));
          FUN_00458ec0();
          for (local_40 = 0; local_40 < local_44; local_40 = local_40 + 1) {
            if (*(int *)(*(int *)(*(int *)(&DAT_004d1ce0 + local_3c * 4) + 0x40 + local_40 * 4) +
                        0x28) == 0x1005) {
              FUN_00458ec0();
              DAT_004d1ccc = local_3c;
              DAT_004d1cc8 = local_40;
              local_48 = FUN_00402690(*(void **)(&DAT_004d1ce0 + local_3c * 4),local_40);
              FUN_00458ec0();
              for (local_4c = 0; local_4c < local_48; local_4c = local_4c + 1) {
                FUN_00402740(*(void **)(&DAT_004d1ce0 + local_3c * 4),local_40,local_4c);
                FUN_004026e0(*(void **)(&DAT_004d1ce0 + local_3c * 4),local_40,local_4c);
                FUN_00458ec0();
                if (*(int *)(*(int *)(*(int *)(&DAT_004d1ce0 + local_3c * 4) + 0x40 + local_40 * 4)
                             + 0xd8 + local_4c * 0x94) == 0x50030001) {
                  FUN_00458ec0();
                  DAT_004d1cc4 = local_4c;
                  goto LAB_004035d8;
                }
                FUN_00458ec0();
              }
            }
          }
          for (local_40 = 0; local_40 < local_44; local_40 = local_40 + 1) {
            if (*(int *)(*(int *)(*(int *)(&DAT_004d1ce0 + local_3c * 4) + 0x40 + local_40 * 4) +
                        0x28) == 0x1009) {
              FUN_00458ec0();
              DAT_004d1ccc = local_3c;
              DAT_004d1cc8 = local_40;
              local_50 = FUN_00402690(*(void **)(&DAT_004d1ce0 + local_3c * 4),local_40);
              FUN_00458ec0();
              for (local_54 = 0; local_54 < local_50; local_54 = local_54 + 1) {
                FUN_00402740(*(void **)(&DAT_004d1ce0 + local_3c * 4),local_40,local_54);
                FUN_004026e0(*(void **)(&DAT_004d1ce0 + local_3c * 4),local_40,local_54);
                FUN_00458ec0();
                if (*(int *)(*(int *)(*(int *)(&DAT_004d1ce0 + local_3c * 4) + 0x40 + local_40 * 4)
                             + 0xd8 + local_54 * 0x94) == 0x50030001) {
                  FUN_00458ec0();
                  DAT_004d1cc4 = local_54;
                  goto LAB_004035d8;
                }
                FUN_00458ec0();
              }
            }
          }
        }
LAB_004035d8:
        FUN_00458ec0();
        FUN_00458ec0();
        FUN_00458ec0();
        if (DAT_004d1cc4 != -1) {
          DAT_004d1cd4 = FUN_004027a0(*(void **)(&DAT_004d1ce0 + DAT_004d1ccc * 4),DAT_004d1cc8,
                                      DAT_004d1cc4);
        }
      }
    }
    else {
      mciSendCommandA(DAT_004d1d60,0x804,0,0);
      __chkesp();
    }
  }
  ExceptionList = local_10;
  local_8 = 0x40365f;
  __chkesp();
  return;
}

