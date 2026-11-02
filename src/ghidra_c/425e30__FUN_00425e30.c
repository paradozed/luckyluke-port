/* FUN_00425e30 @ 00425e30 */
/* decompiled from Lucky.exe (Game.run) */


void __fastcall FUN_00425e30(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = param_1;
  waveOutWrite(*(HWAVEOUT *)(param_1 + 0x48),
               *(LPWAVEHDR *)(param_1 + 4 + (uint)*(byte *)(param_1 + 0x44) * 4),0x20);
  __chkesp();
  *(char *)(local_8 + 1) = *(char *)(local_8 + 1) + '\x01';
  *(char *)(local_8 + 0x44) = *(char *)(local_8 + 0x44) + '\x01';
  if (0xf < *(byte *)(local_8 + 0x44)) {
    *(undefined1 *)(local_8 + 0x44) = 0;
  }
  local_8 = 0x425eb4;
  __chkesp();
  return;
}

