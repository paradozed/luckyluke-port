/* FUN_00401a10 @ 00401a10 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall FUN_00401a10(void *this,undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [15];
  undefined4 uStack_10;
  int local_c;
  void *local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = this;
  local_c = AVIStreamGetFrame(*(undefined4 *)((int)this + *(int *)((int)this + 0x58) * 4 + 0x148),0)
  ;
  if (local_c != 0) {
    *(undefined1 *)(param_1 + 2) = *(undefined1 *)(local_c + 0xe);
    param_1[1] = *(undefined4 *)(local_c + 8);
    *param_1 = *(undefined4 *)(local_c + 4);
  }
  uStack_10 = 0x401a84;
  __chkesp();
  return;
}

