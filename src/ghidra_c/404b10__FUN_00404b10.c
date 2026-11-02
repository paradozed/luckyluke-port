/* FUN_00404b10 @ 00404b10 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00404b10(void)

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
  FUN_00433160();
  FUN_00458ec0();
  FUN_004457e0(FUN_00404230);
  uStack_8 = 0x404b54;
  __chkesp();
  return;
}

