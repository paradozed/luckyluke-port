/* FUN_0049a4b0 @ 0049a4b0 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __cdecl FUN_0049a4b0(int param_1)

{
  bool bVar1;
  undefined4 uVar2;
  undefined3 extraout_var;
  
  DAT_0050a29c = HeapCreate((uint)(param_1 == 0),0x1000,0);
  if (DAT_0050a29c == (HANDLE)0x0) {
    uVar2 = 0;
  }
  else {
    bVar1 = FUN_0049a5d0();
    if (CONCAT31(extraout_var,bVar1) == 0) {
      HeapDestroy(DAT_0050a29c);
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}

