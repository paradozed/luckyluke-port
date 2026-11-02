/* FUN_00494220 @ 00494220 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00494220(DWORD param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  LPWAVEHDR local_10;
  uint local_c;
  int local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004e8c40 != '\0') {
    local_10 = (LPWAVEHDR)FUN_00494080();
    local_10->dwBufferLength = param_1;
    local_10->dwFlags = 0;
    local_10->dwLoops = 0;
    waveOutPrepareHeader(DAT_00508a0c,local_10,0x20);
    iVar1 = __chkesp();
    if (iVar1 == 0) {
      local_8 = 0;
      for (local_c = 0; local_c < DAT_00508a10; local_c = local_c + 1) {
        (*DAT_00508e30)(local_10->lpData,local_c & 0xff);
        __chkesp();
      }
      waveOutWrite(DAT_00508a0c,local_10,0x20);
      local_8 = __chkesp();
      if (local_8 != 0) {
        waveOutUnprepareHeader(DAT_00508a0c,local_10,0x20);
        __chkesp();
        FUN_00494110((undefined *)local_10);
      }
    }
  }
  local_8 = 0x494334;
  __chkesp();
  return;
}

