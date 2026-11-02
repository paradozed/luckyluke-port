/* FUN_0049a3f0 @ 0049a3f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0049a3f0(LPVOID param_1)

{
  uint *puVar1;
  
  if (param_1 != (LPVOID)0x0) {
    puVar1 = (uint *)FUN_0049a630((int)param_1);
    if (puVar1 == (uint *)0x0) {
      HeapFree(DAT_0050a29c,0,param_1);
    }
    else {
      FUN_0049a6f0(puVar1,(int)param_1);
    }
  }
  return;
}

