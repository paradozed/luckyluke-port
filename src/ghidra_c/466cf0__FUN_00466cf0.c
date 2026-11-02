/* FUN_00466cf0 @ 00466cf0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00466cf0(void)

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
  DAT_004f2400 = FUN_00465ab0;
  FUN_004669b0(*DAT_004f2458,&DAT_004f2440);
  FUN_00466510(4,FUN_00466b40);
  DAT_004f23f8 = FUN_00466b60;
  FUN_00466b60();
  uStack_8 = 0x466d52;
  __chkesp();
  return;
}

