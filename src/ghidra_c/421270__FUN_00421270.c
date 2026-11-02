/* FUN_00421270 @ 00421270 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall FUN_00421270(void *this,uint param_1)

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
  local_8 = this;
  FUN_00422ab0((int)this);
  if ((param_1 & 1) != 0) {
    FUN_004966d0(local_8);
  }
  local_8 = (void *)0x4212bb;
  __chkesp();
  return;
}

