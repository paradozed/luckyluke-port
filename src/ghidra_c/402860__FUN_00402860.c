/* FUN_00402860 @ 00402860 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall
FUN_00402860(void *this,int param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

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
  if (param_1 < *(int *)((int)this + 0x3c)) {
    local_8 = this;
    FUN_00403000(*(void **)((int)this + param_1 * 4 + 0x40),param_2,param_3,param_4);
  }
  local_8 = (void *)0x4028b2;
  __chkesp();
  return;
}

