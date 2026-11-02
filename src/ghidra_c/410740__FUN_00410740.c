/* FUN_00410740 @ 00410740 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00410740(void)

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
  DAT_004f13a0 = FUN_00477aa0();
  uStack_8 = 0x41076f;
  __chkesp();
  return;
}

