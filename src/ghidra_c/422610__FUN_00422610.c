/* FUN_00422610 @ 00422610 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall FUN_00422610(void *this,int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 local_54 [16];
  undefined4 local_14;
  void *local_10;
  void *local_c;
  void *local_8;
  
  puVar2 = local_54;
  for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = this;
  piVar1 = (int *)FUN_004228e0(this,param_1 + -1);
  if (*piVar1 != 0) {
    puVar2 = (undefined4 *)FUN_004228e0(local_8,param_1 + -1);
    local_10 = (void *)*puVar2;
    local_c = local_10;
    if (local_10 == (void *)0x0) {
      local_14 = 0;
    }
    else {
      local_14 = FUN_004225b0(local_10,1);
    }
  }
  puVar2 = (undefined4 *)FUN_004228e0(local_8,param_1 + -1);
  *puVar2 = 0;
  local_8 = (void *)0x422699;
  __chkesp();
  return;
}

