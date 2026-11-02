/* FUN_00469c40 @ 00469c40 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00469c40(void)

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
  FUN_004669b0(*DAT_004f2458,&DAT_004f2440);
  FUN_00466510(0x15,FUN_00469b60);
  DAT_004f23f8 = FUN_00469b90;
  FUN_00469b90();
  uStack_8 = 0x469c98;
  __chkesp();
  return;
}

