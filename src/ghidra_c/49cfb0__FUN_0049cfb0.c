/* FUN_0049cfb0 @ 0049cfb0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0049cfb0(void)

{
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_004bb2a8;
  puStack_10 = &LAB_00499320;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  if (DAT_004e8ce4 != (code *)0x0) {
    local_8 = 1;
    ExceptionList = &pvStack_14;
    (*DAT_004e8ce4)();
  }
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _abort();
}

