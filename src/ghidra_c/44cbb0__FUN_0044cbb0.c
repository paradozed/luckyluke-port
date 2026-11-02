/* FUN_0044cbb0 @ 0044cbb0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044cbb0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004e8618 == 0) {
    if ((DAT_004f2750 & 0x8000) == 0) {
      DAT_004e8631 = DAT_004e8631 + '\x01';
      *(short *)(*(int *)(DAT_004f1578 + 4) + 0x18) =
           *(short *)(*(int *)(DAT_004f1578 + 4) + 0x18) + -1;
    }
    else {
      DAT_004e8618 = 1;
      *(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) =
           *(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) + 4;
      DAT_004e8631 = DAT_004e8631 + -1;
    }
  }
  else if ((DAT_004f2750 & 0x2000) == 0) {
    DAT_004e8631 = DAT_004e8631 + '\x01';
    *(short *)(*(int *)(DAT_004f1578 + 4) + 0x18) =
         *(short *)(*(int *)(DAT_004f1578 + 4) + 0x18) + -1;
  }
  else {
    DAT_004e8618 = DAT_004e8618 ^ 1;
    *(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) =
         *(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) + 4;
    DAT_004e8631 = DAT_004e8631 + -1;
  }
  if (((int)*(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) < (int)(uint)DAT_004bd068) ||
     (*(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) =
           *(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) + 0x32, (DAT_004f2750 & 0x1000) == 0)) {
    if (*(short *)(*(int *)(DAT_004f1578 + 4) + 0x18) < 1) {
      *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x18) =
           *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x14);
      *(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) =
           *(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) + -2;
    }
    if (*(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) < 0) {
      *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x16) = 0;
    }
    for (local_8 = 0; local_8 < 0xb; local_8 = local_8 + 1) {
      if ((int)*(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) <
          (int)(uint)(ushort)(&DAT_004bd054)[local_8]) {
        *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x12) = (undefined2)local_8;
        return;
      }
    }
  }
  else {
    DAT_004e8610 = 1;
  }
  return;
}

