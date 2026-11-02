/* FUN_00460b50 @ 00460b50 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00460b50(void)

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
  DAT_004f2564 = 0;
  FUN_0045f940(0xe,FUN_004609b0);
  DAT_004f2598 = FUN_00460ba0;
  FUN_00460ba0();
  uStack_8 = 0x460b9a;
  __chkesp();
  return;
}

