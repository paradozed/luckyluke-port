/* FUN_004a59a0 @ 004a59a0 */
/* decompiled from Lucky.exe (Game.run) */


int FUN_004a59a0(int *param_1)

{
  int iVar1;
  
  if (((*(int *)*param_1 == -0x1f928c9d) && (*(int *)(*param_1 + 0x10) == 3)) &&
     (*(int *)(*param_1 + 0x14) == 0x19930520)) {
    FUN_0049cfb0();
  }
  if ((DAT_004e8e50 != (_func_int *)0x0) && (iVar1 = _ValidateExecute(DAT_004e8e50), iVar1 != 0)) {
    iVar1 = (*DAT_004e8e50)(param_1);
    return iVar1;
  }
  return 0;
}

