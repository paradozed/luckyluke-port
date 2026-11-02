/* FUN_0049edc0 @ 0049edc0 */
/* decompiled from Lucky.exe (Game.run) */


int __cdecl FUN_0049edc0(PCNZWCH param_1,int param_2)

{
  int iVar1;
  int *local_8;
  
  local_8 = DAT_004e8c94;
  while( true ) {
    if (*local_8 == 0) {
      return -((int)local_8 - (int)DAT_004e8c94 >> 2);
    }
    iVar1 = FUN_004a6ed0(param_1,(LPCWSTR)*local_8,param_2);
    if ((iVar1 == 0) &&
       ((*(short *)(*local_8 + param_2 * 2) == 0x3d || (*(short *)(*local_8 + param_2 * 2) == 0))))
    break;
    local_8 = local_8 + 1;
  }
  return (int)local_8 - (int)DAT_004e8c94 >> 2;
}

