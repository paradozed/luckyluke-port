/* FUN_004ac7f0 @ 004ac7f0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_004ac7f0(uint param_1,uint param_2)

{
  double dVar1;
  int iVar2;
  float10 fVar3;
  int local_c;
  uint local_8;
  
  local_8 = FUN_004ac3e0();
  if ((param_2._2_2_ & 0x7ff0) != 0x7ff0) {
    if ((double)CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1)) == _DAT_004b8e28) {
      fVar3 = FUN_004ab810(4,0x25,param_1,param_2,SUB84(-_DAT_004c7be0,0),
                           (int)((ulonglong)-_DAT_004c7be0 >> 0x20),local_8);
      return fVar3;
    }
    FUN_004ac610(param_1,param_2,&local_c);
    FUN_004ac3e0();
    return (float10)(local_c + -1);
  }
  iVar2 = FUN_004ac590(param_1,param_2);
  if (0 < iVar2) {
    if (iVar2 < 3) {
      FUN_004ac3e0();
      return (float10)(double)CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1));
    }
    if (iVar2 == 3) {
      fVar3 = FUN_004ab740(0x25,param_1,param_2);
      return fVar3;
    }
  }
  dVar1 = (double)CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1)) + _DAT_004bb2d8;
  fVar3 = FUN_004ab810(8,0x25,param_1,param_2,SUB84(dVar1,0),(int)((ulonglong)dVar1 >> 0x20),local_8
                      );
  return fVar3;
}

