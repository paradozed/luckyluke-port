/* FUN_0046b040 @ 0046b040 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0046b040(void)

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
  FUN_00466510(0,FUN_00465a40);
  FUN_004663b0(DAT_004f2404,0,FUN_0046aae0);
  FUN_004663b0(DAT_004f23fc,0,FUN_0046ae40);
  DAT_004f23f8 = FUN_0046af20;
  FUN_0046af20();
  uStack_8 = 0x46b0ae;
  __chkesp();
  return;
}

