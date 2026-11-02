/* FUN_00494340 @ 00494340 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00494340(undefined4 param_1,int param_2,undefined4 param_3,LPWAVEHDR param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar3 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (param_2 == 0x3bd) {
    waveOutUnprepareHeader(DAT_00508a0c,param_4,0x20);
    __chkesp();
    FUN_00494110((undefined *)param_4);
    while (DAT_004e8c40 != '\0') {
      uVar1 = FUN_004941c0();
      if ('\x02' < (char)uVar1) break;
      FUN_00494220(DAT_00508e2c);
    }
  }
  uStack_8 = 0x4943bf;
  __chkesp();
  return;
}

