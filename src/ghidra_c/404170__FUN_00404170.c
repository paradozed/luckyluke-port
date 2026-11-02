/* FUN_00404170 @ 00404170 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00404170(void)

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
  FUN_004222e0((undefined4 *)&DAT_004d1da8);
  uStack_8 = 0x40419f;
  __chkesp();
  return;
}

