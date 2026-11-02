/* FUN_0049ca60 @ 0049ca60 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0049ca60(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,int param_7)

{
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_004bb270;
  puStack_10 = &LAB_00499320;
  pvStack_14 = ExceptionList;
  DAT_004e8cd8 = param_1;
  DAT_004e8cdc = param_3;
  local_8 = 1;
  ExceptionList = &pvStack_14;
  FUN_004968c0(param_2,param_4,param_5,param_6,param_7);
  local_8 = 0xffffffff;
  FUN_0049cb33();
  FUN_0049cb8d();
  return;
}

