/* FUN_004556d0 @ 004556d0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004556d0(void)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_c4 [16];
  int local_84;
  int local_80;
  int local_7c;
  short local_78;
  ushort local_74;
  short local_70;
  short local_6c;
  short local_6a;
  undefined2 local_68;
  undefined2 local_66;
  int local_64 [4];
  undefined4 local_54 [8];
  undefined4 local_34 [8];
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar4 = local_c4;
  for (iVar3 = 0x30; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_8 = 0;
  local_6c = 0;
  local_6a = 0;
  local_68 = 0;
  local_66 = 0;
  local_14 = *(int *)(*DAT_004f2458 + 0x90);
  local_10 = *(undefined4 *)(*DAT_004f2458 + 0x94);
  local_c = *(undefined4 *)(*DAT_004f2458 + 0x98);
  local_74 = (short)DAT_004f2458[0x29] - 0x800U & 0xfff;
  if (DAT_004e8640 == '\x01') {
    DAT_004e868a = DAT_004e868a + local_74;
    DAT_004e8640 = '\0';
    DAT_004e8660 = local_74;
  }
  uVar2 = FUN_00455380();
  if ((uVar2 & 0xff) == 0) {
    if (local_74 != DAT_004e8660) {
      local_70 = local_74 - DAT_004e8660;
      if (0x800 < local_70) {
        local_70 = local_70 + -0x1000;
      }
      if (local_70 < -0x800) {
        local_70 = local_70 + 0x1000;
      }
      DAT_004e8658 = DAT_004e8658 + local_70;
      DAT_004e8660 = local_74;
      if ((DAT_004e8641 == '\0') || (DAT_004e8641 == '\x01')) {
        if (DAT_004e8658 < 0x33) {
          if (DAT_004e8658 < -0x32) {
            DAT_004e8654 = DAT_004e8654 + -0x400;
            DAT_004e8641 = '\x02';
          }
        }
        else {
          DAT_004e8654 = DAT_004e8654 + 0x400;
          DAT_004e8641 = '\x02';
        }
      }
      local_7c = DAT_004e8658;
      if (DAT_004e8658 < 0) {
        local_7c = -DAT_004e8658;
      }
      if (0x39c < local_7c) {
        DAT_004e8658 = 0;
        if (DAT_004e8641 == '\x03') {
          DAT_004e8641 = '\0';
        }
        else {
          DAT_004e8641 = '\x01';
        }
      }
    }
    if ((DAT_004e8641 == '\x02') || (DAT_004e8641 == '\x01')) {
      local_78 = (short)(DAT_004f2458[0x2b] / 10);
      if (local_78 < 0x3c) {
        local_78 = 0x3c;
      }
      if (DAT_004e8652 < DAT_004e8654) {
        DAT_004e8652 = DAT_004e8652 + local_78;
        if (DAT_004e8654 < DAT_004e8652) {
          DAT_004e8652 = DAT_004e8654;
        }
      }
      else if ((DAT_004e8654 < DAT_004e8652) &&
              (DAT_004e8652 = DAT_004e8652 - local_78, DAT_004e8652 < DAT_004e8654)) {
        DAT_004e8652 = DAT_004e8654;
      }
      if (DAT_004e8652 == DAT_004e8654) {
        DAT_004e868a = DAT_004e868a + DAT_004e8654;
        DAT_004e8654 = 0;
        DAT_004e8652 = 0;
        if (DAT_004e8641 == '\x01') {
          DAT_004e8641 = '\0';
        }
        else {
          DAT_004e8641 = '\x03';
        }
      }
    }
  }
  local_74 = *(short *)((int)DAT_004f2458 + 0xa6);
  local_70 = local_74 - DAT_004e8650;
  if (local_70 < 0) {
    local_80 = -(int)local_70;
  }
  else {
    local_80 = (int)local_70;
  }
  if (0x800 < local_80) {
    if (local_70 < 1) {
      local_70 = local_70 + 0x1000;
    }
    else {
      local_70 = local_70 + -0x1000;
    }
  }
  if (local_70 < 0) {
    local_84 = -(int)local_70;
  }
  else {
    local_84 = (int)local_70;
  }
  sVar1 = local_74;
  if (0x14 < local_84) {
    if (local_70 < 1) {
      sVar1 = DAT_004e8650 + -0x15;
    }
    else {
      sVar1 = DAT_004e8650 + 0x15;
    }
  }
  DAT_004e8650 = sVar1;
  uVar2 = (int)DAT_004e8650 & 0x80000fff;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xfffff000) + 1;
  }
  DAT_004e8650 = (short)uVar2;
  if (DAT_004f2458[0x2b] == 0x578) {
    DAT_004e8642 = '\x01';
    DAT_004e8648 = 0xfff1;
  }
  if (DAT_004e8642 == '\x01') {
    FUN_00455620();
  }
  local_6c = DAT_004e8650 + DAT_004e8688;
  local_6a = DAT_004e8652 + DAT_004e868a;
  local_68 = DAT_004e868c;
  FUN_00482a90(&local_6c,local_34);
  FUN_004835d0((undefined2 *)local_34,(undefined2 *)local_54);
  FUN_00482760(local_54,&DAT_004bd6a0,local_64);
  FUN_00454330(&local_14,local_64);
  if (DAT_004f2bf8 != 0xb) {
    FUN_00451ab0(&local_14,&local_6c,DAT_004e864c);
  }
  local_8 = 0x455bbf;
  __chkesp();
  return;
}

