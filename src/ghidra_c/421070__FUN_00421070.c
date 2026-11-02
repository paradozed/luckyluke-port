/* FUN_00421070 @ 00421070 */
/* decompiled from Lucky.exe (Game.run) */


void __fastcall FUN_00421070(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_58 [16];
  int local_18;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_004b2868;
  local_10 = ExceptionList;
  puVar2 = local_58;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = 1;
  local_18 = 0;
  ExceptionList = &local_10;
  local_14 = param_1;
  while( true ) {
    iVar1 = FUN_004222b0((undefined4 *)((int)local_14 + 0x24));
    if (iVar1 <= local_18) break;
    FUN_004212d0(local_14,local_18 + 1);
    local_18 = local_18 + 1;
  }
  local_8 = local_8 & 0xffffff00;
  FUN_00422210((int)local_14 + 0x24);
  local_8 = 0xffffffff;
  FUN_00420cd0((int)local_14 + 8);
  ExceptionList = local_10;
  local_8 = 0x421114;
  __chkesp();
  return;
}

