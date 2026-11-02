/* FUN_00401000 @ 00401000 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall
FUN_00401000(undefined4 param_1,undefined4 param_2,short *param_3,byte *param_4)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  char cVar4;
  short sVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  byte bVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  
  if ((*param_3 != 0x4e52) || (param_3[1] != 0x243)) {
    iVar3 = 0;
LAB_004011ad:
    return CONCAT44(param_2,iVar3);
  }
  DAT_004bc050 = FUN_004011b4();
  _DAT_004bc054 = FUN_004011b4();
  pbVar12 = (byte *)(param_3 + 5);
  pbVar8 = (byte *)((int)param_3 + _DAT_004bc054 + 0x12);
  if ((param_4 < pbVar8) && (pbVar8 < param_4 + (uint)*(byte *)(param_3 + 8) + DAT_004bc050)) {
    uVar6 = _DAT_004bc054 >> 2;
    pbVar12 = param_4 + (uint)*(byte *)(param_3 + 8) + DAT_004bc050;
    while( true ) {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      *(undefined4 *)(pbVar12 + -4) = *(undefined4 *)(pbVar8 + -4);
      pbVar8 = pbVar8 + -4;
      pbVar12 = pbVar12 + -4;
    }
    uVar6 = _DAT_004bc054 & 3;
    if ((short)uVar6 != 0) {
      while( true ) {
        pbVar8 = pbVar8 + -1;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pbVar12[-1] = *pbVar8;
        pbVar12 = pbVar12 + -1;
      }
    }
  }
  pbVar8 = pbVar12 + 1;
  bVar2 = (*pbVar12 * '\x02' + '\x01') * '\x02';
LAB_0040112f:
  while (bVar9 = bVar2 * '\x02', bVar1 = bVar9, !CARRY1(bVar2,bVar2)) {
    pbVar11 = param_4 + 1;
    pbVar12 = pbVar8 + 1;
    *param_4 = *pbVar8;
    bVar2 = bVar2 << 2;
    pbVar8 = pbVar12;
    param_4 = pbVar11;
    bVar1 = bVar2;
    if (CARRY1(bVar9,bVar9)) break;
LAB_0040112e:
    param_4 = pbVar11 + 1;
    pbVar8 = pbVar12 + 1;
    *pbVar11 = *pbVar12;
  }
  bVar2 = bVar1;
  pbVar12 = pbVar8;
  if (bVar2 == 0) {
    pbVar12 = pbVar8 + 1;
    bVar9 = *pbVar8;
    bVar2 = bVar9 * '\x02' + 1;
    pbVar11 = param_4;
    if (!CARRY1(bVar9,bVar9) && (byte)(bVar9 * '\x02') != -1) goto LAB_0040112e;
  }
  uVar6 = 2;
  iVar3 = 0;
  bVar15 = CARRY1(bVar2,bVar2);
  bVar2 = bVar2 * '\x02';
  pbVar8 = pbVar12;
  bVar13 = bVar15;
  if (bVar2 == 0) {
    pbVar8 = pbVar12 + 1;
    bVar2 = *pbVar12;
    bVar13 = CARRY1(bVar2,bVar2) || CARRY1(bVar2 * '\x02',bVar15);
    bVar2 = bVar2 * '\x02' + bVar15;
  }
  if (bVar13) {
    bVar15 = CARRY1(bVar2,bVar2);
    bVar2 = bVar2 * '\x02';
    pbVar12 = pbVar8;
    bVar13 = bVar15;
    if (bVar2 == 0) {
      pbVar12 = pbVar8 + 1;
      bVar2 = *pbVar8;
      bVar13 = CARRY1(bVar2,bVar2) || CARRY1(bVar2 * '\x02',bVar15);
      bVar2 = bVar2 * '\x02' + bVar15;
    }
    if (!bVar13) {
LAB_00401119:
      pbVar8 = pbVar12 + 1;
      pbVar12 = param_4 + (-1 - CONCAT31((int3)((uint)iVar3 >> 8),*pbVar12));
      for (; uVar6 != 0; uVar6 = uVar6 - 1) {
        *param_4 = *pbVar12;
        pbVar12 = pbVar12 + 1;
        param_4 = param_4 + 1;
      }
      goto LAB_0040112f;
    }
    uVar6 = 3;
    bVar15 = CARRY1(bVar2,bVar2);
    bVar2 = bVar2 * '\x02';
    pbVar10 = pbVar12;
    bVar13 = bVar15;
    if (bVar2 == 0) {
      pbVar10 = pbVar12 + 1;
      bVar2 = *pbVar12;
      bVar13 = CARRY1(bVar2,bVar2) || CARRY1(bVar2 * '\x02',bVar15);
      bVar2 = bVar2 * '\x02' + bVar15;
    }
    pbVar11 = pbVar10;
    if (bVar13) {
      pbVar11 = pbVar10 + 1;
      if (*pbVar10 != 0) {
        uVar6 = (uint)(ushort)(*pbVar10 + 8);
        goto LAB_004010fb;
      }
      bVar15 = CARRY1(bVar2,bVar2);
      bVar2 = bVar2 * '\x02';
      pbVar8 = pbVar11;
      bVar13 = bVar15;
      if (bVar2 == 0) {
        pbVar8 = pbVar10 + 2;
        bVar2 = *pbVar11;
        bVar13 = CARRY1(bVar2,bVar2) || CARRY1(bVar2 * '\x02',bVar15);
        bVar2 = bVar2 * '\x02' + bVar15;
      }
      iVar3 = DAT_004bc050;
      if (!bVar13) goto LAB_004011ad;
      goto LAB_0040112f;
    }
  }
  else {
    bVar15 = CARRY1(bVar2,bVar2);
    bVar2 = bVar2 * '\x02';
    pbVar12 = pbVar8;
    bVar13 = bVar15;
    if (bVar2 == 0) {
      pbVar12 = pbVar8 + 1;
      bVar2 = *pbVar8;
      bVar13 = CARRY1(bVar2,bVar2) || CARRY1(bVar2 * '\x02',bVar15);
      bVar2 = bVar2 * '\x02' + bVar15;
    }
    uVar6 = (uint)(byte)(bVar13 + 4U);
    bVar14 = CARRY1(bVar2,bVar2);
    bVar2 = bVar2 * '\x02';
    pbVar11 = pbVar12;
    bVar15 = bVar14;
    if (bVar2 == 0) {
      pbVar11 = pbVar12 + 1;
      bVar2 = *pbVar12;
      bVar15 = CARRY1(bVar2,bVar2) || CARRY1(bVar2 * '\x02',bVar14);
      bVar2 = bVar2 * '\x02' + bVar14;
    }
    if (!bVar15) goto LAB_004010fb;
    bVar14 = CARRY1(bVar2,bVar2);
    bVar2 = bVar2 * '\x02';
    bVar15 = bVar14;
    if (bVar2 == 0) {
      bVar2 = *pbVar11;
      bVar15 = CARRY1(bVar2,bVar2) || CARRY1(bVar2 * '\x02',bVar14);
      bVar2 = bVar2 * '\x02' + bVar14;
      pbVar11 = pbVar11 + 1;
    }
    sVar5 = (byte)(bVar13 + 4U) - 1;
    bVar9 = (byte)((ushort)sVar5 >> 8);
    cVar4 = (char)sVar5 * '\x02' + bVar15;
    uVar6 = (uint)CONCAT11(bVar9,cVar4);
    if (cVar4 == '\t') {
      iVar7 = CONCAT31((uint3)bVar9,4);
      do {
        bVar15 = CARRY1(bVar2,bVar2);
        bVar2 = bVar2 * '\x02';
        pbVar8 = pbVar11;
        bVar13 = bVar15;
        if (bVar2 == 0) {
          pbVar8 = pbVar11 + 1;
          bVar2 = *pbVar11;
          bVar13 = CARRY1(bVar2,bVar2) || CARRY1(bVar2 * '\x02',bVar15);
          bVar2 = bVar2 * '\x02' + bVar15;
        }
        bVar9 = (char)((uint)iVar3 >> 8) * '\x02' + bVar13;
        iVar3 = (uint)bVar9 << 8;
        iVar7 = iVar7 + -1;
        pbVar11 = pbVar8;
      } while (iVar7 != 0);
      for (uVar6 = (uint)(byte)((bVar9 + 3) * '\x02'); uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined2 *)param_4 = *(undefined2 *)pbVar8;
        pbVar8 = pbVar8 + 2;
        param_4 = param_4 + 2;
      }
      goto LAB_0040112f;
    }
  }
LAB_004010fb:
  bVar15 = CARRY1(bVar2,bVar2);
  bVar2 = bVar2 * '\x02';
  pbVar12 = pbVar11;
  bVar13 = bVar15;
  if (bVar2 == 0) {
    pbVar12 = pbVar11 + 1;
    bVar2 = *pbVar11;
    bVar13 = CARRY1(bVar2,bVar2) || CARRY1(bVar2 * '\x02',bVar15);
    bVar2 = bVar2 * '\x02' + bVar15;
  }
  if (bVar13) {
    bVar15 = CARRY1(bVar2,bVar2);
    bVar2 = bVar2 * '\x02';
    pbVar8 = pbVar12;
    bVar13 = bVar15;
    if (bVar2 == 0) {
      pbVar8 = pbVar12 + 1;
      bVar2 = *pbVar12;
      bVar13 = CARRY1(bVar2,bVar2) || CARRY1(bVar2 * '\x02',bVar15);
      bVar2 = bVar2 * '\x02' + bVar15;
    }
    bVar14 = CARRY1(bVar2,bVar2);
    bVar2 = bVar2 * '\x02';
    pbVar12 = pbVar8;
    bVar15 = bVar14;
    if (bVar2 == 0) {
      pbVar12 = pbVar8 + 1;
      bVar2 = *pbVar8;
      bVar15 = CARRY1(bVar2,bVar2) || CARRY1(bVar2 * '\x02',bVar14);
      bVar2 = bVar2 * '\x02' + bVar14;
    }
    if (bVar15) {
      bVar14 = CARRY1(bVar2,bVar2);
      bVar2 = bVar2 * '\x02';
      pbVar8 = pbVar12;
      bVar15 = bVar14;
      if (bVar2 == 0) {
        pbVar8 = pbVar12 + 1;
        bVar2 = *pbVar12;
        bVar15 = CARRY1(bVar2,bVar2) || CARRY1(bVar2 * '\x02',bVar14);
        bVar2 = bVar2 * '\x02' + bVar14;
      }
      iVar3 = (uint)(uint3)((byte)(bVar13 * '\x02' + bVar15) | 4) << 8;
      bVar15 = CARRY1(bVar2,bVar2);
      bVar2 = bVar2 * '\x02';
      pbVar12 = pbVar8;
      bVar13 = bVar15;
      if (bVar2 == 0) {
        pbVar12 = pbVar8 + 1;
        bVar2 = *pbVar8;
        bVar13 = CARRY1(bVar2,bVar2) || CARRY1(bVar2 * '\x02',bVar15);
        bVar2 = bVar2 * '\x02' + bVar15;
      }
      if (!bVar13) goto LAB_00401113;
    }
    else {
      iVar3 = (uint)bVar13 << 8;
      if (bVar13 == false) {
        iVar3 = 0x100;
LAB_00401113:
        bVar15 = CARRY1(bVar2,bVar2);
        bVar2 = bVar2 * '\x02';
        bVar13 = bVar15;
        if (bVar2 == 0) {
          bVar2 = *pbVar12;
          bVar13 = CARRY1(bVar2,bVar2) || CARRY1(bVar2 * '\x02',bVar15);
          bVar2 = bVar2 * '\x02' + bVar15;
          pbVar12 = pbVar12 + 1;
        }
        iVar3 = (uint)(byte)((char)((uint)iVar3 >> 8) * '\x02' + bVar13) << 8;
      }
    }
  }
  goto LAB_00401119;
}

