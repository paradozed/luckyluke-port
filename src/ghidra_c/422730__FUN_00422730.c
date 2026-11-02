/* FUN_00422730 @ 00422730 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall FUN_00422730(void *this,int param_1,undefined4 param_2,undefined *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_48 [16];
  void *local_8;
  
  puVar1 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0xcccccccc;
    puVar1 = puVar1 + 1;
  }
  local_8 = this;
  puVar1 = (undefined4 *)FUN_004228e0(this,param_1 + -1);
  FUN_004214f0((void *)*puVar1,param_2,param_3);
  local_8 = (void *)0x422778;
  __chkesp();
  return;
}

