/* FUN_0046b1e0 @ 0046b1e0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0046b1e0(void)

{
  int iVar1;
  undefined4 *puVar2;
  bool bVar3;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  bVar3 = DAT_004e8836 == '\x03';
  DAT_004e8836 = DAT_004e8836 + '\x01';
  if (bVar3) {
    DAT_004e8836 = '\0';
    FUN_004663b0(DAT_004f23fc,0,FUN_0046ae40);
  }
  uStack_8 = 0x46b23d;
  __chkesp();
  return;
}

