/* FUN_0049f550 @ 0049f550 */
/* decompiled from Lucky.exe (Game.run) */


float10 __fastcall
FUN_0049f550(char *param_1,uint param_2,undefined2 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  float10 in_ST0;
  _exception local_24;
  
  local_24.arg2._0_4_ = param_7;
  local_24.arg2._4_4_ = param_8;
  local_24.retval = (double)in_ST0;
  local_24.arg1._0_4_ = param_5;
  local_24.arg1._4_4_ = param_6;
  local_24.name = param_1;
  FUN_004a7120(param_2,&local_24,&param_3);
  return (float10)local_24.retval;
}

