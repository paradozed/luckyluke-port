/* FUN_0044e390 @ 0044e390 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044e390(void)

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
  DAT_004f23f8 = FUN_0044e490;
  FUN_0044e490();
  uStack_8 = 0x44e3c4;
  __chkesp();
  return;
}

