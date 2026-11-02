/* FUN_0049a120 @ 0049a120 */
/* decompiled from Lucky.exe (Game.run) */


int * __cdecl FUN_0049a120(uint param_1)

{
  int *piVar1;
  
  if ((DAT_004c6fd8 < param_1) || (piVar1 = FUN_0049acc0(param_1), piVar1 == (int *)0x0)) {
    if (param_1 == 0) {
      param_1 = 1;
    }
    piVar1 = HeapAlloc(DAT_0050a29c,0,param_1 + 0xf & 0xfffffff0);
  }
  return piVar1;
}

