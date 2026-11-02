/* FUN_00460ba0 @ 00460ba0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00460ba0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (0xf < *(ushort *)(*(int *)(**(int **)(&DAT_004f2580 + (uint)DAT_004f2596 * 4) + 0xc4) + 0x32))
  {
    DAT_004e861f = 1;
  }
  return;
}

