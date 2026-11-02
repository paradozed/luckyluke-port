/* FUN_00468d80 @ 00468d80 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00468d80(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [17];
  
  uVar1 = DAT_004e89e0;
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  *(undefined1 *)(*(int *)(DAT_004f2458 + 0x9c) + 0x14) = 1;
  *(uint *)(DAT_004f2458 + 0x10) = *(uint *)(DAT_004f2458 + 0x10) | 0x8000;
  if (DAT_004e8850 == 0) {
    DAT_004e8850 = DAT_004e89e0;
  }
  if (uVar1 - DAT_004e8850 < 0x79) {
    if ((uVar1 & 8) == 0) {
      *(undefined1 *)(*(int *)(DAT_004f2458 + 0x9c) + 0x14) = 0;
    }
  }
  else {
    DAT_004e8850 = 0;
    DAT_004f23b8 = 0;
    *(uint *)(DAT_004f2458 + 0x10) = *(uint *)(DAT_004f2458 + 0x10) & 0xffff7fff;
  }
  return;
}

