/* FUN_0040ca00 @ 0040ca00 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0040ca00(void)

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
  FUN_004209e0(&DAT_004d2890,0x4b,FUN_0040c850);
  FUN_004209e0(&DAT_004d2890,0x4c,FUN_0040c8b0);
  FUN_004209e0(&DAT_004d2890,0x4d,FUN_0040c8f0);
  FUN_004209e0(&DAT_004d2890,0x4e,FUN_0040c960);
  FUN_004209e0(&DAT_004d2890,0x4f,FUN_0040c9a0);
  uStack_8 = 0x40ca7a;
  __chkesp();
  return;
}

