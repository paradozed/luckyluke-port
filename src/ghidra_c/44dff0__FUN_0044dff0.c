/* FUN_0044dff0 @ 0044dff0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044dff0(void)

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
  if ((int)(uint)DAT_004bd058 <= (int)*(short *)(*(int *)(DAT_004f1578 + 4) + 0x16)) {
    DAT_004f23f8 = FUN_0044e0a0;
    FUN_0044e0a0();
  }
  uStack_8 = 0x44e041;
  __chkesp();
  return;
}

