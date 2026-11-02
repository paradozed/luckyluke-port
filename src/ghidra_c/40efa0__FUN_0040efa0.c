/* FUN_0040efa0 @ 0040efa0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0040efa0(void)

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
  FUN_00420990(&DAT_004d2890,0xaa,FUN_0040eb40);
  FUN_00420990(&DAT_004d2890,0xab,FUN_0040ec60);
  FUN_00420990(&DAT_004d2890,0xac,FUN_0040ed50);
  FUN_00420990(&DAT_004d2890,0xad,FUN_0040ee10);
  FUN_00420990(&DAT_004d2890,0xae,FUN_0040ee50);
  FUN_00420990(&DAT_004d2890,0xaf,FUN_0040eeb0);
  FUN_00420990(&DAT_004d2890,0xb0,FUN_0040ef40);
  uStack_8 = 0x40f051;
  __chkesp();
  return;
}

