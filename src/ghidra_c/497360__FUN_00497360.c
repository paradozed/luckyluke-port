/* FUN_00497360 @ 00497360 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00497360(void)

{
  longlong lVar1;
  undefined8 uVar2;
  _FILETIME local_c;
  
  GetSystemTimeAsFileTime(&local_c);
  lVar1 = __allshl(0x20,0);
  lVar1 = (lVar1 + (ulonglong)local_c.dwLowDateTime) - CONCAT44(_DAT_004e8cbc,_DAT_004e8cb8);
  uVar2 = __aulldiv((uint)lVar1,(uint)((ulonglong)lVar1 >> 0x20),10000,0);
  return uVar2;
}

