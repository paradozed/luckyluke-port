/* CatchIt @ 0049c9a0 */
/* decompiled from Lucky.exe (Game.run) */


/* Library Function - Single Match
    void __cdecl CatchIt(struct EHExceptionRecord *,struct EHRegistrationNode *,struct _CONTEXT
   *,void *,struct _s_FuncInfo const *,struct _s_HandlerType const *,struct _s_CatchableType const
   *,struct _s_TryBlockMapEntry const *,int,struct EHRegistrationNode *,unsigned char)
   
   Library: Visual Studio */

void __cdecl
CatchIt(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
       _s_FuncInfo *param_5,_s_HandlerType *param_6,_s_CatchableType *param_7,
       _s_TryBlockMapEntry *param_8,int param_9,EHRegistrationNode *param_10,uchar param_11)

{
  undefined *UNRECOVERED_JUMPTABLE;
  
  if (param_7 != (_s_CatchableType *)0x0) {
    FUN_0049cc00((int)param_1,(int)param_2,&param_6->adjectives,(uint *)param_7);
  }
  if (param_10 == (EHRegistrationNode *)0x0) {
    FUN_004967f0(param_2,(PEXCEPTION_RECORD)param_1);
  }
  else {
    FUN_004967f0(param_10,(PEXCEPTION_RECORD)param_1);
  }
  FUN_0049c870((int)param_2,param_4,(int)param_5,param_8->tryLow);
  *(__ehstate_t *)(param_2 + 8) = param_8->tryHigh + 1;
  UNRECOVERED_JUMPTABLE =
       (undefined *)
       FUN_0049ca60(param_1,param_2,param_3,param_5,param_6->addressOfHandler,param_9,0x100);
  if (UNRECOVERED_JUMPTABLE != (undefined *)0x0) {
    FUN_00496780(UNRECOVERED_JUMPTABLE);
  }
  return;
}

