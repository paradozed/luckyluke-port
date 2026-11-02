/* FUN_00402a10 @ 00402a10 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall FUN_00402a10(void *this,undefined4 param_1,undefined4 param_2)

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
  *(undefined4 *)((int)this + 4) = param_1;
  *(undefined4 *)((int)this + 8) = param_2;
  *(undefined4 *)((int)this + 0x10) = 0xa8;
  *(undefined4 *)((int)this + 0x28) = param_2;
  local_8 = this;
  mixerGetLineInfoA(*(HMIXEROBJ *)((int)this + 4),(LPMIXERLINEA)((int)this + 0x10),3);
  iVar1 = __chkesp();
  if (iVar1 == 0) {
    *(int *)((int)local_8 + 0xc) = (int)local_8 + 0x48;
    *(undefined4 *)((int)local_8 + 0xb8) = 0x18;
    *(undefined4 *)((int)local_8 + 0xc4) = *(undefined4 *)((int)local_8 + 0x34);
    *(undefined4 *)((int)local_8 + 200) = 0x94;
    *(int *)((int)local_8 + 0xcc) = (int)local_8 + 0xd0;
    *(undefined4 *)((int)local_8 + 0xbc) = *(undefined4 *)((int)local_8 + 0x1c);
    mixerGetLineControlsA
              (*(HMIXEROBJ *)((int)local_8 + 4),(LPMIXERLINECONTROLSA)((int)local_8 + 0xb8),0);
    __chkesp();
  }
  local_8 = (void *)0x402b0e;
  __chkesp();
  return;
}

