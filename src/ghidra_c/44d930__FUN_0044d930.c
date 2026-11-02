/* FUN_0044d930 @ 0044d930 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044d930(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_58 [16];
  short local_18;
  int local_c;
  int local_8;
  
  puVar3 = local_58;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_0046d700();
  DAT_004e8632 = (byte)((ulonglong)(uVar1 & 0xffff) % 100);
  local_18 = *(short *)(*(int *)(DAT_004f1578 + 4) + 0x30) -
             *(short *)(*(int *)(DAT_004f1578 + 4) + 0x10);
  if (DAT_004e8633 == '\0') {
    if (local_18 < 2) {
      if (local_18 < 1) {
        local_c = 0;
      }
      else {
        local_c = 1;
      }
    }
    else {
      DAT_004f2c68 = DAT_004e8abc >> 5;
      if (DAT_004e862c == 0) {
        DAT_004e862c = DAT_004e8abc >> 5;
      }
      if (0x5dc < DAT_004f2c68 - DAT_004e862c) {
        DAT_004e862c = 0;
        DAT_004e8633 = '\x01';
      }
      local_c = 2;
    }
  }
  else {
    DAT_004f2c68 = DAT_004e8abc >> 5;
    if (DAT_004e862c == 0) {
      DAT_004e862c = DAT_004e8abc >> 5;
    }
    if (0x5dc < DAT_004f2c68 - DAT_004e862c) {
      DAT_004e862c = 0;
      DAT_004e8633 = '\0';
    }
    local_c = 0;
  }
  if ((int)*(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) <
      *(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) + 0x1e) {
    if ((int)*(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) <
        *(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) + 0x14) {
      if ((int)*(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) <
          *(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) + 10) {
        if (*(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) <
            *(short *)(*(int *)(DAT_004f1578 + 4) + 0x16)) {
          if (*(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) <=
              *(short *)(*(int *)(DAT_004f1578 + 4) + 0x16)) {
            *(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) =
                 *(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) + 1;
          }
        }
        else if (*(ushort *)(local_c * 2 + 0x4bd076) < (ushort)DAT_004e8632) {
          *(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) =
               *(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) + -1;
        }
        else {
          *(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) =
               *(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) + 1;
        }
      }
      else if (*(ushort *)(local_c * 2 + 0x4bd080) < (ushort)DAT_004e8632) {
        *(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) =
             *(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) + -1;
      }
      else {
        *(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) =
             *(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) + 1;
      }
    }
    else if (*(ushort *)(local_c * 2 + 0x4bd08a) < (ushort)DAT_004e8632) {
      *(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) =
           *(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) + -1;
    }
    else {
      *(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) =
           *(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) + 1;
    }
  }
  else if (*(ushort *)(&DAT_004bd094 + local_c * 2) < (ushort)DAT_004e8632) {
    *(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) =
         *(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) + -1;
  }
  else {
    *(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) =
         *(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) + 1;
  }
  if (*(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) < 1) {
    *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x36) = 0;
  }
  local_8 = 0;
  do {
    if (10 < local_8) {
LAB_0044dcf7:
      local_8 = 0x44dd04;
      __chkesp();
      return;
    }
    if ((int)*(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) <
        (int)(uint)(ushort)(&DAT_004bd054)[local_8]) {
      *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x32) = (undefined2)local_8;
      goto LAB_0044dcf7;
    }
    local_8 = local_8 + 1;
  } while( true );
}

