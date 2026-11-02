/* FUN_00404700 @ 00404700 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Removing unreachable block (ram,0x00404882) */

void FUN_00404700(void)

{
  short sVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 local_88 [16];
  undefined1 local_45;
  undefined1 local_44 [4];
  undefined1 local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  short local_3c;
  short local_3a;
  undefined1 local_38;
  undefined1 local_37;
  short local_34;
  short local_32;
  undefined1 local_30;
  undefined1 local_2f;
  undefined2 local_2e;
  short local_2c;
  short local_2a;
  undefined1 local_28;
  undefined1 local_27;
  short local_24;
  short local_22;
  undefined1 local_20;
  undefined1 local_1f;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  undefined1 local_c;
  PVOID local_8;
  
  puVar7 = local_88;
  for (iVar4 = 0x21; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = 0xcccccccc;
    puVar7 = puVar7 + 1;
  }
  if ((DAT_004d1db3 & DAT_004d1db1) != 0) {
    local_14 = (uint)DAT_004d1db2 * 0x2d + 0x22;
    if (DAT_004d1db2 == 3) {
      local_10 = 0xe7;
      local_18 = 0x2e;
      local_1c = 0x1d;
      local_14 = 0xaa;
    }
    else if (DAT_004d1db2 < 3) {
      local_10 = 0xc2;
      local_18 = 0x79;
      local_1c = 0x1d;
    }
    if (DAT_004d1db2 < 4) {
      local_10 = local_10 * DAT_004be3c8 >> 9;
      uVar6 = local_14 * DAT_004be3cc >> 8;
      local_18 = local_18 * DAT_004be3c8 >> 9;
      uVar5 = local_1c * DAT_004be3cc >> 8;
      if (*DAT_004f58a8 == 0x536f6674) {
        local_1c = uVar5;
        local_14 = uVar6;
        (*DAT_005089f8)(local_10,uVar6,local_18,uVar5,0xff,0xff,0x40,0x5a);
        __chkesp();
      }
      else {
        local_1c._0_2_ = (short)(local_1c * DAT_004be3cc >> 8);
        sVar1 = (short)local_1c;
        local_14._0_2_ = (short)(local_14 * DAT_004be3cc >> 8);
        sVar2 = (short)local_14;
        local_1c = uVar5;
        local_14 = uVar6;
        local_8 = (PVOID)FUN_00440e80((short)local_10,sVar2,(short)local_18,sVar1);
        *(undefined1 *)((int)local_8 + 4) = 0xff;
        *(undefined1 *)((int)local_8 + 5) = 0xff;
        *(undefined1 *)((int)local_8 + 6) = 0x40;
        *(byte *)((int)local_8 + 7) = *(byte *)((int)local_8 + 7) | 2;
        local_45 = *(undefined1 *)((int)local_8 + 7);
        (*DAT_004e8a6c)(0x5a);
        uVar3 = __chkesp();
        local_c = (undefined1)uVar3;
        (*DAT_004e8a30)();
        __chkesp();
        (*DAT_004e8a44)(local_8,0,0,0,0);
        __chkesp();
        (*DAT_004e8a6c)(local_c);
        __chkesp();
        FUN_00439c30(local_8);
      }
      local_10 = (DAT_004be3c8 >> 1) - 0x38;
      local_18 = (DAT_004be3c8 * 0x71) / 0x280;
      local_1c = (uint)(DAT_004be3cc * 0x15) / 0x1e0;
      local_14 = (DAT_004be3cc - local_1c) - ((uint)(DAT_004be3cc * 0x23) >> 8);
      local_3c = (short)local_10;
      local_3a = (short)local_14;
      local_34 = (short)local_10 + (short)local_18;
      local_32 = (short)local_14;
      local_2c = (short)local_10;
      local_2a = (short)local_14 + (short)local_1c;
      local_24 = (short)local_10 + (short)local_18;
      local_22 = (short)local_14 + (short)local_1c;
      local_38 = 0;
      local_37 = 0x50;
      local_30 = 0x71;
      local_2f = 0x50;
      local_28 = 0;
      local_27 = 100;
      local_20 = 0x71;
      local_1f = 100;
      local_3e = 0xff;
      local_3f = 0xff;
      local_40 = 0xff;
      local_2e = 0xd;
      (*DAT_004e8a30)();
      __chkesp();
      (*DAT_004e8a54)(local_44,0x11,0x11,0x11,0x11);
      __chkesp();
    }
    else {
      local_10 = (DAT_004be3c8 >> 1) - 0x38;
      local_18 = (DAT_004be3c8 * 0x71) / 0x280;
      local_1c = (uint)(DAT_004be3cc * 0x15) / 0x1e0;
      local_14 = (DAT_004be3cc - local_1c) - ((uint)(DAT_004be3cc * 0x23) >> 8);
      local_3c = (short)local_10;
      local_3a = (short)local_14;
      local_34 = (short)local_10 + (short)local_18;
      local_32 = (short)local_14;
      local_2c = (short)local_10;
      local_2a = (short)local_14 + (short)local_1c;
      local_24 = (short)local_10 + (short)local_18;
      local_22 = (short)local_14 + (short)local_1c;
      local_38 = 0;
      local_37 = 0x65;
      local_30 = 0x71;
      local_2f = 0x65;
      local_28 = 0;
      local_27 = 0x7a;
      local_20 = 0x71;
      local_1f = 0x7a;
      local_3e = 0xff;
      local_3f = 0xff;
      local_40 = 0xff;
      local_2e = 0xd;
      (*DAT_004e8a30)();
      __chkesp();
      (*DAT_004e8a54)(local_44,0x11,0x11,0x11,0x11);
      __chkesp();
    }
  }
  local_8 = (PVOID)0x404b09;
  __chkesp();
  return;
}

