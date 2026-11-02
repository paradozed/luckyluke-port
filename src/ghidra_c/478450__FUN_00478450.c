/* FUN_00478450 @ 00478450 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00478450(void)

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
  if (DAT_004be2ed != '\0') {
    DAT_004be2ed = '\0';
  }
  DAT_004e89d9 = 1;
  FUN_0046dc30();
  DAT_004e89d9 = 0;
  DAT_004be2e4 = 0;
  DAT_004e89da = 0;
  PTR_DAT_004be2e0 = &DAT_004e93a0 + (uint)DAT_004e89d8 * 0x4000;
  uStack_8 = 0x4784c1;
  __chkesp();
  return;
}

