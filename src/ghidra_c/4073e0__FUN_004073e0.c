/* FUN_004073e0 @ 004073e0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004073e0(void)

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
  FUN_004209e0(&DAT_004d2890,0x78,FUN_00406f80);
  FUN_004209e0(&DAT_004d2890,0x79,FUN_00406ff0);
  FUN_004209e0(&DAT_004d2890,0x7a,FUN_00407020);
  FUN_004209e0(&DAT_004d2890,0x7b,FUN_00407050);
  FUN_004209e0(&DAT_004d2890,0x7c,FUN_00407080);
  FUN_004209e0(&DAT_004d2890,0x7d,FUN_004070d0);
  FUN_004209e0(&DAT_004d2890,0x7e,FUN_00407110);
  FUN_004209e0(&DAT_004d2890,0x7f,FUN_00407320);
  FUN_004209e0(&DAT_004d2890,0x80,FUN_00407390);
  uStack_8 = 0x4074a1;
  __chkesp();
  return;
}

