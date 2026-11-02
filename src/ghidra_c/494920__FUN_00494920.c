/* FUN_00494920 @ 00494920 */
/* decompiled from Lucky.exe (Game.run) */


int * __cdecl FUN_00494920(uint param_1,uint param_2,int param_3,int param_4)

{
  code *pcVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  bVar2 = false;
  if ((((DAT_004c6e88 & 4) != 0) && (iVar4 = FUN_00495960(), iVar4 == 0)) &&
     (iVar4 = FUN_004999a0(2,0x4ba828,0x141,0,(byte *)"_CrtCheckMemory()"), iVar4 == 1)) {
    pcVar1 = (code *)swi(3);
    piVar5 = (int *)(*pcVar1)();
    return piVar5;
  }
  iVar4 = DAT_004c6e8c;
  if (DAT_004c6e8c == DAT_004c6e90) {
    pcVar1 = (code *)swi(3);
    piVar5 = (int *)(*pcVar1)();
    return piVar5;
  }
  iVar6 = (*(code *)PTR_FUN_004c6fd0)(1,0,param_1,param_2,DAT_004c6e8c,param_3,param_4);
  if (iVar6 == 0) {
    if (param_3 == 0) {
      iVar4 = FUN_004999a0(0,0,0,0,&DAT_004b8034);
      if (iVar4 == 1) {
        pcVar1 = (code *)swi(3);
        piVar5 = (int *)(*pcVar1)();
        return piVar5;
      }
    }
    else {
      iVar4 = FUN_004999a0(0,0,0,0,(byte *)"Client hook allocation failure at file %hs line %d.\n");
      if (iVar4 == 1) {
        pcVar1 = (code *)swi(3);
        piVar5 = (int *)(*pcVar1)();
        return piVar5;
      }
    }
    piVar5 = (int *)0x0;
  }
  else {
    if (((param_2 & 0xffff) != 2) && ((DAT_004c6e88 & 1) == 0)) {
      bVar2 = true;
    }
    if ((param_1 < 0xffffffe1) && (param_1 + 0x24 < 0xffffffe1)) {
      if (((((param_2 & 0xffff) != 4) && (param_2 != 1)) && ((param_2 & 0xffff) != 2)) &&
         ((param_2 != 3 && (iVar6 = FUN_004999a0(1,0,0,0,&DAT_004b8034), iVar6 == 1)))) {
        pcVar1 = (code *)swi(3);
        piVar5 = (int *)(*pcVar1)();
        return piVar5;
      }
      piVar5 = FUN_0049a120(param_1 + 0x24);
      if (piVar5 == (int *)0x0) {
        piVar5 = (int *)0x0;
      }
      else {
        DAT_004c6e8c = DAT_004c6e8c + 1;
        if (bVar2) {
          *piVar5 = 0;
          piVar5[1] = 0;
          piVar5[2] = 0;
          piVar5[3] = -0x1234544;
          piVar5[4] = param_1;
          piVar5[5] = 3;
          piVar5[6] = 0;
        }
        else {
          DAT_004e8c4c = DAT_004e8c4c + param_1;
          DAT_004e8c54 = DAT_004e8c54 + param_1;
          if (DAT_004e8c58 < DAT_004e8c54) {
            DAT_004e8c58 = DAT_004e8c54;
          }
          piVar3 = piVar5;
          if (DAT_004e8c50 != (int *)0x0) {
            DAT_004e8c50[1] = (int)piVar5;
            piVar3 = DAT_004e8c48;
          }
          DAT_004e8c48 = piVar3;
          *piVar5 = (int)DAT_004e8c50;
          piVar5[1] = 0;
          piVar5[2] = param_3;
          piVar5[3] = param_4;
          piVar5[4] = param_1;
          piVar5[5] = param_2;
          piVar5[6] = iVar4;
          DAT_004e8c50 = piVar5;
        }
        _memset(piVar5 + 7,(uint)DAT_004c6e94,4);
        _memset((void *)((int)piVar5 + param_1 + 0x20),(uint)DAT_004c6e94,4);
        _memset(piVar5 + 8,(uint)DAT_004c6e96,param_1);
        piVar5 = piVar5 + 8;
      }
    }
    else {
      iVar4 = FUN_004999a0(1,0,0,0,(byte *)"Invalid allocation size: %u bytes.\n");
      if (iVar4 == 1) {
        pcVar1 = (code *)swi(3);
        piVar5 = (int *)(*pcVar1)();
        return piVar5;
      }
      piVar5 = (int *)0x0;
    }
  }
  return piVar5;
}

