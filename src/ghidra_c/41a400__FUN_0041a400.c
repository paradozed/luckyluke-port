/* FUN_0041a400 @ 0041a400 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0041a400(void)

{
  ushort uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [17];
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  for (uVar1 = 0; (uint)uVar1 < DAT_004e89fa + 1; uVar1 = uVar1 + 1) {
    *(undefined2 *)(DAT_004e89f0 + (uint)uVar1 * 0x20) = 0;
    *(undefined4 *)(DAT_004e89f0 + 0x14 + (uint)uVar1 * 0x20) = 0;
    *(undefined1 *)(DAT_004e89f0 + 2 + (uint)uVar1 * 0x20) = 0;
    *(undefined1 *)(DAT_004e89f0 + 3 + (uint)uVar1 * 0x20) = 0;
    *(undefined1 *)(DAT_004e89f0 + 4 + (uint)uVar1 * 0x20) = 0;
    *(undefined1 *)(DAT_004e89f0 + 5 + (uint)uVar1 * 0x20) = 0;
    *(undefined1 *)(DAT_004e89f0 + 6 + (uint)uVar1 * 0x20) = 0;
  }
  DAT_004e9380 = 1;
  return;
}

