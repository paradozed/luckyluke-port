/* FUN_0042be50 @ 0042be50 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042be50(void)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_54 [20];
  
  puVar6 = local_54;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0xcccccccc;
    puVar6 = puVar6 + 1;
  }
  sVar4 = (short)(0x1e00 / (ulonglong)DAT_004be3cc);
  sVar3 = (short)DAT_004be3cc + sVar4 * -2;
  sVar2 = (short)(0xa000 / (ulonglong)DAT_004be3c8);
  sVar1 = (short)(DAT_004be3c8 >> 1);
  _DAT_004f72e8 = sVar1 - sVar2;
  _DAT_004f72f0 = sVar1 + sVar2;
  _DAT_004f72f8 = sVar1 - sVar2;
  _DAT_004f7300 = sVar1 + sVar2;
  _DAT_004f72ea = sVar3 - sVar4;
  _DAT_004f72f2 = sVar3 - sVar4;
  _DAT_004f72fa = sVar3 + sVar4;
  _DAT_004f7302 = sVar3 + sVar4;
  DAT_004f72e6 = 0xff;
  DAT_004f72e5 = 0xff;
  DAT_004f72e4 = 0xff;
  _DAT_004f7310 = *(undefined4 *)(&DAT_004f72d0 + DAT_004bc574 * 4);
  DAT_004f7318 = 3;
  _DAT_004f7314 = &DAT_004f72e0;
  return;
}

