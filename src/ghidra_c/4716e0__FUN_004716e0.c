/* FUN_004716e0 @ 004716e0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004716e0(void)

{
  ushort uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_50 [18];
  uint local_8;
  
  puVar3 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = *(ushort *)(DAT_004f1e24 + 1);
  for (local_8 = 0; local_8 < uVar1; local_8 = local_8 + 1) {
    iVar2 = *(int *)(*DAT_004f1e24 + local_8 * 4);
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 4) = 0;
    }
  }
  return;
}

