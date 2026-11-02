/* FUN_00466900 @ 00466900 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00466900(void)

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
  DAT_004f240c = 0;
  DAT_004f2458[4] = DAT_004f2458[4] & 0xfffdffff;
  FUN_004669b0(*DAT_004f2458,&DAT_004f2440);
  DAT_004f2400 = FUN_00465a60;
  _DAT_004e8848 = DAT_004e89e0;
  DAT_004f2458[4] = DAT_004f2458[4] & 0xffffffbf;
  FUN_00466510(0,FUN_00466570);
  DAT_004f23f8 = FUN_00466740;
  FUN_00466740();
  uStack_8 = 0x4669a2;
  __chkesp();
  return;
}

