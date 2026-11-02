/* FUN_0045e070 @ 0045e070 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0045e070(void)

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
  FUN_004266b0();
  FUN_00449380();
  FUN_004266b0();
  DAT_004e8700 = 1;
  uStack_8 = 0x45e0dd;
  __chkesp();
  return;
}

