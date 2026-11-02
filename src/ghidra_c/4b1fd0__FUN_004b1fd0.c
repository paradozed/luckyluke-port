/* FUN_004b1fd0 @ 004b1fd0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_004b1fd0(HINSTANCE param_1)

{
  _DAT_004e9368 = param_1;
  DAT_004e9364 = CreateWindowExA(0x100,s_LUCKY_004d1c64,s_LUCKY_004d1c64,0xcc0000,0,0,0x96,1,
                                 (HWND)0x0,(HMENU)0x0,param_1,(LPVOID)0x0);
  if (DAT_004e9364 == (HWND)0x0) {
    return 0;
  }
  UpdateWindow(DAT_004e9364);
  SetFocus(DAT_004e9364);
  return 1;
}

