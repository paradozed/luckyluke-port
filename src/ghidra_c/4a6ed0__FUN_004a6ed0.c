/* FUN_004a6ed0 @ 004a6ed0 */
/* decompiled from Lucky.exe (Game.run) */


int __cdecl FUN_004a6ed0(PCNZWCH param_1,LPCWSTR param_2,int param_3)

{
  int iVar1;
  
  if (param_3 == 0) {
    iVar1 = 0;
  }
  else if (DAT_004e8e94 == 0) {
    iVar1 = FUN_004ab170((uint)param_2,(uint)param_1,(ushort *)param_1,(ushort *)param_2,param_3);
  }
  else {
    iVar1 = FUN_004aae40(DAT_004e8e94,0x1001,param_1,param_3,param_2,param_3,DAT_004e8eac);
    if (iVar1 == 0) {
      DAT_004e8c64 = 0x16;
      iVar1 = 0x7fffffff;
    }
    else {
      iVar1 = iVar1 + -2;
    }
  }
  return iVar1;
}

