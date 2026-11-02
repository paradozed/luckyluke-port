/* FUN_00461a10 @ 00461a10 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00461a10(void)

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
  DAT_004f1780 = DAT_004f1780 + -1;
  if (DAT_004f1780 != 0) {
    if (DAT_004f1780 != 0) {
      *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x12) = 9;
    }
    FUN_0041f830('\x01');
    FUN_004200e0('\x01');
  }
  DAT_004e8812 = 1;
  uStack_8 = 0x461a84;
  __chkesp();
  return;
}

