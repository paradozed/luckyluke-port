/* FUN_00414540 @ 00414540 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00414540(void)

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
  DAT_004e8750 = DAT_004e8750 ^ 1;
  FUN_0045e280();
  FUN_004422a0();
  uStack_8 = 0x41457c;
  __chkesp();
  return;
}

