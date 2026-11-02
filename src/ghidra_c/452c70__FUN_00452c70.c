/* FUN_00452c70 @ 00452c70 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00452c70(void)

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
  if (DAT_004f2bf8 != 0xb) {
    FUN_00451500(&DAT_004bd6a0,&DAT_004e8688,DAT_004bd6a8);
  }
  uStack_8 = 0x452cbb;
  __chkesp();
  return;
}

