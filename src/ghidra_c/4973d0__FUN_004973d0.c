/* FUN_004973d0 @ 004973d0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004973d0(void)

{
  longlong lVar1;
  _FILETIME local_c;
  
  GetSystemTimeAsFileTime(&local_c);
  lVar1 = __allshl(0x20,0);
  _DAT_004e8cb8 = lVar1 + (ulonglong)local_c.dwLowDateTime;
  return;
}

