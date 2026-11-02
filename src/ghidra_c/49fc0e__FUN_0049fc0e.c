/* FUN_0049fc0e @ 0049fc0e */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined5 __fastcall FUN_0049fc0e(undefined4 param_1,undefined1 param_2)

{
  undefined4 in_EAX;
  int unaff_EBP;
  float10 in_ST0;
  float10 fVar1;
  float10 fVar2;
  undefined4 unaff_retaddr;
  
  fVar1 = ABS(in_ST0);
  *(ushort *)(unaff_EBP + -0xa0) =
       (ushort)(_DAT_004c74fe < fVar1) << 8 | (ushort)(NAN(_DAT_004c74fe) || NAN(fVar1)) << 10 |
       (ushort)(_DAT_004c74fe == fVar1) << 0xe;
  if ((*(byte *)(unaff_EBP + -0x9f) & 0x41) == 0) {
    fVar2 = ROUND(in_ST0);
    fVar1 = (float10)0;
    *(ushort *)(unaff_EBP + -0xa0) =
         (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
         (ushort)(fVar2 == fVar1) << 0xe;
    fVar2 = in_ST0 - fVar2;
    fVar1 = (float10)0;
    *(ushort *)(unaff_EBP + -0xa0) =
         (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
         (ushort)(fVar2 == fVar1) << 0xe;
    f2xm1(ABS(fVar2));
    return CONCAT14(*(undefined1 *)(unaff_EBP + -0x9f),in_EAX);
  }
  fVar1 = (float10)0;
  *(ushort *)(unaff_EBP + -0xa0) =
       (ushort)(in_ST0 < fVar1) << 8 | (ushort)(NAN(in_ST0) || NAN(fVar1)) << 10 |
       (ushort)(in_ST0 == fVar1) << 0xe;
  if ((*(byte *)(unaff_EBP + -0x9f) & 1) == 0) {
    return CONCAT14(param_2,unaff_retaddr);
  }
  *(undefined1 *)(unaff_EBP + -0x90) = 4;
  return CONCAT14(param_2,unaff_retaddr);
}

