/* FUN_004943d0 @ 004943d0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004943d0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  DAT_004e8c40 = 0;
  waveOutReset(DAT_00508a0c);
  __chkesp();
  waveOutClose(DAT_00508a0c);
  __chkesp();
  if (DAT_004e8c44 != (void *)0x0) {
    FUN_00495280(DAT_004e8c44);
    DAT_004e8c44 = (void *)0x0;
  }
  uStack_8 = 0x494449;
  __chkesp();
  return;
}

