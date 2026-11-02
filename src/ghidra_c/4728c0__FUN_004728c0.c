/* FUN_004728c0 @ 004728c0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004728c0(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  int local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  DAT_004f182e = '\0';
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    if (*(short *)(&DAT_004be190 + local_8 * 0xc) == 0) {
      *(undefined4 *)(&DAT_004f1820 + local_8 * 4) = 0;
      (&DAT_004f182c)[local_8] = 0;
    }
    else {
      uVar1 = FUN_00494c40((uint)*(ushort *)(&DAT_004be190 + local_8 * 0xc) << 2,1);
      *(undefined4 *)(&DAT_004f1820 + local_8 * 4) = uVar1;
      *(undefined2 *)(&DAT_004f1828 + local_8 * 2) = 0;
      **(undefined2 **)(&DAT_004f1820 + local_8 * 4) = 0;
      *(undefined2 *)(*(int *)(&DAT_004f1820 + local_8 * 4) + 2) = 1;
      (&DAT_004f182c)[local_8] = 1;
      DAT_004f182e = DAT_004f182e + '\x01';
    }
  }
  for (local_8 = 0; local_8 < 0x37; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_004f182f + local_8 * 4) = *(undefined4 *)(&DAT_004f22c0 + local_8 * 4);
  }
  _DAT_004f190b = DAT_004f23b4;
  _DAT_004f190d = DAT_004f23b6;
  DAT_004e8974 = 1;
  local_8 = 0x4729f4;
  __chkesp();
  return;
}

