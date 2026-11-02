/* FUN_00464790 @ 00464790 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00464790(void)

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
  DAT_004f2564 = 0;
  DAT_004f23f8 = FUN_00462f20;
  FUN_00462f20();
  uStack_8 = 0x4647cb;
  __chkesp();
  return;
}

