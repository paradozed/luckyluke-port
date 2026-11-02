/* FUN_004212d0 @ 004212d0 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall FUN_004212d0(void *this,int param_1)

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
  piVar1 = (int *)FUN_00422270((void *)((int)this + 0x24),param_1 + -1);
  if (*piVar1 != 0) {
    puVar2 = (undefined4 *)FUN_00422270((void *)((int)local_8 + 0x24),param_1 + -1);
    local_10 = (void *)*puVar2;
    local_c = local_10;
    if (local_10 == (void *)0x0) {
      local_14 = 0;
    }
    else {
      local_14 = FUN_00421270(local_10,1);
    }
    puVar2 = (undefined4 *)FUN_00422270((void *)((int)local_8 + 0x24),param_1 + -1);
    *puVar2 = 0;
  }
  local_8 = (void *)0x421367;
  __chkesp();
  return;
}

