/* FUN_0040eab0 @ 0040eab0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0040eab0(void)

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
  FUN_004209e0(&DAT_004d2890,0x46,FUN_0040e8b0);
  FUN_004209e0(&DAT_004d2890,0x47,FUN_0040e8f0);
  FUN_004209e0(&DAT_004d2890,0x48,FUN_0040e930);
  FUN_004209e0(&DAT_004d2890,0x5b,FUN_0040e970);
  FUN_004209e0(&DAT_004d2890,0x5c,FUN_0040e9e0);
  FUN_004209e0(&DAT_004d2890,0x5d,FUN_0040ea50);
  uStack_8 = 0x40eb3b;
  __chkesp();
  return;
}

