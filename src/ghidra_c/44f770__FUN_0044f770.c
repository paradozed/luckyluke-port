/* FUN_0044f770 @ 0044f770 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0044f770(byte param_1,byte param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [17];
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (DAT_004e8618 == 0) {
    if ((DAT_004f2750 & 0x8000) == 0) {
      *(ushort *)(*(int *)(DAT_004f1578 + 4) + 0x18) =
           *(short *)(*(int *)(DAT_004f1578 + 4) + 0x18) - (ushort)param_2;
    }
    else {
      DAT_004e8618 = 1;
      *(ushort *)(*(int *)(DAT_004f1578 + 4) + 0x16) =
           *(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) + (ushort)param_1;
    }
  }
  else if ((DAT_004f2750 & 0x2000) == 0) {
    *(ushort *)(*(int *)(DAT_004f1578 + 4) + 0x18) =
         *(short *)(*(int *)(DAT_004f1578 + 4) + 0x18) - (ushort)param_2;
  }
  else {
    DAT_004e8618 = DAT_004e8618 ^ 1;
    *(ushort *)(*(int *)(DAT_004f1578 + 4) + 0x16) =
         *(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) + (ushort)param_1;
  }
  if (((int)*(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) < (int)(uint)DAT_004bd066) ||
     (*(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) =
           *(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) + 0x32, (DAT_004f2750 & 0x1000) == 0)) {
    if (*(short *)(*(int *)(DAT_004f1578 + 4) + 0x18) < 1) {
      *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x18) =
           *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x14);
      *(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) =
           *(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) + -1;
    }
    if (*(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) < 0) {
      *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x16) = 0;
    }
    for (uVar1 = 0; uVar1 < 0xb; uVar1 = uVar1 + 1) {
      if ((int)*(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) <
          (int)(uint)(ushort)(&DAT_004bd054)[uVar1]) {
        *(ushort *)(*(int *)(DAT_004f1578 + 4) + 0x12) = uVar1;
        return;
      }
    }
  }
  else {
    DAT_004e8610 = 1;
  }
  return;
}

