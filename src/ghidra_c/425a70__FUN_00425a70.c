/* FUN_00425a70 @ 00425a70 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall FUN_00425a70(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  void *local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)((int)this + 0x4c) = param_1;
  local_8 = this;
  FUN_00458ec0();
  FUN_00458ec0();
  FUN_00458ec0();
  FUN_00458ec0();
  FUN_00458ec0();
  FUN_00458ec0();
  FUN_00458ec0();
  FUN_00458ec0();
  FUN_00458ec0();
  local_8 = (void *)0x425b53;
  __chkesp();
  return;
}

