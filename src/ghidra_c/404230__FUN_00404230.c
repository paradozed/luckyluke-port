/* FUN_00404230 @ 00404230 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00404230(HWND param_1,uint param_2,uint param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_5c [16];
  uint local_1c;
  int local_14;
  int local_10;
  int *local_c;
  undefined4 local_8;
  
  puVar3 = local_5c;
  for (iVar2 = 0x16; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_1c = param_2;
  if (0x12 < param_2) {
    if (param_2 < 0x113) {
      if (param_2 == 0x112) {
        uVar1 = param_3 & 0xfff0;
        if (((uVar1 == 0xf140) || (uVar1 == 0xf170)) || (uVar1 == 0xf130)) goto LAB_004046c0;
      }
      else if (param_2 == 0x20) {
        SetCursor((HCURSOR)0x0);
        __chkesp();
      }
      else if ((param_2 == 0x86) && (FUN_00458ec0(), DAT_004d1dc0 != 0)) {
        if (param_3 == 1) {
          if (DAT_004bcfe8 == '\0') {
            FUN_00458ec0();
            DAT_004bcfe8 = '\x01';
            (*DAT_005089e0)(1);
            __chkesp();
            FUN_0044b2a0();
            FUN_00443a60();
          }
        }
        else if (DAT_004bcfe8 != '\0') {
          FUN_00458ec0();
          DAT_004bcfe8 = '\0';
          (*DAT_005089e0)(0);
          __chkesp();
        }
      }
    }
    else if (param_2 == 0x214) {
      local_c = param_4;
      local_10 = param_4[2] - *param_4;
      local_14 = param_4[3] - param_4[1];
      if (0x280 < local_10) {
        param_4[2] = *param_4 + 0x280;
      }
      if (0x1e0 < local_14) {
        param_4[3] = param_4[1] + 0x1e0;
      }
      if (local_10 < 0x32) {
        param_4[2] = *param_4 + 0x32;
      }
      if (local_14 < 0x32) {
        param_4[3] = param_4[1] + 0x32;
      }
      goto LAB_004046c0;
    }
    goto switchD_0040427c_caseD_4;
  }
  if (param_2 == 0x12) goto LAB_004046c0;
  local_1c = param_2 - 2;
  switch(param_2) {
  case 2:
    goto LAB_004046c0;
  case 3:
    if ((DAT_004e8590 != 0) && (DAT_004bcfe8 != '\0')) {
      FUN_0047c4e0((short)(DAT_004be3c8 >> 1),(short)(DAT_004be3cc >> 1),(short)DAT_004bdaac);
      (*DAT_004e8a64)(param_1,DAT_004be3c8,DAT_004be3cc);
      __chkesp();
    }
    break;
  case 5:
    if ((*DAT_004f58a8 != 0x33446678) || (DAT_004bcfe8 == '\0')) {
      FUN_00458ec0();
      if ((param_3 == 4) || (param_3 == 1)) {
        if ((DAT_004e8590 != 0) || (DAT_004bcfe8 != '\0')) {
          DAT_004bcfe8 = '\0';
          goto LAB_004043c7;
        }
      }
      else if ((DAT_004e8590 != 0) || (DAT_004bcfe8 == '\0')) {
        DAT_004bcfe8 = '\x01';
LAB_004043c7:
        FUN_00458ec0();
        if (DAT_004bcfe8 == '\0') {
          (*DAT_005089f0)();
          __chkesp();
        }
        else {
          if (DAT_004e8590 != 0) {
            FUN_00458ec0();
            if (param_3 != 1) {
              DAT_004be3c8 = (uint)param_4 & 0xffff;
              DAT_004be3cc = (uint)param_4 >> 0x10;
              FUN_0047c4e0((short)(DAT_004be3c8 >> 1),(ushort)((uint)param_4 >> 0x11),
                           (short)DAT_004bdaac);
            }
            (*DAT_004e8a64)(param_1,DAT_004be3c8,DAT_004be3cc);
            __chkesp();
            FUN_00443a60();
          }
          if (*DAT_004f58a8 == 0x33446678) {
            FUN_00458ec0();
            (*DAT_005089e0)(1);
            __chkesp();
            FUN_0044b2a0();
            FUN_00443a60();
          }
          else if (DAT_004bc064 != 0) {
            DAT_004bc064 = 0;
            (*DAT_00508988)(param_1,DAT_004be3c8,DAT_004be3cc);
            iVar2 = __chkesp();
            if (iVar2 == 0) {
              MessageBoxA(param_1,DAT_004f5de8,DAT_004f5dd4,0);
              __chkesp();
              FUN_00496ef0(0xffffffff);
            }
            FUN_0044b2a0();
            FUN_00443a60();
            DAT_004bc064 = 1;
          }
        }
      }
    }
    break;
  case 0x10:
    DAT_004f1e20 = 1;
    DAT_004f1e21 = 1;
    SendMessageA(param_1,2,0,0);
    __chkesp();
    DAT_004e8603 = 1;
    goto LAB_004046c0;
  }
switchD_0040427c_caseD_4:
LAB_004046c0:
  local_8 = 0x4046cd;
  __chkesp();
  return;
}

