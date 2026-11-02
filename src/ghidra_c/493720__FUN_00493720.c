/* FUN_00493720 @ 00493720 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00493720(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  DWORD local_c [2];
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  waveOutGetVolume(DAT_00508a0c,local_c);
  __chkesp();
  __ftol();
  local_c[1] = 0x49377f;
  __chkesp();
  return;
}

