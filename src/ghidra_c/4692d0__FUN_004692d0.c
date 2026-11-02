/* FUN_004692d0 @ 004692d0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004692d0(void)

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
  if ((*(uint *)(DAT_004f2458 + 0x10) & 4) != 0) {
    DAT_004f2400 = FUN_00465b50;
    FUN_00466510(0x16,FUN_004691c0);
    DAT_004f23f8 = FUN_004691e0;
    FUN_004691e0();
  }
  if ((*(uint *)(DAT_004f2458 + 0x10) & 0x10) != 0) {
    FUN_00469170();
  }
  uStack_8 = 0x469341;
  __chkesp();
  return;
}

