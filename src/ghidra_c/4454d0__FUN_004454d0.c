/* FUN_004454d0 @ 004454d0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004454d0(void)

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
  FUN_00445740();
  while (DAT_004bcfe8 == '\0') {
    if (DAT_004bcfec != 0) {
      FUN_0041f830('\x01');
      FUN_004200e0('\x01');
      DAT_004bcfec = 0;
    }
    FUN_00445740();
    Sleep(10);
    __chkesp();
  }
  if (DAT_004bcfec == 0) {
    FUN_0041f830('\0');
    FUN_004200e0('\0');
    DAT_004bcfec = 1;
  }
  uStack_8 = 0x44556b;
  __chkesp();
  return;
}

