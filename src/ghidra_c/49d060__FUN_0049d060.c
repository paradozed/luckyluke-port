/* FUN_0049d060 @ 0049d060 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0049d060(void)

{
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_004bb2c0;
  puStack_10 = &LAB_00499320;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  if (PTR_FUN_004c7204 != (undefined *)0x0) {
    local_8 = 1;
    ExceptionList = &pvStack_14;
    (*(code *)PTR_FUN_004c7204)();
  }
  local_8 = 0xffffffff;
  FUN_0049d0ca();
  FUN_0049d0d0();
  return;
}

