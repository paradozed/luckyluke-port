/* FUN_0046b950 @ 0046b950 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0046b950(void)

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
  FUN_004663b0(DAT_004f2404,4,FUN_0046aae0);
  DAT_004f23f8 = FUN_0046b840;
  FUN_0046b840();
  uStack_8 = 0x46b999;
  __chkesp();
  return;
}

