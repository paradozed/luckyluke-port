/* FUN_0041a500 @ 0041a500 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0041a500(void)

{
  int iVar1;
  ushort uVar2;
  undefined4 *puVar3;
  undefined4 local_4c [16];
  int local_c;
  uint local_8;
  
  puVar3 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_c = 0;
  local_8 = local_8 & 0xffff0000;
  while ((local_8 & 0xffff) < DAT_004e89fa + 1) {
    local_c = local_c + (uint)*(ushort *)(DAT_004e89f0 + (local_8 & 0xffff) * 0x20);
    local_8 = CONCAT22(local_8._2_2_,(short)local_8 + 1);
  }
  DAT_004d1eac = FUN_00494c40(local_c << 2,1);
  local_c = 0;
  for (uVar2 = 0; (uint)uVar2 < DAT_004e89fa + 1; uVar2 = uVar2 + 1) {
    if (*(short *)(DAT_004e89f0 + (uint)uVar2 * 0x20) == 0) {
      *(undefined4 *)(DAT_004e89f0 + 0x14 + (uint)uVar2 * 0x20) = 0;
    }
    else {
      *(int *)(DAT_004e89f0 + 0x14 + (uint)uVar2 * 0x20) = DAT_004d1eac + local_c * 4;
    }
    local_c = local_c + (uint)*(ushort *)(DAT_004e89f0 + (uint)uVar2 * 0x20);
    *(undefined2 *)(DAT_004e89f0 + (uint)uVar2 * 0x20) = 0;
    *(undefined1 *)(DAT_004e89f0 + 2 + (uint)uVar2 * 0x20) = 0;
  }
  local_8 = 0x41a670;
  __chkesp();
  return;
}

