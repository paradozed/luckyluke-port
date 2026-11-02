/* FUN_004ad600 @ 004ad600 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_004ad600(uint param_1,uint param_2,int param_3)

{
  int iVar1;
  float10 fVar2;
  double dVar3;
  short sVar4;
  uint uVar5;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  int local_38;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  undefined4 local_20;
  undefined4 uStack_1c;
  int local_18;
  int local_14;
  uint local_10;
  double local_c;
  
  local_10 = FUN_004ac3e0();
  if ((param_2._2_2_ & 0x7ff0) == 0x7ff0) {
    iVar1 = FUN_004ac590(param_1,param_2);
    if (0 < iVar1) {
      if (iVar1 < 3) {
        FUN_004ac3e0();
        return (float10)(double)CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1));
      }
      if (iVar1 == 3) {
        local_2c = SUB84((double)param_3,0);
        fVar2 = FUN_004ab7a0(0x19,param_1,param_2,local_2c,(int)((ulonglong)(double)param_3 >> 0x20)
                            );
        return fVar2;
      }
    }
    dVar3 = (double)CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1)) + _DAT_004bb2d8;
    uStack_30 = (undefined4)((ulonglong)(double)param_3 >> 0x20);
    local_34 = SUB84((double)param_3,0);
    fVar2 = FUN_004ab8d0(8,0x19,param_1,param_2,local_34,uStack_30,SUB84(dVar3,0),
                         (int)((ulonglong)dVar3 >> 0x20),local_10);
    return fVar2;
  }
  if ((double)CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1)) == _DAT_004b8e28) {
    FUN_004ac3e0();
    return (float10)(double)CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1));
  }
  fVar2 = FUN_004ac610(param_1,param_2,&local_14);
  dVar3 = (double)fVar2;
  if (param_3 < 0) {
    local_38 = -param_3;
  }
  else {
    local_38 = param_3;
  }
  if (local_38 <= 0x7fffffff) {
    local_18 = local_14 + param_3;
  }
  else {
    local_18 = param_3;
  }
  local_20 = SUB84(dVar3,0);
  uStack_1c = (undefined4)((ulonglong)dVar3 >> 0x20);
  if (0xa00 < local_18) {
    uVar5 = local_10;
    dVar3 = __copysign((double)CONCAT44(DAT_004c7be4,DAT_004c7be0),dVar3);
    uStack_3c = (undefined4)((ulonglong)(double)param_3 >> 0x20);
    local_40 = SUB84((double)param_3,0);
    fVar2 = FUN_004ab8d0(0x11,0x19,param_1,param_2,local_40,uStack_3c,SUB84(dVar3,0),
                         (int)((ulonglong)dVar3 >> 0x20),uVar5);
    return fVar2;
  }
  sVar4 = (short)local_18;
  if (0x400 < local_18) {
    fVar2 = FUN_004ac4a0(local_20,uStack_1c,sVar4 + -0x600);
    local_c = (double)fVar2;
    uStack_44 = (undefined4)((ulonglong)(double)param_3 >> 0x20);
    local_48 = SUB84((double)param_3,0);
    fVar2 = FUN_004ab8d0(0x11,0x19,param_1,param_2,local_48,uStack_44,local_c._0_4_,
                         (int)((ulonglong)local_c >> 0x20),local_10);
    return fVar2;
  }
  if (local_18 < -0x9fd) {
    uStack_4c = (undefined4)((ulonglong)(double)param_3 >> 0x20);
    local_50 = SUB84((double)param_3,0);
    fVar2 = FUN_004ab8d0(0x12,0x19,param_1,param_2,local_50,uStack_4c,SUB84(dVar3 * _DAT_004b8e28,0)
                         ,(int)((ulonglong)(dVar3 * _DAT_004b8e28) >> 0x20),local_10);
    return fVar2;
  }
  if (local_18 < -0x3fd) {
    fVar2 = FUN_004ac4a0(local_20,uStack_1c,sVar4 + 0x600);
    local_c = (double)fVar2;
    uStack_54 = (undefined4)((ulonglong)(double)param_3 >> 0x20);
    local_58 = SUB84((double)param_3,0);
    fVar2 = FUN_004ab8d0(0x12,0x19,param_1,param_2,local_58,uStack_54,local_c._0_4_,
                         (int)((ulonglong)local_c >> 0x20),local_10);
    return fVar2;
  }
  fVar2 = FUN_004ac4a0(local_20,uStack_1c,sVar4);
  local_c = (double)fVar2;
  FUN_004ac3e0();
  return (float10)local_c;
}

