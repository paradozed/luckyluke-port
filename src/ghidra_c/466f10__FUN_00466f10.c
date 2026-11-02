/* FUN_00466f10 @ 00466f10 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00466f10(void)

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
  DAT_004f2400 = FUN_00465b00;
  FUN_004669b0(*DAT_004f2458,&DAT_004f2440);
  FUN_00466510(5,FUN_00466d60);
  DAT_004f23f8 = FUN_00466d80;
  FUN_00466d80();
  uStack_8 = 0x466f72;
  __chkesp();
  return;
}

