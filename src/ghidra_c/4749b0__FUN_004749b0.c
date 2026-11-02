/* FUN_004749b0 @ 004749b0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004749b0(void)

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
  if (DAT_004f1780 < 0) {
    DAT_004f1780 = 0;
  }
  if (DAT_004f1780 == 0) {
    FUN_00473af0();
    DAT_004f16c8 = 0;
    DAT_004e8914 = 0x1d;
    DAT_004e8916 = 0x1d;
  }
  uStack_8 = 0x474a18;
  __chkesp();
  return;
}

