/* FUN_0049c3f0 @ 0049c3f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_0049c3f0(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
            _s_FuncInfo *param_5,char param_6,int param_7,EHRegistrationNode *param_8)

{
  EHExceptionRecord *pEVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  int local_28;
  int local_24;
  _s_HandlerType *local_20;
  undefined4 *local_1c;
  uint local_18;
  _s_TryBlockMapEntry *local_14;
  uint local_10;
  uchar local_c;
  int local_8;
  
  local_c = '\0';
  local_8 = *(int *)(param_2 + 8);
  if ((local_8 < -1) || (param_5->maxState <= local_8)) {
    FUN_0049d060();
  }
  pEVar1 = DAT_004e8cd8;
  if ((((*(int *)param_1 == -0x1f928c9d) && (*(int *)(param_1 + 0x10) == 3)) &&
      (*(int *)(param_1 + 0x14) == 0x19930520)) && (*(int *)(param_1 + 0x1c) == 0)) {
    if (DAT_004e8cd8 == (EHExceptionRecord *)0x0) {
      return;
    }
    param_1 = DAT_004e8cd8;
    param_3 = DAT_004e8cdc;
    local_c = '\x01';
    bVar2 = FUN_004a5a40(DAT_004e8cd8,1);
    if (CONCAT31(extraout_var,bVar2) == 0) {
      FUN_0049d060();
    }
    if (((*(int *)pEVar1 == -0x1f928c9d) && (*(int *)(pEVar1 + 0x10) == 3)) &&
       ((*(int *)(pEVar1 + 0x14) == 0x19930520 && (*(int *)(pEVar1 + 0x1c) == 0)))) {
      FUN_0049d060();
    }
  }
  if (((*(int *)param_1 == -0x1f928c9d) && (*(int *)(param_1 + 0x10) == 3)) &&
     (*(int *)(param_1 + 0x14) == 0x19930520)) {
    local_14 = (_s_TryBlockMapEntry *)FUN_00496ad0((int)param_5,param_7,local_8,&local_18,&local_10)
    ;
    for (; local_18 < local_10; local_18 = local_18 + 1) {
      if ((local_14->tryLow <= local_8) && (local_8 <= local_14->tryHigh)) {
        local_20 = local_14->pHandlerArray;
        for (local_28 = local_14->nCatches; 0 < local_28; local_28 = local_28 + -1) {
          local_1c = *(undefined4 **)(*(int *)(param_1 + 0x1c) + 0xc);
          for (local_24 = **(int **)(*(int *)(param_1 + 0x1c) + 0xc); local_1c = local_1c + 1,
              0 < local_24; local_24 = local_24 + -1) {
            iVar3 = FUN_0049c7b0(&local_20->adjectives,(uint *)*local_1c,*(uint **)(param_1 + 0x1c))
            ;
            if (iVar3 != 0) {
              CatchIt(param_1,param_2,param_3,param_4,param_5,local_20,(_s_CatchableType *)*local_1c
                      ,local_14,param_7,param_8,local_c);
              goto LAB_0049c52b;
            }
          }
          local_20 = local_20 + 1;
        }
      }
LAB_0049c52b:
      local_14 = local_14 + 1;
    }
    if (param_6 != '\0') {
      ___DestructExceptionObject((int)param_1);
    }
  }
  else if (param_6 == '\0') {
    FUN_0049c690(param_1,param_2,param_3,param_4,param_5,local_8,param_7,param_8);
  }
  else {
    FUN_0049cfb0();
  }
  return;
}

