/* FUN_00488130 @ 00488130 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00488130(void)

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
  _memset(DAT_004e8ae0,0,12000);
  DAT_004e8ae4 = 0;
  uStack_8 = 0x488174;
  __chkesp();
  return;
}

