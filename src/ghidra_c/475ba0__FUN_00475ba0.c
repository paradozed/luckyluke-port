/* FUN_00475ba0 @ 00475ba0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00475ba0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_68 [16];
  int local_28;
  short local_24;
  short local_22;
  short local_20;
  short local_1e;
  short local_1c;
  short local_1a;
  short local_18;
  short local_16;
  int local_14;
  int local_10;
  byte *local_c;
  byte *local_8;
  
  puVar2 = local_68;
  for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = (byte *)**(undefined4 **)(DAT_004f16e0 + 8);
  local_c = (byte *)**(undefined4 **)(DAT_004f16e4 + 8);
  local_10 = FUN_0046e8d0((int)*(short *)(*(int *)(DAT_004f16e0 + 8) + 0x14));
  local_14 = FUN_0046e8d0((int)*(short *)(*(int *)(DAT_004f16e4 + 8) + 0x14));
  if (*(char *)(*(int *)(DAT_004f1578 + 4) + 0x1a) == '\0') {
    if ((int)*(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) <
        (int)(uint)*(ushort *)(*(int *)(DAT_004f1578 + 4) + 0x14)) {
      FUN_004856f0(local_8,local_10,*(short *)(*(int *)(DAT_004f1578 + 4) + 0x16),
                   *(short *)(*(int *)(DAT_004f1578 + 4) + 0x16),0x10);
      FUN_004856f0(local_c,local_14,*(short *)(*(int *)(DAT_004f1578 + 4) + 0x16),
                   *(short *)(*(int *)(DAT_004f1578 + 4) + 0x16),0x10);
      local_18 = (short)((uint)*(ushort *)(*(int *)(DAT_004f1578 + 4) + 0x1c) * DAT_004be3c8 >> 9);
      local_16 = (short)((uint)*(ushort *)(*(int *)(DAT_004f1578 + 4) + 0x3c) * DAT_004be3c8 >> 9);
      local_1c = (short)((uint)*(ushort *)(*(int *)(DAT_004f1578 + 4) + 0x1e) * DAT_004be3cc >> 8);
      local_1a = (short)((uint)*(ushort *)(*(int *)(DAT_004f1578 + 4) + 0x3e) * DAT_004be3cc >> 8);
      FUN_004739f0((int)local_8,(int)local_18,(int)local_1c,0x11);
      FUN_004739f0((int)local_c,(int)local_16,(int)local_1a,0x11);
      *(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) =
           *(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) + 1;
    }
    else {
      *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x16) = 0;
      *(undefined1 *)(*(int *)(DAT_004f1578 + 4) + 0x1a) = 1;
    }
  }
  else {
    FUN_004856f0(local_8,local_10,*(short *)(*(int *)(DAT_004f1578 + 4) + 0x12),
                 *(short *)(*(int *)(DAT_004f1578 + 4) + 0x12),0x10);
    FUN_004856f0(local_c,local_14,*(short *)(*(int *)(DAT_004f1578 + 4) + 0x32),
                 *(short *)(*(int *)(DAT_004f1578 + 4) + 0x32),0x10);
    local_20 = (short)((uint)*(ushort *)(*(int *)(DAT_004f1578 + 4) + 0x1c) * DAT_004be3c8 >> 9);
    local_1e = (short)((uint)*(ushort *)(*(int *)(DAT_004f1578 + 4) + 0x3c) * DAT_004be3c8 >> 9);
    local_24 = (short)((uint)*(ushort *)(*(int *)(DAT_004f1578 + 4) + 0x1e) * DAT_004be3cc >> 8);
    local_22 = (short)((uint)*(ushort *)(*(int *)(DAT_004f1578 + 4) + 0x3e) * DAT_004be3cc >> 8);
    FUN_004739f0((int)local_8,(int)local_20,(int)local_24,0x11);
    FUN_004739f0((int)local_c,(int)local_1e,(int)local_22,0x11);
    local_28 = DAT_004e8914 - 0xf;
    switch(DAT_004e8914) {
    case 0xf:
      if ((DAT_004e8812 == '\0') && (DAT_004f2564 != '\0')) {
        if (DAT_004f2596 == 2) {
          FUN_00473bf0(&DAT_004b33d4,(int)DAT_004f1780,(uint)(DAT_004be3c8 * 0xa2) >> 9,
                       (uint)(DAT_004be3cc * 0x30) >> 8);
        }
        else {
          FUN_00473bf0(&DAT_004b33d4,(int)DAT_004f1780,(uint)(DAT_004be3c8 * 0x140) >> 9,
                       (uint)(DAT_004be3cc * 0x30) >> 8);
        }
      }
      break;
    case 0x14:
      FUN_00473bf0(&DAT_004b33d4,(int)DAT_004f1780,(uint)(DAT_004be3c8 * 0x82) >> 9,
                   (uint)(DAT_004be3cc * 0x30) >> 8);
      FUN_00475ab0(0,0x78);
      FUN_00475ab0(1,0x6e);
      break;
    case 0x15:
      FUN_00473bf0(&DAT_004b33d4,(int)DAT_004f1780,(uint)(DAT_004be3c8 * 0x16a) >> 9,
                   (uint)(DAT_004be3cc * 0x30) >> 8);
      FUN_00475ab0(0,0x78);
      FUN_00475ab0(1,0x6e);
      break;
    case 0x16:
      if (DAT_004f2564 != '\0') {
        FUN_00473bf0(&DAT_004b33d4,(int)DAT_004f1780,(uint)(DAT_004be3c8 * 0x140) >> 9,
                     (uint)(DAT_004be3cc * 0x30) >> 8);
      }
      break;
    case 0x1c:
      FUN_00475ab0(0,0x78);
      FUN_00475ab0(1,0x6e);
    }
  }
  local_8 = (byte *)0x476036;
  __chkesp();
  return;
}

