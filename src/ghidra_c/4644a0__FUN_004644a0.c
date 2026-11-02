/* FUN_004644a0 @ 004644a0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004644a0(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar4 = local_44;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  cVar1 = FUN_00461250();
  if ((((cVar1 == '\0') && (2 < *(ushort *)(*(int *)(*DAT_004f2458 + 0xc4) + 0x32))) &&
      (*(ushort *)(*(int *)(*DAT_004f2458 + 0xc4) + 0x32) < 5)) && (DAT_004e880d == '\0')) {
    DAT_004e880d = '\x01';
    DAT_004e8810 = 0;
    *(short *)(DAT_004f25b0 + 0xe) = *(short *)(DAT_004f25b0 + 0xe) + 1;
    if (DAT_004e880e == '\0') {
      cVar1 = FUN_00464bf0(3);
      if (cVar1 == '\0') {
        DAT_004f2598 = FUN_0045fdc0;
        FUN_0045fdc0();
      }
      else if (*(ushort *)(DAT_004f25b0 + 0x10) < *(ushort *)(DAT_004f25b0 + 0xe)) {
        *(undefined2 *)(DAT_004f25b0 + 0xe) = 0;
        uVar2 = FUN_0046d700();
        *(short *)(DAT_004f25b0 + 0x10) = (short)((ulonglong)(uVar2 & 0xffff) % 5);
        DAT_004f2598 = FUN_00460db0;
        FUN_00460db0();
      }
      else {
        DAT_004f2598 = FUN_004604d0;
        FUN_004604d0();
      }
    }
  }
  uStack_8 = 0x4645e6;
  __chkesp();
  return;
}

