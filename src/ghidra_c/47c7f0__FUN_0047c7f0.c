/* FUN_0047c7f0 @ 0047c7f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047c7f0(undefined2 *param_1,short param_2,short param_3,short param_4)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined4 local_68 [25];
  
  puVar12 = local_68;
  for (iVar6 = 0x19; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar12 = 0xcccccccc;
    puVar12 = puVar12 + 1;
  }
  sVar2 = (short)((int)((int)param_2 + ((int)param_2 >> 0x1f & 3U)) >> 2);
  sVar3 = (short)((int)((int)param_3 + ((int)param_3 >> 0x1f & 3U)) >> 2);
  sVar4 = (short)((int)((int)param_4 + ((int)param_4 >> 0x1f & 3U)) >> 2);
  sVar1 = *(short *)(&DAT_004c6534 + ((int)sVar2 & 0x3ffU) * 2);
  iVar6 = (int)*(short *)(&DAT_004c6534 + ((int)sVar3 & 0x3ffU) * 2);
  iVar9 = (int)*(short *)(&DAT_004c6534 + ((int)sVar4 & 0x3ffU) * 2);
  iVar7 = (int)*(short *)(&DAT_004c6534 + ((int)sVar2 + 0x100U & 0x3ff) * 2);
  iVar5 = (int)*(short *)(&DAT_004c6534 + ((int)sVar3 + 0x100U & 0x3ff) * 2);
  iVar10 = (int)*(short *)(&DAT_004c6534 + ((int)sVar4 + 0x100U & 0x3ff) * 2);
  iVar8 = sVar1 * iVar6 >> 0xc;
  iVar11 = sVar1 * iVar5 >> 0xc;
  *param_1 = (short)(iVar10 * iVar5 + iVar9 * iVar8 >> 0xc);
  param_1[1] = (short)(iVar10 * iVar8 - iVar9 * iVar5 >> 0xc);
  param_1[2] = (short)(iVar7 * iVar6 >> 0xc);
  param_1[3] = (short)(iVar9 * iVar7 >> 0xc);
  param_1[4] = (short)(iVar10 * iVar7 >> 0xc);
  param_1[5] = -sVar1;
  param_1[6] = (short)(iVar9 * iVar11 - iVar6 * iVar10 >> 0xc);
  param_1[7] = (short)(iVar6 * iVar9 + iVar10 * iVar11 >> 0xc);
  param_1[8] = (short)(iVar7 * iVar5 >> 0xc);
  return;
}

