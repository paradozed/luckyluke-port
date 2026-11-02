/* FUN_00429040 @ 00429040 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00429040(void)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  uint local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  for (local_8 = 0; local_8 < DAT_004e2b68; local_8 = local_8 + 1) {
    iVar2 = _strcmp((char *)(&DAT_004e57dc + local_8 * 0x8a),s_3dfx_w3x_004bcecc);
    if ((iVar2 == 0) && (*(ushort *)(&DAT_004e57fc + local_8 * 0x228) == DAT_004e858c)) {
      DAT_004f58a8 = &DAT_004e57d8 + local_8 * 0x8a;
      goto LAB_004292bc;
    }
  }
  for (local_8 = 0; local_8 < DAT_004e2b68; local_8 = local_8 + 1) {
    if ((&DAT_004e57d8)[local_8 * 0x8a] == 0x33446678) {
      DAT_004f58a8 = &DAT_004e57d8 + local_8 * 0x8a;
      goto LAB_004292bc;
    }
  }
  for (local_8 = 0; local_8 < DAT_004e2b68; local_8 = local_8 + 1) {
    if (((&DAT_004e57d8)[local_8 * 0x8a] == 0x6d443344) &&
       (*(short *)(&DAT_004e57fc + local_8 * 0x228) != 0)) {
      DAT_004f58a8 = &DAT_004e57d8 + local_8 * 0x8a;
      goto LAB_004292bc;
    }
  }
  for (local_8 = 0; local_8 < DAT_004e2b68; local_8 = local_8 + 1) {
    if (((&DAT_004e57d8)[local_8 * 0x8a] == 0x6d443344) &&
       (*(short *)(&DAT_004e57fc + local_8 * 0x228) == 0)) {
      DAT_004f58a8 = &DAT_004e57d8 + local_8 * 0x8a;
      goto LAB_004292bc;
    }
  }
  cVar1 = FUN_004283d0();
  if (cVar1 == '\0') {
    for (local_8 = 0; local_8 < DAT_004e2b68; local_8 = local_8 + 1) {
      if (((&DAT_004e57d8)[local_8 * 0x8a] == 0x536f6674) &&
         (*(short *)(&DAT_004e57fc + local_8 * 0x228) == 0)) {
        DAT_004f58a8 = &DAT_004e57d8 + local_8 * 0x8a;
        break;
      }
    }
  }
  else {
    for (local_8 = 0; local_8 < DAT_004e2b68; local_8 = local_8 + 1) {
      if (((&DAT_004e57d8)[local_8 * 0x8a] == 0x536f6674) &&
         (*(short *)(&DAT_004e57fc + local_8 * 0x228) != 0)) {
        DAT_004f58a8 = &DAT_004e57d8 + local_8 * 0x8a;
        break;
      }
    }
  }
LAB_004292bc:
  local_8 = 0x4292c9;
  __chkesp();
  return;
}

