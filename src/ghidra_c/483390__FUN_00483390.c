/* FUN_00483390 @ 00483390 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00483390(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  DAT_004be3d8 = DAT_004be3d8 + 1;
  DAT_00508840 = *(undefined2 *)(DAT_004be3d8 * 0x20 + 0x5081c0);
  DAT_00508842 = *(undefined2 *)(DAT_004be3d8 * 0x20 + 0x5081c2);
  DAT_00508844 = *(undefined2 *)(DAT_004be3d8 * 0x20 + 0x5081c4);
  DAT_00508846 = *(undefined2 *)(DAT_004be3d8 * 0x20 + 0x5081c6);
  DAT_00508848 = *(undefined2 *)(DAT_004be3d8 * 0x20 + 0x5081c8);
  DAT_0050884a = *(undefined2 *)(DAT_004be3d8 * 0x20 + 0x5081ca);
  DAT_0050884c = *(undefined2 *)(DAT_004be3d8 * 0x20 + 0x5081cc);
  DAT_0050884e = *(undefined2 *)(DAT_004be3d8 * 0x20 + 0x5081ce);
  DAT_00508850 = *(undefined2 *)(DAT_004be3d8 * 0x20 + 0x5081d0);
  DAT_00508854 = *(undefined4 *)(DAT_004be3d8 * 0x20 + 0x5081d4);
  DAT_00508858 = *(undefined4 *)(DAT_004be3d8 * 0x20 + 0x5081d8);
  DAT_0050885c = *(undefined4 *)(DAT_004be3d8 * 0x20 + 0x5081dc);
  return;
}

