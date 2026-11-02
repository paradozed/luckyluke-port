/* FUN_00402c70 @ 00402c70 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall FUN_00402c70(void *this,int param_1)

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
  *(undefined4 *)((int)this + 0xc60) = 0x18;
  *(undefined4 *)((int)this + 0xc64) = *(undefined4 *)((int)this + param_1 * 0x94 + 0xd4);
  *(undefined4 *)((int)this + 0xc68) = 1;
  *(undefined4 *)((int)this + 0xc6c) = 0;
  *(undefined4 *)((int)this + 0xc6c) = 0;
  local_8 = this;
  local_c = FUN_00402c20(this,param_1);
  if (local_c == 1) {
    *(undefined4 *)((int)local_8 + 0xc70) = 4;
    *(undefined4 *)((int)local_8 + 0xc88) = 0;
    *(int *)((int)local_8 + 0xc74) = (int)local_8 + 0xc88;
    mixerGetControlDetailsA
              (*(HMIXEROBJ *)((int)local_8 + 4),(LPMIXERCONTROLDETAILS)((int)local_8 + 0xc60),0);
    __chkesp();
  }
  else if (local_c == 2) {
    *(undefined4 *)((int)local_8 + 0xc70) = 4;
    *(undefined4 *)((int)local_8 + 0xc84) = 0;
    *(int *)((int)local_8 + 0xc74) = (int)local_8 + 0xc84;
    mixerGetControlDetailsA
              (*(HMIXEROBJ *)((int)local_8 + 4),(LPMIXERCONTROLDETAILS)((int)local_8 + 0xc60),0);
    __chkesp();
  }
  else if (local_c == 3) {
    *(undefined4 *)((int)local_8 + 0xc70) = 4;
    *(undefined4 *)((int)local_8 + 0xc80) = 0;
    *(int *)((int)local_8 + 0xc74) = (int)local_8 + 0xc80;
    mixerGetControlDetailsA
              (*(HMIXEROBJ *)((int)local_8 + 4),(LPMIXERCONTROLDETAILS)((int)local_8 + 0xc60),0);
    __chkesp();
  }
  local_8 = (void *)0x402e3d;
  __chkesp();
  return;
}

