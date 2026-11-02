/* FUN_00496f70 @ 00496f70 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00496f70(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  uint uVar1;
  UINT uExitCode;
  int *local_8;
  
  if (DAT_004e8cac == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_004e8ca8 = 1;
  DAT_004e8ca4 = (undefined1)param_3;
  if (param_2 == 0) {
    if (DAT_0050a2b4 != (int *)0x0) {
      local_8 = DAT_0050a2b0;
      while (local_8 = local_8 + -1, DAT_0050a2b4 <= local_8) {
        if (*local_8 != 0) {
          (*(code *)*local_8)();
        }
      }
    }
    __initterm((int *)&DAT_004bc02c,(int *)&DAT_004bc034);
  }
  __initterm((int *)&DAT_004bc038,(int *)&DAT_004bc040);
  if ((DAT_004e8cb0 == 0) && (uVar1 = FUN_00495cc0(-1), (uVar1 & 0x20) != 0)) {
    DAT_004e8cb0 = 1;
    FUN_00496580();
  }
  if (param_3 == 0) {
    DAT_004e8cac = 1;
                    /* WARNING: Subroutine does not return */
    ExitProcess(param_1);
  }
  return;
}

