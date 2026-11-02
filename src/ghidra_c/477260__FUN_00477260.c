/* FUN_00477260 @ 00477260 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00477260(void)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_54 [20];
  
  puVar5 = local_54;
  for (iVar4 = 0x14; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  sVar2 = (short)(0xa000 / (ulonglong)DAT_004be3c8);
  sVar1 = (short)(DAT_004be3c8 >> 1);
  _DAT_004f15e8 = sVar1 - sVar2;
  _DAT_004f15f0 = sVar1 + sVar2;
  _DAT_004f15f8 = sVar1 - sVar2;
  _DAT_004f1600 = sVar1 + sVar2;
  sVar2 = (short)(0x1e00 / (ulonglong)DAT_004be3cc);
  sVar1 = (short)(DAT_004be3cc >> 1);
  _DAT_004f15ea = sVar1 - sVar2;
  _DAT_004f15f2 = sVar1 - sVar2;
  _DAT_004f15fa = sVar1 + sVar2;
  _DAT_004f1602 = sVar1 + sVar2;
  DAT_004f15e6 = 0xff;
  DAT_004f15e5 = 0xff;
  DAT_004f15e4 = 0xff;
  sVar2 = (short)(0x5000 / (ulonglong)DAT_004be3c8);
  sVar1 = (short)(DAT_004be3c8 >> 1);
  _DAT_004f15a8 = sVar1 - sVar2;
  _DAT_004f15b0 = sVar1 + sVar2;
  _DAT_004f15b8 = sVar1 - sVar2;
  _DAT_004f15c0 = sVar1 + sVar2;
  sVar2 = (short)(0x1e00 / (ulonglong)DAT_004be3cc);
  sVar1 = (short)(DAT_004be3cc >> 2);
  _DAT_004f15aa = sVar1 - sVar2;
  _DAT_004f15b2 = sVar1 - sVar2;
  _DAT_004f15ba = sVar1 + sVar2;
  _DAT_004f15c2 = sVar1 + sVar2;
  DAT_004f15a6 = 0xff;
  DAT_004f15a5 = 0xff;
  DAT_004f15a4 = 0xff;
  sVar3 = (short)(DAT_004be3cc >> 2) * 3;
  sVar2 = (short)(0xa000 / (ulonglong)DAT_004be3c8);
  sVar1 = (short)(DAT_004be3c8 >> 1);
  _DAT_004f17c8 = sVar1 - sVar2;
  _DAT_004f17d0 = sVar1 + sVar2;
  _DAT_004f17d8 = sVar1 - sVar2;
  _DAT_004f17e0 = sVar1 + sVar2;
  sVar1 = (short)(0xf00 / (ulonglong)DAT_004be3cc);
  _DAT_004f17ca = sVar3 - sVar1;
  _DAT_004f17d2 = sVar3 - sVar1;
  _DAT_004f17da = sVar3 + sVar1;
  _DAT_004f17e2 = sVar3 + sVar1;
  DAT_004f17c6 = 0xff;
  DAT_004f17c5 = 0xff;
  DAT_004f17c4 = 0xff;
  sVar2 = (short)(0xa000 / (ulonglong)DAT_004be3c8);
  sVar1 = (short)(DAT_004be3c8 >> 1);
  _DAT_004f1688 = sVar1 - sVar2;
  _DAT_004f1690 = sVar1 + sVar2;
  _DAT_004f1698 = sVar1 - sVar2;
  _DAT_004f16a0 = sVar1 + sVar2;
  sVar2 = (short)(0x1e00 / (ulonglong)DAT_004be3cc);
  sVar1 = (short)(DAT_004be3cc >> 1);
  _DAT_004f168a = sVar1 - sVar2;
  _DAT_004f1692 = sVar1 - sVar2;
  _DAT_004f169a = sVar1 + sVar2;
  _DAT_004f16a2 = sVar1 + sVar2;
  DAT_004f1686 = 0xff;
  DAT_004f1685 = 0xff;
  DAT_004f1684 = 0xff;
  _DAT_004f16b0 = *(undefined4 *)(&DAT_004f16f8 + DAT_004be1e8 * 4);
  DAT_004f16b8 = 3;
  _DAT_004f16b4 = &DAT_004f15e0;
  _DAT_004f1610 = DAT_004f1700;
  DAT_004f1618 = 3;
  _DAT_004f1614 = &DAT_004f15a0;
  _DAT_004f1740 = DAT_004f1760;
  DAT_004f1748 = 3;
  _DAT_004f1744 = &DAT_004f17c0;
  _DAT_004f1580 = *(undefined4 *)(&DAT_004f1750 + DAT_004e8990 * 4);
  DAT_004f1588 = 3;
  _DAT_004f1584 = &DAT_004f1680;
  return;
}

