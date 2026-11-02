/* FUN_004a062e @ 004a062e */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a062e(void)

{
  char cVar1;
  int unaff_EBP;
  ushort in_FPUStatusWord;
  float10 in_ST0;
  
  DAT_004e8d18 = '\0';
  if (DAT_004e8c5c != 0) {
    DAT_004e8d18 = 0;
    return;
  }
  _DAT_004e8d10 = (double)in_ST0;
  cVar1 = *(char *)(unaff_EBP + -0x90);
  if (cVar1 != '\0') {
    if ((cVar1 != -1) && (cVar1 != -2)) {
      if (cVar1 == '\0') {
        DAT_004e8d18 = 0;
        return;
      }
      *(int *)(unaff_EBP + -0x8e) = (int)cVar1;
      goto LAB_004a0703;
    }
    if (((ulonglong)_DAT_004e8d10 & 0x7ff0000000000000) == 0) {
      *(undefined4 *)(unaff_EBP + -0x8e) = 4;
      in_ST0 = (float10)fscale(in_ST0,(float10)_DAT_004bb4a8);
      if (ABS(in_ST0) < (float10)_DAT_004bb498) {
        in_ST0 = in_ST0 * (float10)_DAT_004bb4b8;
      }
      goto LAB_004a0703;
    }
    if ((DAT_004e8d16 & 0x7ff0) == 0x7ff0) {
      *(undefined4 *)(unaff_EBP + -0x8e) = 3;
      in_ST0 = (float10)fscale(in_ST0,(float10)_DAT_004bb4a0);
      if ((float10)_DAT_004bb490 < ABS(in_ST0)) {
        in_ST0 = in_ST0 * (float10)_DAT_004bb4b0;
      }
      goto LAB_004a0703;
    }
  }
  if ((*(ushort *)(unaff_EBP + -0xa4) & 0x20) != 0) {
    DAT_004e8d18 = 0;
    return;
  }
  if ((in_FPUStatusWord & 0x20) == 0) {
    DAT_004e8d18 = 0;
    return;
  }
  *(undefined4 *)(unaff_EBP + -0x8e) = 8;
LAB_004a0703:
  *(int *)(unaff_EBP + -0x8a) = *(int *)(unaff_EBP + -0x94) + 1;
  if (DAT_004e8d18 == '\0') {
    *(undefined4 *)(unaff_EBP + -0x86) = *(undefined4 *)(unaff_EBP + 8);
    *(undefined4 *)(unaff_EBP + -0x82) = *(undefined4 *)(unaff_EBP + 0xc);
    if (*(char *)(*(int *)(unaff_EBP + -0x94) + 0xd) != '\x01') {
      *(undefined4 *)(unaff_EBP + -0x7e) = *(undefined4 *)(unaff_EBP + 0x10);
      *(undefined4 *)(unaff_EBP + -0x7a) = *(undefined4 *)(unaff_EBP + 0x14);
    }
  }
  *(double *)(unaff_EBP + -0x76) = (double)in_ST0;
  FUN_004a7120((int)*(char *)(*(int *)(unaff_EBP + -0x94) + 0xe),(_exception *)(unaff_EBP + -0x8e),
               (ushort *)(unaff_EBP + -0xa4));
  return;
}

