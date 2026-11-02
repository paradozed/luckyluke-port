/* FUN_0040e810 @ 0040e810 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0040e810(void)

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
  FUN_004209e0(&DAT_004d2890,0x4a,FUN_0040e7e0);
  uStack_8 = 0x40e846;
  __chkesp();
  return;
}

