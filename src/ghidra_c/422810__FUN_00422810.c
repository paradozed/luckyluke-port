/* FUN_00422810 @ 00422810 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall FUN_00422810(void *this,int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  undefined4 local_c;
  void *local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(int *)this = param_1;
  local_8 = this;
  local_c = FUN_00496760(*(int *)this << 2);
  *(undefined4 *)((int)local_8 + 4) = local_c;
  local_8 = (void *)0x42286e;
  __chkesp();
  return;
}

