/* FUN_004a4eb0 @ 004a4eb0 */
/* decompiled from Lucky.exe (Game.run) */


int __cdecl FUN_004a4eb0(int param_1,int param_2)

{
  int iVar1;
  BOOL BVar2;
  int local_c;
  undefined4 *local_8;
  
  if ((param_2 != 4) && (param_2 != 3)) {
    if ((param_1 == 2) || (((param_1 == 0x15 || (param_1 == 0x16)) || (param_1 == 0xf)))) {
      if (((param_1 == 2) || (param_1 == 0x15)) && (DAT_004e8e3c == 0)) {
        BVar2 = SetConsoleCtrlHandler(ctrlevent_capture,1);
        if (BVar2 != 1) {
          DAT_004e8c68 = GetLastError();
          DAT_004e8c64 = 0x16;
          return -1;
        }
        DAT_004e8e3c = 1;
      }
      switch(param_1) {
      case 2:
        local_c = DAT_004e8e2c;
        DAT_004e8e2c = param_2;
        break;
      case 0xf:
        local_c = DAT_004e8e38;
        DAT_004e8e38 = param_2;
        break;
      case 0x15:
        local_c = DAT_004e8e30;
        DAT_004e8e30 = param_2;
        break;
      case 0x16:
        local_c = DAT_004e8e34;
        DAT_004e8e34 = param_2;
      }
      return local_c;
    }
    if ((((param_1 == 8) || (param_1 == 4)) || (param_1 == 0xb)) &&
       (local_8 = siglookup(param_1), local_8 != (undefined4 *)0x0)) {
      iVar1 = local_8[2];
      do {
        if (local_8[1] != param_1) {
          return iVar1;
        }
        local_8[2] = param_2;
        local_8 = local_8 + 3;
      } while (local_8 < &DAT_004c7738 + DAT_004c77b8 * 3);
      return iVar1;
    }
  }
  DAT_004e8c64 = 0x16;
  return -1;
}

