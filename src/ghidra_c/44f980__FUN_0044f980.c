/* FUN_0044f980 @ 0044f980 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044f980(void)

{
  undefined2 uVar1;
  short sVar2;
  uint uVar3;
  ushort uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_58 [16];
  uint local_18;
  undefined4 local_14;
  uint local_10;
  short local_c;
  undefined4 local_8;
  
  puVar6 = local_58;
  for (iVar5 = 0x15; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0xcccccccc;
    puVar6 = puVar6 + 1;
  }
  local_c = 0;
  local_10 = local_10 & 0xffff0000;
  uVar1 = (undefined2)(local_14 >> 0x10);
  local_14 = local_14 & 0xffff0000;
  if (DAT_004e8618 == 0) {
    if ((DAT_004f2750 & 0x8000) == 0) {
      *(short *)(*(int *)(DAT_004f1578 + 4) + 0x18) =
           *(short *)(*(int *)(DAT_004f1578 + 4) + 0x18) + -3;
    }
    else {
      DAT_004e8618 = 1;
      *(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) =
           *(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) + 3;
    }
  }
  else if ((DAT_004f2750 & 0x2000) == 0) {
    *(short *)(*(int *)(DAT_004f1578 + 4) + 0x18) =
         *(short *)(*(int *)(DAT_004f1578 + 4) + 0x18) + -3;
  }
  else {
    DAT_004e8618 = DAT_004e8618 ^ 1;
    *(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) =
         *(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) + 3;
  }
  if (*(short *)(*(int *)(DAT_004f1578 + 4) + 0x18) < 1) {
    *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x18) =
         *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x14);
    *(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) =
         *(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) + -1;
  }
  local_18 = (uint)DAT_004e863c;
  switch(local_18) {
  case 0:
    local_14 = CONCAT22(uVar1,4);
    break;
  case 1:
    local_14 = CONCAT22(uVar1,4);
    break;
  case 2:
    local_14 = CONCAT22(uVar1,4);
    break;
  case 3:
    local_14 = CONCAT22(uVar1,3);
    break;
  case 4:
    local_14 = CONCAT22(uVar1,4);
    break;
  case 5:
    local_14 = CONCAT22(uVar1,5);
    break;
  case 6:
    local_14 = CONCAT22(uVar1,6);
  }
  if (DAT_004e863e == 0) {
    uVar3 = FUN_0046d700();
    if ((local_14 & 0xffff) < (uVar3 & 0xffff) % 9) {
      DAT_004e863e = DAT_004e863e ^ 1;
      *(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) =
           *(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) + 1;
    }
    else {
      *(short *)(*(int *)(DAT_004f1578 + 4) + 0x38) =
           *(short *)(*(int *)(DAT_004f1578 + 4) + 0x38) + -1;
    }
  }
  else {
    uVar3 = FUN_0046d700();
    if ((uVar3 & 0xffff) % 9 < 5) {
      *(short *)(*(int *)(DAT_004f1578 + 4) + 0x38) =
           *(short *)(*(int *)(DAT_004f1578 + 4) + 0x38) + -1;
    }
    else {
      DAT_004e863e = DAT_004e863e ^ 1;
      *(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) =
           *(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) + 1;
    }
  }
  DAT_004f2c68 = DAT_004e8abc >> 5;
  if (DAT_004e862c == 0) {
    DAT_004e862c = DAT_004e8abc >> 5;
  }
  if (0x96 < DAT_004f2c68 - DAT_004e862c) {
    DAT_004e862c = 0;
    sVar2 = *(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) + -10;
    local_10 = CONCAT22(local_10._2_2_,sVar2);
    uVar3 = FUN_0046d700();
    local_c = sVar2 + (short)((ulonglong)(uVar3 & 0xffff) % 0x14);
    if (*(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) <
        *(short *)(*(int *)(DAT_004f1578 + 4) + 0x16)) {
      DAT_004e8610 = 1;
    }
    else {
      DAT_004e863f = 1;
    }
    *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x16) = 0;
    *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x36) = 0;
  }
  uVar4 = 0;
  do {
    if (10 < uVar4) {
LAB_0044fd00:
      local_8 = 0x44fd0d;
      __chkesp();
      return;
    }
    if ((int)*(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) <
        (int)(uint)(ushort)(&DAT_004bd054)[uVar4]) {
      *(ushort *)(*(int *)(DAT_004f1578 + 4) + 0x12) = uVar4;
      goto LAB_0044fd00;
    }
    uVar4 = uVar4 + 1;
  } while( true );
}

