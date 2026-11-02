/* FUN_00445870 @ 00445870 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00445870(HINSTANCE param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_5c [16];
  undefined1 *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_004b7978;
  puStack_10 = &LAB_00499320;
  local_14 = ExceptionList;
  local_1c = &stack0xffffff98;
  puVar2 = local_5c;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = &local_14;
  iVar1 = FUN_00445630(param_1);
  if (iVar1 != 0) {
    local_8 = 0;
    FUN_004067e0();
  }
  ExceptionList = local_14;
  local_8 = 0x44591a;
  __chkesp();
  return;
}

