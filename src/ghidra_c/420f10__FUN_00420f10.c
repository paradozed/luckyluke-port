/* FUN_00420f10 @ 00420f10 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall FUN_00420f10(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_5c [16];
  uint local_1c;
  int local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004b2838;
  local_10 = ExceptionList;
  puVar1 = local_5c;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0xcccccccc;
    puVar1 = puVar1 + 1;
  }
  ExceptionList = &local_10;
  local_14 = this;
  FUN_00420c50((undefined1 *)((int)this + 8));
  local_8 = 0;
  FUN_00422160(local_14 + 9);
  local_8 = CONCAT31(local_8._1_3_,1);
  *local_14 = param_1;
  local_14[1] = param_2;
  iVar2 = FUN_00420d10(local_14 + 2,*local_14);
  if (iVar2 == 0) {
    FUN_00477a60();
  }
  if (local_14[1] == 0) {
    local_14[1] = (uint)*(ushort *)(local_14 + 4);
  }
  else {
    if ((int)local_14[1] < (int)(uint)*(ushort *)(local_14 + 4)) {
      local_1c = local_14[1];
    }
    else {
      local_1c = (uint)*(ushort *)(local_14 + 4);
    }
    local_14[1] = local_1c;
  }
  iVar2 = FUN_004221a0(local_14 + 9,local_14[1]);
  if (iVar2 == 0) {
    FUN_00477a60();
  }
  local_18 = 0;
  while( true ) {
    iVar2 = FUN_004222b0(local_14 + 9);
    if (iVar2 <= local_18) break;
    puVar1 = (undefined4 *)FUN_00422270(local_14 + 9,local_18);
    *puVar1 = 0;
    local_18 = local_18 + 1;
  }
  ExceptionList = local_10;
  local_8 = 0x42105e;
  __chkesp();
  return;
}

