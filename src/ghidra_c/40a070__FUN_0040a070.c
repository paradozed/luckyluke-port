/* FUN_0040a070 @ 0040a070 */
/* decompiled from Lucky.exe (Game.run) */


uint __cdecl FUN_0040a070(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_78 [29];
  
  puVar6 = local_78;
  for (iVar5 = 0x1d; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0xcccccccc;
    puVar6 = puVar6 + 1;
  }
  iVar5 = *(int *)(param_1 + 0x90);
  iVar1 = *(int *)(param_1 + 0x98);
  iVar2 = *(int *)(param_2 + 0x90);
  iVar3 = *(int *)(param_2 + 0x98);
  uVar4 = iVar2 - iVar5;
  if ((uVar4 == 0) && (iVar3 == iVar1)) {
    return 0;
  }
  if (DAT_004f5558 < 0x601) {
    if (DAT_004f5558 == 0x600) {
      if (((int)uVar4 < 0) &&
         (uVar4 = (-(iVar3 - (iVar1 + -0x5dc)) - (iVar2 - (iVar5 + -0x5dc))) *
                  (-(iVar3 - (iVar1 + 0x5dc)) - (iVar2 - (iVar5 + 0x5dc))), (int)uVar4 < 0)) {
        return CONCAT22((short)(uVar4 >> 0x10),1);
      }
    }
    else if (DAT_004f5558 == 0) {
      if (((0 < (int)uVar4) && (uVar4 = iVar1 - 1000, (int)uVar4 < iVar3)) && (iVar3 < iVar1 + 1000)
         ) {
        return CONCAT22((short)(uVar4 >> 0x10),1);
      }
    }
    else if (DAT_004f5558 == 0x200) {
      if ((0 < (int)uVar4) &&
         (uVar4 = iVar3 - (iVar1 + -0x5dc),
         (int)(((iVar2 - (iVar5 + -0x5dc)) - (iVar3 - (iVar1 + 0x5dc))) *
              ((iVar2 - (iVar5 + 0x5dc)) - uVar4)) < 0)) {
        return CONCAT22((short)(uVar4 >> 0x10),1);
      }
    }
    else if (((DAT_004f5558 == 0x400) && (0 < iVar3 - iVar1)) &&
            ((iVar5 + -1000 < iVar2 && (uVar4 = iVar5 + 1000, iVar2 < (int)uVar4)))) {
      return CONCAT22((short)(uVar4 >> 0x10),1);
    }
  }
  else if (DAT_004f5558 == 0xa00) {
    if (((int)uVar4 < 0) &&
       (uVar4 = ((iVar3 - (iVar1 + 0x5dc)) - (iVar2 - (iVar5 + -0x5dc))) *
                ((iVar3 - (iVar1 + -0x5dc)) - (iVar2 - (iVar5 + 0x5dc))), (int)uVar4 < 0)) {
      return CONCAT22((short)(uVar4 >> 0x10),1);
    }
  }
  else if (DAT_004f5558 == 0xc00) {
    if (((iVar3 - iVar1 < 0) && (iVar5 + -1000 < iVar2)) && (iVar2 < iVar5 + 1000)) {
      return CONCAT22((short)(uVar4 >> 0x10),1);
    }
  }
  else if (((DAT_004f5558 == 0xe00) && (0 < (int)uVar4)) &&
          (uVar4 = iVar1 + 0x5dc,
          (int)((-(iVar3 - (iVar1 + -0x5dc)) - (iVar2 - (iVar5 + -0x5dc))) *
               (-(iVar3 - uVar4) - (iVar2 - (iVar5 + 0x5dc)))) < 0)) {
    return CONCAT22((short)(uVar4 >> 0x10),1);
  }
  return uVar4 & 0xffff0000;
}

