/* FUN_004952a0 @ 004952a0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004952a0(void *param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  BOOL BVar3;
  int *_Dst;
  
  if ((((DAT_004c6e88 & 4) != 0) && (iVar2 = FUN_00495960(), iVar2 == 0)) &&
     (iVar2 = FUN_004999a0(2,0x4ba828,0x3e1,0,(byte *)"_CrtCheckMemory()"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  if (param_1 != (void *)0x0) {
    iVar2 = (*(code *)PTR_FUN_004c6fd0)(3,param_1,0,param_2,0,0,0);
    if (iVar2 == 0) {
      iVar2 = FUN_004999a0(0,0,0,0,&DAT_004b8034);
      if (iVar2 == 1) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
    }
    else {
      BVar3 = FUN_00495da0((int)param_1);
      if ((BVar3 == 0) &&
         (iVar2 = FUN_004999a0(2,0x4ba828,0x3f3,0,(byte *)"_CrtIsValidHeapPointer(pUserData)"),
         iVar2 == 1)) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _Dst = (int *)((int)param_1 + -0x20);
      if ((((*(uint *)((int)param_1 + -0xc) & 0xffff) != 4) && (*(int *)((int)param_1 + -0xc) != 1))
         && (((*(uint *)((int)param_1 + -0xc) & 0xffff) != 2 &&
             ((*(int *)((int)param_1 + -0xc) != 3 &&
              (iVar2 = FUN_004999a0(2,0x4ba828,0x3f9,0,
                                    (byte *)"_BLOCK_TYPE_IS_VALID(pHead->nBlockUse)"), iVar2 == 1)))
             ))) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      if ((DAT_004c6e88 & 4) == 0) {
        iVar2 = FUN_004958d0((char *)((int)param_1 + -4),DAT_004c6e94,4);
        if ((iVar2 == 0) &&
           (iVar2 = FUN_004999a0(1,0,0,0,(byte *)"DAMAGE: before %hs block (#%d) at 0x%08X.\n"),
           iVar2 == 1)) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        iVar2 = FUN_004958d0((char *)((int)param_1 + *(int *)((int)param_1 + -0x10)),DAT_004c6e94,4)
        ;
        if ((iVar2 == 0) &&
           (iVar2 = FUN_004999a0(1,0,0,0,(byte *)"DAMAGE: after %hs block (#%d) at 0x%08X.\n"),
           iVar2 == 1)) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
      }
      if (*(int *)((int)param_1 + -0xc) == 3) {
        if (((*(int *)((int)param_1 + -0x14) != -0x1234544) || (*(int *)((int)param_1 + -8) != 0))
           && (iVar2 = FUN_004999a0(2,0x4ba828,0x40e,0,
                                    (byte *)
                                    "pHead->nLine == IGNORE_LINE && pHead->lRequest == IGNORE_REQ"),
              iVar2 == 1)) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        _memset(_Dst,(uint)DAT_004c6e95,*(int *)((int)param_1 + -0x10) + 0x24);
        FUN_0049a3f0(_Dst);
      }
      else {
        if ((*(int *)((int)param_1 + -0xc) == 2) && (param_2 == 1)) {
          param_2 = 2;
        }
        if ((*(int *)((int)param_1 + -0xc) != param_2) &&
           (iVar2 = FUN_004999a0(2,0x4ba828,0x41b,0,(byte *)"pHead->nBlockUse == nBlockUse"),
           iVar2 == 1)) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        DAT_004e8c54 = DAT_004e8c54 - *(int *)((int)param_1 + -0x10);
        if ((DAT_004c6e88 & 2) == 0) {
          if (*_Dst == 0) {
            if ((DAT_004e8c48 != _Dst) &&
               (iVar2 = FUN_004999a0(2,0x4ba828,0x42a,0,(byte *)"_pLastBlock == pHead"), iVar2 == 1)
               ) {
              pcVar1 = (code *)swi(3);
              (*pcVar1)();
              return;
            }
            DAT_004e8c48 = *(int **)((int)param_1 + -0x1c);
          }
          else {
            *(undefined4 *)(*_Dst + 4) = *(undefined4 *)((int)param_1 + -0x1c);
          }
          if (*(int *)((int)param_1 + -0x1c) == 0) {
            if ((DAT_004e8c50 != _Dst) &&
               (iVar2 = FUN_004999a0(2,0x4ba828,0x434,0,(byte *)"_pFirstBlock == pHead"), iVar2 == 1
               )) {
              pcVar1 = (code *)swi(3);
              (*pcVar1)();
              return;
            }
            DAT_004e8c50 = (int *)*_Dst;
          }
          else {
            **(int **)((int)param_1 + -0x1c) = *_Dst;
          }
          _memset(_Dst,(uint)DAT_004c6e95,*(int *)((int)param_1 + -0x10) + 0x24);
          FUN_0049a3f0(_Dst);
        }
        else {
          *(undefined4 *)((int)param_1 + -0xc) = 0;
          _memset(param_1,(uint)DAT_004c6e95,*(size_t *)((int)param_1 + -0x10));
        }
      }
    }
  }
  return;
}

