/* FUN_0046b5c0 @ 0046b5c0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046b5c0(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar4 = local_44;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  uVar2 = FUN_0041ff20();
  if ((uVar2 & 0xff) == 1) {
    cVar1 = FUN_0041fbb0(DAT_004f23bc);
    if (cVar1 == '\0') {
      FUN_0041fc80(DAT_004f23bc);
      DAT_004f23bc = FUN_0041f5e0(2,2,0x15e,0xfff,0x800,'\0');
      FUN_0041fc30(DAT_004f23bc);
    }
  }
  if (((DAT_004f2438 & 0x80) == 0) || (0x32 < (uint)(DAT_004e89e0 - _DAT_004f2408))) {
    FUN_0041f7b0(DAT_004f23bc);
    FUN_0041fc80(DAT_004f23bc);
    uVar2 = FUN_0041ff20();
    if ((uVar2 & 0xff) == 1) {
      FUN_0041f5e0(2,3,0x32,0x1fff,0,'\0');
    }
    DAT_004f23f8 = FUN_0046b040;
    FUN_0046b040();
  }
  else if ((DAT_004f2458[4] & 0x20U) == 0) {
    FUN_0041f7b0(DAT_004f23bc);
    FUN_0041fc80(DAT_004f23bc);
    DAT_004f23f8 = FUN_0046bcf0;
    FUN_0046bcf0();
  }
  else if ((DAT_004f245c & 0x8000) == 0) {
    if (((DAT_004f29ac == '\0') && (**(char **)(*(int *)(*DAT_004f2458 + 0xe4) + 0x14) == '\x03'))
       && ((short)DAT_004f2458[0x29] == *(short *)(*(int *)(*DAT_004f2458 + 0xe4) + 0x58))) {
      FUN_0041f7b0(DAT_004f23bc);
      FUN_0041fc80(DAT_004f23bc);
      DAT_004f23f8 = FUN_0046ac90;
      FUN_0046ac90();
    }
  }
  else {
    DAT_004f23f8 = FUN_0046ba90;
    FUN_0046ba90();
  }
  uStack_8 = 0x46b79d;
  __chkesp();
  return;
}

