/* entry @ 00499530 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(void)

{
  DWORD DVar1;
  int iVar2;
  HMODULE pHVar3;
  UINT UVar4;
  _STARTUPINFOA local_60;
  undefined1 *local_1c;
  _EXCEPTION_POINTERS *local_18;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_004bb028;
  puStack_10 = &LAB_00499320;
  pvStack_14 = ExceptionList;
  local_1c = &stack0xffffff84;
  ExceptionList = &pvStack_14;
  DVar1 = GetVersion();
  _DAT_004e8c7c = DVar1 >> 8 & 0xff;
  DAT_004e8c78 = DVar1 & 0xff;
  _DAT_004e8c74 = DAT_004e8c78 * 0x100 + _DAT_004e8c7c;
  DAT_004e8c70 = DVar1 >> 0x10;
  iVar2 = FUN_0049a4b0(0);
  if (iVar2 == 0) {
    FUN_004996c0(0x1c);
  }
  local_8 = 0;
  FUN_004a22f0();
  DAT_0050a2a4 = GetCommandLineA();
  DAT_004e8cc0 = FUN_004a4540();
  FUN_004a4030();
  FUN_004a3ee0();
  FUN_00496eb0();
  local_60.dwFlags = 0;
  GetStartupInfoA(&local_60);
  FUN_004a3e20();
  pHVar3 = GetModuleHandleA((LPCSTR)0x0);
  UVar4 = FUN_00445870(pHVar3);
  FUN_00496ef0(UVar4);
  __XcptFilter(local_18->ExceptionRecord->ExceptionCode,local_18);
  return;
}

