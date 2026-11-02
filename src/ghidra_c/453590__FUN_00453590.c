/* FUN_00453590 @ 00453590 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00453590(void)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_90 [16];
  int local_50;
  int local_4c;
  int local_48;
  uint local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_28;
  int local_24;
  undefined4 local_20;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar4 = local_90;
  for (iVar3 = 0x23; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_10 = 0;
  if (DAT_004f2b68 == 0) {
    FUN_00453190(&DAT_004f2b6c,&DAT_004f2bbc);
    goto LAB_004541cd;
  }
  if ((DAT_004f2b65 == '\x02') && (uVar2 = FUN_004544b0(), (uVar2 & 0xff) == 0)) {
    DAT_004f2b65 = '\x01';
  }
  local_28 = *(int *)(DAT_004f2b68 + 0x90);
  local_24 = *(int *)(DAT_004f2b68 + 0x94);
  local_20 = *(undefined4 *)(DAT_004f2b68 + 0x98);
  if ((DAT_004f2b65 == '\x03') && (DAT_004e866c == '\0')) {
    if (((DAT_004f2458[4] & 8U) != 0) && (DAT_004f2c38 < local_24)) {
      DAT_004f2b70 = local_24 + DAT_004f2bf4;
      DAT_004f2c38 = local_24;
    }
    if (DAT_004f2c38 + 300 < local_24) {
      DAT_004f2b65 = '\x04';
      DAT_004bc4ec = 8000;
    }
  }
  local_8 = local_28 - DAT_004f2b8c;
  local_c = local_24 - (DAT_004f2b90 - DAT_004f2bf4);
  local_3c = local_8;
  if (local_8 < 0) {
    local_3c = -local_8;
  }
  if (local_3c < 0x1389) {
    local_40 = local_c;
    if (local_c < 0) {
      local_40 = -local_c;
    }
    if (5000 < local_40) goto LAB_004536f5;
  }
  else {
LAB_004536f5:
    if (*DAT_004f2458 == DAT_004f2b68) {
      FUN_00452d60(local_8,local_c);
      goto LAB_004541cd;
    }
  }
  if ((DAT_004f2b65 == '\0') || (DAT_004f2b65 == '\x03')) {
    local_24 = DAT_004f2c38;
  }
  FUN_00453540(&DAT_004f2b7c,&local_28);
  DAT_004f2b80 = DAT_004f2b80 + DAT_004f2bf4;
  FUN_00454390(&local_38,&DAT_004f2b7c,&DAT_004f2b6c);
  if (DAT_004f2bf8 != 3) {
    DAT_004f2bbe = FUN_004836a0(local_38,local_30);
    if (0x400 < DAT_004f2bbe) {
      DAT_004f2bbe = DAT_004f2bbe + -0x1000;
    }
    DAT_004f2bbe = -DAT_004f2bbe;
  }
  if (DAT_004f2bf8 != 4) {
    if ((DAT_004f2b65 == '\x01') || (DAT_004f2b65 == '\x04')) {
      DAT_004f2b70 = DAT_004f2b70 + (DAT_004f2b80 - DAT_004f2b90);
    }
    DAT_004f2b74 = DAT_004f2b74 + (DAT_004f2b84 - DAT_004f2b94);
  }
  local_44 = (uint)DAT_004f2bf8;
  switch(local_44) {
  case 0:
    if ((DAT_004f2458 != (int *)0x0) && (*DAT_004f2458 == DAT_004f2b68)) {
      FUN_00454250(&local_38);
      sVar1 = FUN_00454210(DAT_004f2b68);
      local_14 = (int)sVar1;
      uVar2 = FUN_004542c0(local_14);
      if ((uVar2 & 0xff) == 1) {
        if (DAT_004f2bec < local_10 * DAT_004f2bf0) {
          DAT_004f2bec = DAT_004f2bec + DAT_004f2be0;
          if (local_10 * DAT_004f2bf0 < DAT_004f2bec) {
            DAT_004f2bec = local_10 * DAT_004f2bf0;
          }
        }
        else if ((local_10 * DAT_004f2bf0 < DAT_004f2bec) &&
                (DAT_004f2bec = DAT_004f2bec - DAT_004f2be0, DAT_004f2bec < local_10 * DAT_004f2bf0)
                ) {
          DAT_004f2bec = local_10 * DAT_004f2bf0;
        }
        if (DAT_004f2b6c < DAT_004f2b7c) {
          DAT_004f2b6c = DAT_004f2b6c + DAT_004f2be0;
          if (DAT_004f2b7c < DAT_004f2b6c) {
            DAT_004f2b6c = DAT_004f2b7c;
          }
        }
        else if ((DAT_004f2b7c < DAT_004f2b6c) &&
                (DAT_004f2b6c = DAT_004f2b6c - DAT_004f2be0, DAT_004f2b6c < DAT_004f2b7c)) {
          DAT_004f2b6c = DAT_004f2b7c;
        }
      }
      else if (DAT_004f2b60 == 1) {
        if ((0x200 < local_14) && (local_14 < 0x600)) {
          local_10 = 1;
        }
        if ((0xa00 < local_14) && (local_14 < 0xe00)) {
          local_10 = -1;
        }
        if ((((DAT_004f23f8 == FUN_004688d0) || (DAT_004f23f8 == FUN_00468aa0)) ||
            (DAT_004f23f8 == FUN_004689f0)) || (DAT_004f23f8 == FUN_00468bd0)) {
          local_10 = 0;
        }
        if (DAT_004f2bec < local_10 * DAT_004f2bf0) {
          DAT_004f2bec = DAT_004f2bec + DAT_004f2be0;
          if (local_10 * DAT_004f2bf0 < DAT_004f2bec) {
            DAT_004f2bec = local_10 * DAT_004f2bf0;
          }
        }
        else if ((local_10 * DAT_004f2bf0 < DAT_004f2bec) &&
                (DAT_004f2bec = DAT_004f2bec - DAT_004f2be0, DAT_004f2bec < local_10 * DAT_004f2bf0)
                ) {
          DAT_004f2bec = local_10 * DAT_004f2bf0;
        }
      }
    }
    if (DAT_004f2bbe - _DAT_004f2c34 < 0) {
      local_48 = -(DAT_004f2bbe - _DAT_004f2c34);
    }
    else {
      local_48 = DAT_004f2bbe - _DAT_004f2c34;
    }
    if (DAT_004f2bc2 < local_48) {
      DAT_004f2b6c = DAT_004f2b6c + local_8;
      DAT_004f2bf8 = 7;
    }
    break;
  case 2:
  case 3:
    DAT_004f2b6c = DAT_004f2b6c + local_8;
    sVar1 = FUN_00454210(DAT_004f2b68);
    local_14 = (int)sVar1;
    if ((0x200 < local_14) && (local_14 < 0x600)) {
      local_10 = 1;
    }
    if ((0xa00 < local_14) && (local_14 < 0xe00)) {
      local_10 = -1;
    }
    if ((((DAT_004f23f8 == FUN_004688d0) || (DAT_004f23f8 == FUN_00468aa0)) ||
        (DAT_004f23f8 == FUN_004689f0)) || (DAT_004f23f8 == FUN_00468bd0)) {
      local_10 = 0;
    }
    if (DAT_004f2bec < local_10 * DAT_004f2bf0) {
      DAT_004f2bec = DAT_004f2bec + DAT_004f2be0;
      if (local_10 * DAT_004f2bf0 < DAT_004f2bec) {
        DAT_004f2bec = local_10 * DAT_004f2bf0;
      }
    }
    else if ((local_10 * DAT_004f2bf0 < DAT_004f2bec) &&
            (DAT_004f2bec = DAT_004f2bec - DAT_004f2be0, DAT_004f2bec < local_10 * DAT_004f2bf0)) {
      DAT_004f2bec = local_10 * DAT_004f2bf0;
    }
    if (DAT_004f2bf8 == 2) {
      DAT_004f2bbe = DAT_004f2c34;
    }
    break;
  case 4:
    DAT_004f2bbc = FUN_004836a0(local_34,local_30);
    if (DAT_004f2c2c == 2) {
      DAT_004f2bbc = DAT_004f2c34 - DAT_004f2bbc;
    }
    if (DAT_004f2bbe - _DAT_004f2c34 < 0) {
      local_4c = -(DAT_004f2bbe - _DAT_004f2c34);
    }
    else {
      local_4c = DAT_004f2bbe - _DAT_004f2c34;
    }
    if (DAT_004f2bc2 < local_4c) {
      if (DAT_004e8691 == '\0') {
        DAT_004e8691 = '\x01';
        DAT_004e8694 = DAT_004f2b7c;
      }
      DAT_004f2bbe = DAT_004f2bbe - DAT_004f2c34;
      if (DAT_004f2bc2 < DAT_004f2bbe) {
        DAT_004f2bbe = DAT_004f2bc2;
      }
      if ((int)DAT_004f2bbe < -(int)DAT_004f2bc2) {
        DAT_004f2bbe = -DAT_004f2bc2;
      }
      DAT_004f2bbe = DAT_004f2bbe + DAT_004f2c34;
    }
    else {
      DAT_004e8691 = '\0';
    }
    break;
  case 5:
    if (DAT_004f2bbe - _DAT_004f2c34 < 0) {
      local_50 = -(DAT_004f2bbe - _DAT_004f2c34);
    }
    else {
      local_50 = DAT_004f2bbe - _DAT_004f2c34;
    }
    if (DAT_004f2bc2 < local_50) {
      if (DAT_004e8691 == '\0') {
        DAT_004e8691 = '\x01';
        DAT_004e8694 = DAT_004f2b7c;
      }
      DAT_004f2bbe = DAT_004f2bbe - DAT_004f2c34;
      if (DAT_004f2bc2 < DAT_004f2bbe) {
        DAT_004f2bbe = DAT_004f2bc2;
      }
      if ((int)DAT_004f2bbe < -(int)DAT_004f2bc2) {
        DAT_004f2bbe = -DAT_004f2bc2;
      }
      DAT_004f2bbe = DAT_004f2bbe + DAT_004f2c34;
    }
    else {
      DAT_004e8691 = '\0';
    }
    break;
  case 7:
    sVar1 = FUN_00454210(DAT_004f2b68);
    local_14 = (int)sVar1;
    if ((local_8 * DAT_004e869c < 0) || (uVar2 = FUN_004542c0(local_14), (uVar2 & 0xff) != 0)) {
      DAT_004f2bf8 = 0;
    }
    else {
      FUN_00454250(&local_38);
      DAT_004f2b6c = DAT_004f2b6c + local_8;
      if (DAT_004f2bbe - _DAT_004f2c34 < 0) {
        DAT_004f2bbe = (short)_DAT_004f2c34 - DAT_004f2bc2;
        if (DAT_004f2bec < DAT_004f2bf0 * DAT_004f2c30) {
          DAT_004f2bec = DAT_004f2bec + DAT_004f2be0;
          if (DAT_004f2bf0 * DAT_004f2c30 < DAT_004f2bec) {
            DAT_004f2bec = DAT_004f2bf0 * DAT_004f2c30;
          }
        }
        else if ((DAT_004f2bf0 * DAT_004f2c30 < DAT_004f2bec) &&
                (DAT_004f2bec = DAT_004f2bec - DAT_004f2be0,
                DAT_004f2bec < DAT_004f2bf0 * DAT_004f2c30)) {
          DAT_004f2bec = DAT_004f2bf0 * DAT_004f2c30;
        }
      }
      else {
        DAT_004f2bbe = (short)_DAT_004f2c34 + DAT_004f2bc2;
        if (DAT_004f2bec < DAT_004f2bf0 * -DAT_004f2c30) {
          DAT_004f2bec = DAT_004f2bec + DAT_004f2be0;
          if (DAT_004f2bf0 * -DAT_004f2c30 < DAT_004f2bec) {
            DAT_004f2bec = DAT_004f2bf0 * -DAT_004f2c30;
          }
        }
        else if ((DAT_004f2bf0 * -DAT_004f2c30 < DAT_004f2bec) &&
                (DAT_004f2bec = DAT_004f2bec - DAT_004f2be0,
                DAT_004f2bec < DAT_004f2bf0 * -DAT_004f2c30)) {
          DAT_004f2bec = DAT_004f2bf0 * -DAT_004f2c30;
        }
      }
    }
    break;
  case 8:
    if (DAT_004f2b6c < DAT_004f2b7c) {
      DAT_004f2b6c = DAT_004f2b6c + DAT_004f2be0;
      if (DAT_004f2b7c < DAT_004f2b6c) {
        DAT_004f2b6c = DAT_004f2b7c;
      }
    }
    else if ((DAT_004f2b7c < DAT_004f2b6c) &&
            (DAT_004f2b6c = DAT_004f2b6c - DAT_004f2be0, DAT_004f2b6c < DAT_004f2b7c)) {
      DAT_004f2b6c = DAT_004f2b7c;
    }
    if (DAT_004f2b60 == 0) {
      if (DAT_004f2bec < 0) {
        DAT_004f2bec = DAT_004f2bec + DAT_004f2be0;
        if (0 < DAT_004f2bec) {
          DAT_004f2bec = 0;
        }
      }
      else if ((0 < DAT_004f2bec) && (DAT_004f2bec = DAT_004f2bec - DAT_004f2be0, DAT_004f2bec < 0))
      {
        DAT_004f2bec = 0;
      }
    }
    if ((DAT_004f23f8 != FUN_00466740) || ((local_38 == 0 && (DAT_004f2bec == 0)))) {
      DAT_004f2bf8 = 0;
    }
  }
  if (local_8 != 0) {
    DAT_004e869c = local_8;
  }
  FUN_00453540(&DAT_004f2b8c,&DAT_004f2b7c);
  FUN_00453540(&local_28,&DAT_004f2b6c);
  local_28 = local_28 + DAT_004f2bec;
  if (DAT_004f2bfa == 1) {
    FUN_004549d0();
    FUN_00454330(&local_28,&DAT_004f2c50);
    FUN_004543f0(&DAT_004f2bbc,&DAT_004f2c40);
  }
  FUN_00453190(&local_28,&DAT_004f2bbc);
  if (DAT_004f2bfa == 1) {
    FUN_00454450(&DAT_004f2bbc,&DAT_004f2c40);
  }
LAB_004541cd:
  local_8 = 0x4541dd;
  __chkesp();
  return;
}

