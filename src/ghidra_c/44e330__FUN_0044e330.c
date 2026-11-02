/* FUN_0044e330 @ 0044e330 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044e330(void)

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
  FUN_0044cbb0();
  if ((int)(uint)DAT_004bd05c <= (int)*(short *)(*(int *)(DAT_004f1578 + 4) + 0x16)) {
    DAT_004f23f8 = FUN_0044e3d0;
    FUN_0044e3d0();
  }
  uStack_8 = 0x44e381;
  __chkesp();
  return;
}

