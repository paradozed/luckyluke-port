/* FUN_004b174c @ 004b174c */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __fastcall FUN_004b174c(int *param_1,short param_2)

{
  byte *pbVar1;
  short *psVar2;
  byte bVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined4 in_EAX;
  uint uVar6;
  uint uVar7;
  short unaff_BX;
  uint uVar8;
  undefined1 *puVar9;
  byte *pbVar10;
  short *psVar11;
  
  uVar5 = DAT_004e9322;
  uVar4 = DAT_004e9320;
  puVar9 = (undefined1 *)
           ((int)param_1 +
           *(int *)((int)param_1 + (short)((ushort)in_EAX & 0x7fff) * 4 + *param_1) + *param_1);
  uVar8 = CONCAT11(*puVar9,(char)((uint)in_EAX >> 8)) & 0xffffff80;
  pbVar1 = puVar9 + 2;
  DAT_004e8f18 = param_1;
  DAT_004e9320 = param_2;
  DAT_004e9322 = unaff_BX;
  for (uVar6 = (uint)(byte)puVar9[1]; uVar6 != 0; uVar6 = uVar6 - 1) {
    bVar3 = *pbVar1;
    uVar7 = (uint)pbVar1[1];
    psVar11 = &DAT_004e8f20;
    pbVar10 = pbVar1 + 4;
    DAT_004e8f1c = *(undefined4 *)pbVar1;
    if ((((byte)uVar8 ^ (byte)(uVar8 >> 8)) & 0x80) == 0) {
      do {
        pbVar1 = pbVar10 + 2;
        psVar2 = psVar11 + 1;
        *psVar11 = *(short *)pbVar10 + DAT_004e9320;
        pbVar10 = pbVar10 + 4;
        psVar11 = psVar11 + 2;
        *psVar2 = *(short *)pbVar1 + DAT_004e9322;
        uVar7 = uVar7 - 1;
      } while (uVar7 != 0);
    }
    else {
      do {
        pbVar1 = pbVar10 + 2;
        psVar2 = psVar11 + 1;
        *psVar11 = DAT_004e9320 - *(short *)pbVar10;
        pbVar10 = pbVar10 + 4;
        psVar11 = psVar11 + 2;
        *psVar2 = *(short *)pbVar1 + DAT_004e9322;
        uVar7 = uVar7 - 1;
      } while (uVar7 != 0);
    }
    (*(code *)(&PTR_LAB_004d1bc0)[bVar3])();
    pbVar1 = pbVar10;
  }
  DAT_004e9322 = uVar5;
  DAT_004e9320 = uVar4;
  return 0x10;
}

