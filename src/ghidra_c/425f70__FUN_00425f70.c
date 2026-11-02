/* FUN_00425f70 @ 00425f70 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall FUN_00425f70(void *this,undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  int local_10;
  int local_c;
  void *local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = this;
  waveOutOpen((LPHWAVEOUT)((int)this + 0x48),0xffffffff,*(LPCWAVEFORMATEX *)((int)this + 0x4c),
              *(DWORD_PTR *)((int)this + 0x54),0,0x30000);
  local_10 = __chkesp();
  local_c = local_10;
  switch(local_10) {
  case 0:
    *(undefined1 *)((int)local_8 + 0x50) = 1;
    break;
  case 4:
    if (param_2 == 0) {
      sndPlaySoundA((LPCSTR)0x0,0);
      __chkesp();
      waveOutOpen((LPHWAVEOUT)((int)local_8 + 0x48),0xffffffff,
                  *(LPCWAVEFORMATEX *)((int)local_8 + 0x4c),*(DWORD_PTR *)((int)local_8 + 0x54),0,
                  0x30000);
      local_c = __chkesp();
      if (local_c != 0) break;
    }
    if (param_2 == 1) break;
    if (param_2 == 2) {
      while (local_c != 0) {
        waveOutOpen((LPHWAVEOUT)((int)local_8 + 0x48),0xffffffff,
                    *(LPCWAVEFORMATEX *)((int)local_8 + 0x4c),*(DWORD_PTR *)((int)local_8 + 0x54),0,
                    0x30000);
        local_c = __chkesp();
        FUN_00458ec0();
      }
      *(undefined1 *)((int)local_8 + 0x50) = 1;
      break;
    }
  default:
    break;
  case 6:
    break;
  case 7:
  }
  local_8 = (void *)0x4260bd;
  __chkesp();
  return;
}

