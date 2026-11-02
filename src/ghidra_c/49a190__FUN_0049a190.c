/* FUN_0049a190 @ 0049a190 */
/* decompiled from Lucky.exe (Game.run) */


LPVOID __cdecl FUN_0049a190(LPVOID param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  LPVOID local_8;
  
  if (param_2 < 0xffffffe1) {
    puVar1 = (uint *)FUN_0049a630((int)param_1);
    if (puVar1 == (uint *)0x0) {
      if (param_2 == 0) {
        param_2 = 1;
      }
      local_8 = HeapReAlloc(DAT_0050a29c,0x10,param_1,param_2 + 0xf & 0xfffffff0);
    }
    else {
      local_8 = (LPVOID)0x0;
      if ((param_2 <= DAT_004c6fd8) &&
         (iVar2 = FUN_0049b500(puVar1,(int)param_1,param_2), iVar2 != 0)) {
        local_8 = param_1;
      }
    }
  }
  else {
    local_8 = (LPVOID)0x0;
  }
  return local_8;
}

