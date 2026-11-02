/* FUN_0044f240 @ 0044f240 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044f240(void)

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
  DAT_004e8634 = DAT_004e8abc >> 5;
  if (DAT_004e8638 == 0) {
    DAT_004e8638 = DAT_004e8abc >> 5;
  }
  if (600 < DAT_004e8634 - DAT_004e8638) {
    DAT_004e8638 = 0;
    DAT_004f1780 = DAT_004f1780 + -1;
    DAT_004f17e8 = 1;
    DAT_004f1e21 = 1;
    FUN_0041f830('\x01');
    FUN_004200e0('\x01');
    FUN_00449560();
  }
  FUN_0044f490();
  uStack_8 = 0x44f2e4;
  __chkesp();
  return;
}

