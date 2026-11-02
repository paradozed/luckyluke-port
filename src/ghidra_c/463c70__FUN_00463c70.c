/* FUN_00463c70 @ 00463c70 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00463c70(void)

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
  FUN_00466510(6,FUN_00463ab0);
  DAT_004f23f8 = FUN_00463cc0;
  FUN_00463cc0();
  uStack_8 = 0x463cb3;
  __chkesp();
  return;
}

