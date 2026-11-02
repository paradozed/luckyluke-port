/* FUN_00425cd0 @ 00425cd0 */
/* decompiled from Lucky.exe (Game.run) */


void __fastcall FUN_00425cd0(char *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  undefined4 local_c;
  char *local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = param_1;
  if (param_1[0x50] != '\0') {
    waveOutPause(*(HWAVEOUT *)(param_1 + 0x48));
    __chkesp();
    waveOutReset(*(HWAVEOUT *)(local_8 + 0x48));
    __chkesp();
    if (*local_8 != '\0') {
      waveOutClose(*(HWAVEOUT *)(local_8 + 0x48));
      __chkesp();
    }
  }
  local_c = (uint)local_c._2_2_ << 0x10;
  while ((local_c & 0xffff) < 0x10) {
    if (*(int *)(local_8 + (local_c & 0xffff) * 4 + 4) != 0) {
      FUN_00495280(*(void **)(local_8 + (local_c & 0xffff) * 4 + 4));
    }
    local_c = CONCAT22(local_c._2_2_,(short)local_c + 1);
  }
  local_8 = (char *)0x425da2;
  __chkesp();
  return;
}

