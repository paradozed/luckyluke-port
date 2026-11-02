/* FUN_0044dd10 @ 0044dd10 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044dd10(void)

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
  *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x10) = 0;
  *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x30) = 0;
  *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x32) = 0;
  *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x12) = 0;
  DAT_004f2c7a = 0;
  DAT_004f23f8 = FUN_0044dde0;
  FUN_0044dde0();
  uStack_8 = 0x44dd85;
  __chkesp();
  return;
}

