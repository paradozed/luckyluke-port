/* FUN_00493f60 @ 00493f60 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00493f60(void)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 local_50 [17];
  int local_c;
  uint local_8;
  
  puVar3 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_c = 0;
  for (local_8 = 0; local_8 < 0x40; local_8 = local_8 + 1) {
    *(int *)(&DAT_00508a20 + local_c * 4) =
         (int)((uint)*(ushort *)(&DAT_004c6e04 + local_8 * 2) * 3) >> 3;
    uVar2 = (uint)*(ushort *)(&DAT_004c6e06 + local_8 * 2) -
            (uint)*(ushort *)(&DAT_004c6e04 + local_8 * 2);
    *(uint *)(&DAT_00508a20 + (local_c + 1) * 4) =
         ((uint)*(ushort *)(&DAT_004c6e04 + local_8 * 2) + (uVar2 >> 2)) * 3 >> 3;
    *(uint *)(&DAT_00508a20 + (local_c + 2) * 4) =
         ((uint)*(ushort *)(&DAT_004c6e04 + local_8 * 2) + (uVar2 >> 1)) * 3 >> 3;
    *(uint *)(&DAT_00508a20 + (local_c + 3) * 4) =
         ((uint)*(ushort *)(&DAT_004c6e04 + local_8 * 2) + (uVar2 >> 2) * 3) * 3 >> 3;
    local_c = local_c + 4;
  }
  return;
}

