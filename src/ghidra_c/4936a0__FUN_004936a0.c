/* FUN_004936a0 @ 004936a0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004936a0(void)

{
  int iVar1;
  undefined4 *puVar2;
  longlong lVar3;
  undefined4 local_50 [16];
  uint local_10;
  uint local_c;
  undefined4 local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  lVar3 = __ftol();
  local_c = (uint)lVar3;
  local_10 = local_c | local_c << 0x10;
  waveOutSetVolume(DAT_00508a0c,local_10);
  __chkesp();
  local_8 = 0x49371b;
  __chkesp();
  return;
}

