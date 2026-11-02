/* FUN_004699b0 @ 004699b0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004699b0(void)

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
  FUN_004669b0(*DAT_004f2458,(undefined4 *)&DAT_004f23e0);
  FUN_00466510(0x14,FUN_00469850);
  DAT_004f2400 = FUN_00465a60;
  DAT_004f23f8 = FUN_00469870;
  FUN_00469870();
  uStack_8 = 0x469a12;
  __chkesp();
  return;
}

