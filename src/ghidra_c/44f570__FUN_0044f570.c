/* FUN_0044f570 @ 0044f570 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044f570(void)

{
  undefined2 uVar1;
  uint uVar2;
  ushort uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_60 [16];
  uint local_20;
  undefined2 local_14;
  undefined4 local_10;
  undefined4 local_8;
  
  puVar5 = local_60;
  for (iVar4 = 0x17; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  uVar1 = (undefined2)(local_10 >> 0x10);
  local_10 = local_10 & 0xffff0000;
  local_14 = 0;
  local_20 = (uint)DAT_004e863c;
  switch(local_20) {
  case 0:
    local_10 = CONCAT22(uVar1,10);
    break;
  case 1:
    local_10 = CONCAT22(uVar1,10);
    break;
  case 2:
    local_10 = CONCAT22(uVar1,10);
    break;
  case 3:
    local_10 = CONCAT22(uVar1,10);
    break;
  case 4:
    local_10 = CONCAT22(uVar1,0xc);
    break;
  case 5:
    local_10 = CONCAT22(uVar1,0xc);
    break;
  case 6:
    local_10 = CONCAT22(uVar1,0xc);
  }
  if (DAT_004e863e == 0) {
    uVar2 = FUN_0046d700();
    if ((local_10 & 0xffff) < (uVar2 & 0xffff) % 0x12) {
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
    uVar2 = FUN_0046d700();
    if ((local_10 & 0xffff) < (uVar2 & 0xffff) % 0x12) {
      DAT_004e863e = DAT_004e863e ^ 1;
      *(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) =
           *(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) + 1;
    }
    else {
      *(short *)(*(int *)(DAT_004f1578 + 4) + 0x38) =
           *(short *)(*(int *)(DAT_004f1578 + 4) + 0x38) + -1;
    }
  }
  if ((int)(uint)DAT_004bd066 <= (int)*(short *)(*(int *)(DAT_004f1578 + 4) + 0x36)) {
    DAT_004e863f = 1;
  }
  uVar3 = 0;
  do {
    if (10 < uVar3) {
LAB_0044f741:
      local_8 = 0x44f74e;
      __chkesp();
      return;
    }
    if ((int)*(short *)(*(int *)(DAT_004f1578 + 4) + 0x36) <
        (int)(uint)(ushort)(&DAT_004bd054)[uVar3]) {
      *(ushort *)(*(int *)(DAT_004f1578 + 4) + 0x32) = uVar3;
      goto LAB_0044f741;
    }
    uVar3 = uVar3 + 1;
  } while( true );
}

