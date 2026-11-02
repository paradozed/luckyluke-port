/* FUN_0045ca10 @ 0045ca10 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0045ca10(void)

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
  DAT_004f2930 = FUN_00439af0(0x5000);
  DAT_004f2934 = FUN_00439af0(0x5000);
  uStack_8 = 0x45ca59;
  __chkesp();
  return;
}

