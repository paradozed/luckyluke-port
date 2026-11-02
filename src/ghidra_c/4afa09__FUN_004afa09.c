/* FUN_004afa09 @ 004afa09 */
/* decompiled from Lucky.exe (Game.run) */


void __fastcall FUN_004afa09(int *param_1)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined2 *puVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  
  iVar7 = DAT_004e8f08;
  uVar2 = (undefined2)param_1[4];
  iVar11 = *param_1;
  iVar5 = param_1[1];
  iVar6 = param_1[2];
  iVar3 = param_1[3];
  iVar4 = iVar11;
  DAT_004e8f14 = uVar2;
  if (iVar5 == iVar3) {
    if (iVar6 < iVar11) {
      iVar4 = iVar6;
      iVar6 = iVar11;
    }
    if ((((iVar4 <= DAT_0050a2c4) && (DAT_0050a2c8 <= iVar6)) && (DAT_0050a2c0 <= iVar5)) &&
       (iVar5 <= DAT_0050a2bc)) {
      if (iVar4 < DAT_0050a2c8) {
        iVar4 = DAT_0050a2c8;
      }
      if (DAT_0050a2c4 < iVar6) {
        iVar6 = DAT_0050a2c4;
      }
      uVar10 = iVar6 - iVar4;
      puVar13 = (undefined4 *)(DAT_004e8f10 + iVar4 * 2 + DAT_004e8f08 * iVar5);
      uVar8 = uVar10 + 1;
      puVar14 = puVar13;
      if (((uint)puVar13 & 1) != 0) {
        puVar14 = (undefined4 *)((int)puVar13 + 2);
        *(undefined2 *)puVar13 = uVar2;
        uVar8 = uVar10;
        if (uVar10 == 0) {
          return;
        }
      }
      for (uVar10 = uVar8 >> 1; uVar10 != 0; uVar10 = uVar10 - 1) {
        *puVar14 = CONCAT22(uVar2,uVar2);
        puVar14 = puVar14 + 1;
      }
      for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(char *)puVar14 = (char)uVar2;
        puVar14 = (undefined4 *)((int)puVar14 + 1);
      }
      return;
    }
  }
  else if (iVar11 != iVar6) {
    iVar7 = iVar11;
    iVar4 = iVar3;
    if (iVar6 <= iVar11) {
      iVar7 = iVar6;
      iVar4 = iVar5;
      iVar5 = iVar3;
      iVar6 = iVar11;
    }
    if (iVar6 < DAT_0050a2c8) {
      return;
    }
    if (DAT_0050a2c4 < iVar7) {
      return;
    }
    DAT_004e8ef4 = iVar6 - iVar7;
    DAT_004e8ef8 = iVar4 - iVar5;
    if (DAT_0050a2c4 < iVar6) {
      iVar4 = (int)(((longlong)(DAT_0050a2c4 - iVar7) * (longlong)DAT_004e8ef8) /
                   (longlong)DAT_004e8ef4) + iVar5;
      DAT_004e8ef4 = DAT_0050a2c4 - iVar7;
      DAT_004e8ef8 = iVar4 - iVar5;
      iVar6 = DAT_0050a2c4;
    }
    if (iVar7 < DAT_0050a2c8) {
      iVar5 = (int)(((longlong)(DAT_0050a2c8 - iVar7) * (longlong)DAT_004e8ef8) /
                   (longlong)DAT_004e8ef4) + iVar5;
      DAT_004e8ef4 = iVar6 - DAT_0050a2c8;
      DAT_004e8ef8 = iVar4 - iVar5;
      iVar7 = DAT_0050a2c8;
    }
    if ((iVar5 < DAT_0050a2c0) && (iVar4 < DAT_0050a2c0)) {
      return;
    }
    if ((DAT_0050a2bc < iVar5) && (DAT_0050a2bc < iVar4)) {
      return;
    }
    if (iVar4 < DAT_0050a2c0) {
      iVar6 = (int)(((longlong)(DAT_0050a2c0 - iVar5) * (longlong)DAT_004e8ef4) /
                   (longlong)DAT_004e8ef8) + iVar7;
      DAT_004e8ef4 = iVar6 - iVar7;
      DAT_004e8ef8 = DAT_0050a2c0 - iVar5;
      iVar4 = DAT_0050a2c0;
    }
    else if (DAT_0050a2bc < iVar4) {
      iVar6 = (int)(((longlong)(DAT_0050a2bc - iVar5) * (longlong)DAT_004e8ef4) /
                   (longlong)DAT_004e8ef8) + iVar7;
      DAT_004e8ef4 = iVar6 - iVar7;
      DAT_004e8ef8 = DAT_0050a2bc - iVar5;
      iVar4 = DAT_0050a2bc;
    }
    if (iVar5 < DAT_0050a2c0) {
      iVar7 = (int)(((longlong)(DAT_0050a2c0 - iVar5) * (longlong)DAT_004e8ef4) /
                   (longlong)DAT_004e8ef8) + iVar7;
      DAT_004e8ef4 = iVar6 - iVar7;
      DAT_004e8ef8 = iVar4 - DAT_0050a2c0;
      iVar5 = DAT_0050a2c0;
    }
    else if (DAT_0050a2bc < iVar5) {
      iVar7 = (int)(((longlong)(DAT_0050a2bc - iVar5) * (longlong)DAT_004e8ef4) /
                   (longlong)DAT_004e8ef8) + iVar7;
      DAT_004e8ef4 = iVar6 - iVar7;
      DAT_004e8ef8 = iVar4 - DAT_0050a2bc;
      iVar5 = DAT_0050a2bc;
    }
    uVar10 = iVar4 - iVar5;
    uVar8 = iVar6 - iVar7;
    puVar12 = (undefined2 *)(DAT_004e8f10 + iVar7 * 2 + DAT_004e8f08 * iVar5);
    iVar11 = DAT_004e8f08;
    if ((int)uVar10 < 1) {
      uVar10 = -uVar10;
      iVar11 = -DAT_004e8f08;
    }
    if ((int)uVar10 <= (int)uVar8) {
      uVar9 = uVar8 >> 1;
      iVar5 = uVar8 + 1;
      while( true ) {
        puVar1 = puVar12 + 1;
        *puVar12 = uVar2;
        iVar5 = iVar5 + -1;
        if (iVar5 == 0) break;
        uVar9 = uVar9 + uVar10;
        puVar12 = puVar1;
        if (uVar8 <= uVar9) {
          uVar9 = uVar9 - uVar8;
          puVar12 = (undefined2 *)((int)puVar1 + iVar11);
        }
      }
      return;
    }
    uVar9 = uVar10 >> 1;
    iVar5 = uVar10 + 1;
    while( true ) {
      *puVar12 = uVar2;
      puVar12 = (undefined2 *)((int)puVar12 + iVar11);
      iVar5 = iVar5 + -1;
      if (iVar5 == 0) break;
      uVar9 = uVar9 + uVar8;
      if (uVar10 <= uVar9) {
        uVar9 = uVar9 - uVar10;
        puVar12 = (undefined2 *)((int)puVar12 + 1);
      }
    }
    return;
  }
  iVar11 = iVar3;
  if (iVar3 <= iVar5) {
    iVar11 = iVar5;
    iVar5 = iVar3;
  }
  if (((DAT_0050a2c8 <= iVar4) && (iVar4 <= DAT_0050a2c4)) &&
     ((iVar5 <= DAT_0050a2bc && (DAT_0050a2c0 <= iVar11)))) {
    if (iVar5 < DAT_0050a2c0) {
      iVar5 = DAT_0050a2c0;
    }
    if (DAT_0050a2bc < iVar11) {
      iVar11 = DAT_0050a2bc;
    }
    iVar11 = (iVar11 - iVar5) + 1;
    puVar12 = (undefined2 *)(DAT_004e8f10 + iVar4 * 2 + DAT_004e8f08 * iVar5);
    do {
      *puVar12 = uVar2;
      puVar12 = (undefined2 *)((int)puVar12 + iVar7);
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
  }
  return;
}

