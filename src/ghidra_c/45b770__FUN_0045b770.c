/* FUN_0045b770 @ 0045b770 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0045b770(uint param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_74 [16];
  uint local_34;
  uint local_30;
  uint local_2c;
  int local_28;
  int local_24;
  uint local_20;
  byte *local_1c;
  uint local_18;
  int local_14;
  uint local_10;
  uint local_c;
  undefined4 local_8;
  
  puVar2 = local_74;
  for (iVar1 = 0x1c; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = CONCAT22(local_8._2_2_,*(short *)(param_2 + 8) * 8 + 0x30);
  local_10 = local_10 & 0xffff0000;
  local_20 = param_1 & 0xffff;
  if (local_20 != 0) {
    if ((local_20 == 0) || (2 < local_20)) {
      FUN_00497610((byte *)"Error: File %s, Line %d");
    }
    else {
      if ((DAT_004f2750 & 0x80) != 0) {
        if (DAT_004e8724 < 1) {
          if (DAT_004e871c != 0) {
            DAT_004e871c = DAT_004e871c - 1;
            DAT_004e8724 = *(short *)(DAT_004e89f0 + (uint)DAT_004e871c * 0x20) + -1;
          }
        }
        else {
          DAT_004e8724 = DAT_004e8724 + -1;
        }
      }
      if ((((DAT_004f2750 & 0x20) != 0) &&
          (DAT_004e8724 = DAT_004e8724 + 1,
          *(short *)(DAT_004e89f0 + (uint)DAT_004e871c * 0x20) <= DAT_004e8724)) &&
         ((int)(uint)DAT_004e871c < (int)(DAT_004e89fa - 1))) {
        DAT_004e871c = DAT_004e871c + 1;
        DAT_004e8724 = 0;
      }
      if (*(short *)(DAT_004e89f0 + (uint)DAT_004e871c * 0x20) <= DAT_004e8724) {
        DAT_004e8724 = *(short *)(DAT_004e89f0 + (uint)DAT_004e871c * 0x20) + -1;
      }
      FUN_00459540();
      if (*(short *)(DAT_004e89f0 + (uint)DAT_004e871c * 0x20) != 0) {
        if (DAT_004e8724 < 0x11) {
          local_24 = 0;
        }
        else {
          local_24 = DAT_004e8724 + -0x10;
        }
        local_14 = local_24;
        iVar1 = local_14;
        if (DAT_004e8724 < 0x11) {
          local_28 = 0x1a;
        }
        else {
          local_28 = DAT_004e8724 + 10;
        }
        if (local_28 < (int)(uint)*(ushort *)(DAT_004e89f0 + (uint)DAT_004e871c * 0x20)) {
          if (DAT_004e8724 < 0x11) {
            local_2c = 0x1a;
          }
          else {
            local_2c = (int)DAT_004e8724 + 10;
          }
          local_30 = local_2c;
        }
        else {
          local_30 = (uint)*(ushort *)(DAT_004e89f0 + (uint)DAT_004e871c * 0x20);
        }
        local_18 = local_30;
        local_14._0_2_ = (undefined2)local_24;
        local_c = CONCAT22(local_c._2_2_,(undefined2)local_14);
        local_14 = iVar1;
        while ((local_c & 0xffff) < local_18) {
          if ((short)local_c == DAT_004e8724) {
            DAT_004e8720 = *(byte **)(*(int *)(DAT_004e89f0 + 0x14 + (uint)DAT_004e871c * 0x20) +
                                     (local_c & 0xffff) * 4);
            local_1c = DAT_004e8720;
            FUN_004266b0();
            if ((*local_1c & 1) == 0) {
              FUN_004266b0();
            }
            else {
              FUN_004266b0();
            }
            if ((*local_1c & 2) == 0) {
              FUN_004266b0();
            }
            else {
              FUN_004266b0();
            }
            FUN_004594c0();
            FUN_004594c0();
            FUN_004594c0();
            FUN_0047c470((short *)(local_1c + 0x5c));
            FUN_004594c0();
            if (*(int *)(local_1c + 8) == 0) {
              FUN_004266b0();
              FUN_004594c0();
            }
            else {
              FUN_004266b0();
              FUN_004266b0();
              FUN_004594c0();
            }
            local_34 = (uint)local_1c[1];
            switch(local_34) {
            case 0:
              FUN_004266b0();
              break;
            case 1:
              FUN_004266b0();
              break;
            case 2:
              FUN_004266b0();
              break;
            case 3:
              FUN_004266b0();
              break;
            case 4:
              FUN_004266b0();
              FUN_004594c0();
              FUN_004594c0();
              FUN_004594c0();
              FUN_0047c470((short *)(*(int *)(local_1c + 0xdc) + 0x14));
              FUN_004594c0();
            }
            FUN_004594c0();
            FUN_004594c0();
            FUN_004594c0();
            FUN_004594c0();
            FUN_004594c0();
            FUN_004594c0();
            FUN_004594c0();
            FUN_004594c0();
            FUN_00459500();
          }
          else {
            FUN_004266b0();
          }
          local_c = CONCAT22(local_c._2_2_,(short)local_c + 1);
        }
      }
    }
  }
  local_8 = 0x45bfbe;
  __chkesp();
  return;
}

