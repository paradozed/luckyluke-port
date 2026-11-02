/* FUN_0046ae40 @ 0046ae40 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0046ae40(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar3 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (*(int *)(DAT_004f2458 + 0xac) < 0x201) {
    uVar1 = FUN_004971c0();
    uVar1 = uVar1 & 0x80000001;
    if ((int)uVar1 < 0) {
      uVar1 = (uVar1 - 1 | 0xfffffffe) + 1;
    }
    if (uVar1 == 0) {
      uVar1 = FUN_0041ff20();
      if ((uVar1 & 0xff) == 1) {
        uVar1 = FUN_0046d700();
        if ((uVar1 & 0xffff) % 5 == 3) {
          FUN_0041f5e0(4,0x10,0,0x1964,0,'\0');
        }
      }
      FUN_004663b0(DAT_004f23fc,3,FUN_0046ad90);
    }
    else {
      FUN_004663b0(DAT_004f23fc,0,FUN_0046ae40);
    }
  }
  else {
    FUN_004663b0(DAT_004f23fc,4,FUN_0046ae40);
  }
  uStack_8 = 0x46af11;
  __chkesp();
  return;
}

