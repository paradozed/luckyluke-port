/* FUN_00401500 @ 00401500 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall FUN_00401500(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [13];
  undefined4 uStack_14;
  void *local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = this;
  AVIFileInfoA(*(undefined4 *)((int)this + 0xff8),param_1,0x6c);
  uStack_14 = 0x401541;
  __chkesp();
  return;
}

