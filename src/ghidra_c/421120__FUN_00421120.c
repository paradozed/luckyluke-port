/* FUN_00421120 @ 00421120 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00421120(undefined4 param_1,undefined4 param_2,size_t param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_74 [16];
  undefined4 local_34;
  void *local_30;
  void *local_2c;
  void *local_28;
  void *local_24;
  void *local_20;
  void *local_1c;
  int local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004b288b;
  local_10 = ExceptionList;
  puVar3 = local_74;
  for (iVar2 = 0x19; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  ExceptionList = &local_10;
  local_24 = (void *)FUN_00496760(0x98);
  local_8 = 0;
  if (local_24 == (void *)0x0) {
    local_30 = (void *)0x0;
  }
  else {
    local_30 = (void *)FUN_00422950(local_24,param_1,*local_14,param_2,param_3,local_14);
  }
  local_20 = local_30;
  local_8 = 0xffffffff;
  local_1c = local_30;
  if (local_30 != (void *)0x0) {
    local_18 = 0;
    while (iVar2 = FUN_004222b0(local_14 + 9), local_18 < iVar2) {
      piVar1 = (int *)FUN_00422270(local_14 + 9,local_18);
      if (*piVar1 == 0) {
        piVar1 = (int *)FUN_00422270(local_14 + 9,local_18);
        *piVar1 = (int)local_1c;
        break;
      }
      local_18 = local_18 + 1;
    }
    iVar2 = FUN_004222b0(local_14 + 9);
    if (local_18 == iVar2) {
      local_2c = local_1c;
      local_28 = local_1c;
      if (local_1c == (void *)0x0) {
        local_34 = 0;
      }
      else {
        local_34 = FUN_00421270(local_1c,1);
      }
    }
  }
  ExceptionList = local_10;
  local_8 = 0x421261;
  __chkesp();
  return;
}

