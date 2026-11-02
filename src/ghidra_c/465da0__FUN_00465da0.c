/* FUN_00465da0 @ 00465da0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00465da0(void)

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
  DAT_004f2400 = FUN_00465d30;
  FUN_00465d30();
  __chkesp();
  uStack_8 = 0x465dde;
  __chkesp();
  return;
}

