/* FUN_004028c0 @ 004028c0 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall FUN_004028c0(void *this,int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  uint local_c;
  void *local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 < *(int *)((int)this + 0x3c)) {
    local_8 = this;
    local_c = FUN_00402c20(*(void **)((int)this + param_1 * 4 + 0x40),param_2);
  }
  local_8 = (void *)0x402924;
  __chkesp();
  return;
}

