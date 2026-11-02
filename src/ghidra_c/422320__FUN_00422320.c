/* FUN_00422320 @ 00422320 */
/* decompiled from Lucky.exe (Game.run) */


void __fastcall FUN_00422320(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_58 [16];
  int local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_004b28a9;
  local_10 = ExceptionList;
  puVar2 = local_58;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = 0;
  local_18 = 0;
  ExceptionList = &local_10;
  local_14 = param_1;
  while( true ) {
    iVar1 = FUN_00422920(local_14);
    if (iVar1 <= local_18) break;
    FUN_00422610(local_14,local_18 + 1);
    local_18 = local_18 + 1;
  }
  local_8 = 0xffffffff;
  FUN_00422880((int)local_14);
  ExceptionList = local_10;
  local_8 = 0x4223af;
  __chkesp();
  return;
}

