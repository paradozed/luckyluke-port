/* FUN_00420700 @ 00420700 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00420700(void)

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
  FUN_00496e40(0x420740);
  uStack_8 = 0x420732;
  __chkesp();
  return;
}

