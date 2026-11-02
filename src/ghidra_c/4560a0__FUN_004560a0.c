/* FUN_004560a0 @ 004560a0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004560a0(void)

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
  DAT_004e864c = 15000;
  DAT_004e868c = 0;
  DAT_004e868a = 0;
  DAT_004e8688 = 0;
  DAT_004bd6a0 = 0;
  DAT_004bd6a4 = 0;
  DAT_004bd6a8 = 0;
  PTR_FUN_004bd5d8 = FUN_00455cf0;
  FUN_00455cf0();
  __chkesp();
  uStack_8 = 0x456129;
  __chkesp();
  return;
}

