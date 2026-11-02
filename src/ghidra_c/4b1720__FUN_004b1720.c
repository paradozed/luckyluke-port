/* FUN_004b1720 @ 004b1720 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004b1720(undefined4 *param_1,undefined4 param_2)

{
  byte *pbVar1;
  short *psVar2;
  byte bVar3;
  int *piVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined1 *puVar10;
  byte *pbVar11;
  short *psVar12;
  
  uVar6 = DAT_004e9322;
  uVar5 = DAT_004e9320;
  piVar4 = (int *)param_1[3];
  _DAT_004e9328 = piVar4[1];
  _DAT_004e932c = piVar4 + 3;
  DAT_004e8f18 = (int *)*piVar4;
  DAT_004e9320 = (short)param_1[1];
  DAT_004e9322 = (short)param_1[2];
  puVar10 = (undefined1 *)
            ((int)DAT_004e8f18 +
            *(int *)((int)DAT_004e8f18 + (short)((ushort)*param_1 & 0x7fff) * 4 + *DAT_004e8f18) +
            *DAT_004e8f18);
  uVar9 = CONCAT11(*puVar10,(char)((uint)*param_1 >> 8)) & 0xffffff80;
  pbVar1 = puVar10 + 2;
  _DAT_004e9324 = param_2;
  for (uVar7 = (uint)(byte)puVar10[1]; uVar7 != 0; uVar7 = uVar7 - 1) {
    bVar3 = *pbVar1;
    uVar8 = (uint)pbVar1[1];
    psVar12 = &DAT_004e8f20;
    pbVar11 = pbVar1 + 4;
    DAT_004e8f1c = *(undefined4 *)pbVar1;
    if ((((byte)uVar9 ^ (byte)(uVar9 >> 8)) & 0x80) == 0) {
      do {
        pbVar1 = pbVar11 + 2;
        psVar2 = psVar12 + 1;
        *psVar12 = *(short *)pbVar11 + DAT_004e9320;
        pbVar11 = pbVar11 + 4;
        psVar12 = psVar12 + 2;
        *psVar2 = *(short *)pbVar1 + DAT_004e9322;
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
    }
    else {
      do {
        pbVar1 = pbVar11 + 2;
        psVar2 = psVar12 + 1;
        *psVar12 = DAT_004e9320 - *(short *)pbVar11;
        pbVar11 = pbVar11 + 4;
        psVar12 = psVar12 + 2;
        *psVar2 = *(short *)pbVar1 + DAT_004e9322;
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
    }
    (*(code *)(&PTR_LAB_004d1bc0)[bVar3])();
    pbVar1 = pbVar11;
  }
  DAT_004e9322 = uVar6;
  DAT_004e9320 = uVar5;
  return 0x10;
}

