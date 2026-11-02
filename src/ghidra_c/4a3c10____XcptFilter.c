/* __XcptFilter @ 004a3c10 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __XcptFilter
   
   Library: Visual Studio 2003 Debug */

int __cdecl __XcptFilter(ulong _ExceptionNum,_EXCEPTION_POINTERS *_ExceptionPtr)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int local_14;
  
  piVar4 = xcptlookup(_ExceptionNum);
  uVar3 = DAT_004e8d1c;
  if ((piVar4 == (int *)0x0) || (piVar4[2] == 0)) {
    iVar5 = UnhandledExceptionFilter(_ExceptionPtr);
  }
  else if (piVar4[2] == 5) {
    piVar4[2] = 0;
    iVar5 = 1;
  }
  else if (piVar4[2] == 1) {
    iVar5 = -1;
    DAT_004e8d1c = (_EXCEPTION_POINTERS *)uVar3;
  }
  else {
    pcVar1 = (code *)piVar4[2];
    DAT_004e8d1c = _ExceptionPtr;
    if (piVar4[1] == 8) {
      for (local_14 = DAT_004c77b0; uVar2 = DAT_004c77bc, local_14 < DAT_004c77b0 + _DAT_004c77b4;
          local_14 = local_14 + 1) {
        *(undefined4 *)(local_14 * 0xc + 0x4c7740) = 0;
      }
      if (*piVar4 == -0x3fffff72) {
        DAT_004c77bc = 0x83;
      }
      else if (*piVar4 == -0x3fffff70) {
        DAT_004c77bc = 0x81;
      }
      else if (*piVar4 == -0x3fffff6f) {
        DAT_004c77bc = 0x84;
      }
      else if (*piVar4 == -0x3fffff6d) {
        DAT_004c77bc = 0x85;
      }
      else if (*piVar4 == -0x3fffff73) {
        DAT_004c77bc = 0x82;
      }
      else if (*piVar4 == -0x3fffff71) {
        DAT_004c77bc = 0x86;
      }
      else if (*piVar4 == -0x3fffff6e) {
        DAT_004c77bc = 0x8a;
      }
      (*pcVar1)(8,DAT_004c77bc);
      DAT_004c77bc = uVar2;
    }
    else {
      piVar4[2] = 0;
      (*pcVar1)(piVar4[1]);
    }
    iVar5 = -1;
    DAT_004e8d1c = (_EXCEPTION_POINTERS *)uVar3;
  }
  return iVar5;
}

