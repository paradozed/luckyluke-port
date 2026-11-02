/* FUN_00495da0 @ 00495da0 */
/* decompiled from Lucky.exe (Game.run) */


BOOL __cdecl FUN_00495da0(int param_1)

{
  BOOL BVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    BVar1 = 0;
  }
  else {
    iVar2 = FID_conflict_AtlIsValidAddress((void *)(param_1 + -0x20),0x20,1);
    if (iVar2 == 0) {
      BVar1 = 0;
    }
    else {
      uVar3 = FUN_0049a630(param_1 + -0x20);
      if (uVar3 == 0) {
        if ((DAT_004e8c70 & 0x8000) == 0) {
          BVar1 = HeapValidate(DAT_0050a29c,0,(LPCVOID)(param_1 + -0x20));
        }
        else {
          BVar1 = 1;
        }
      }
      else {
        BVar1 = FUN_0049a690(uVar3,param_1 + -0x20);
      }
    }
  }
  return BVar1;
}

