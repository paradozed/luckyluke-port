/* FUN_004796e0 @ 004796e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004796e0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  int local_c;
  uint local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_1;
  for (local_8 = 0; local_8 < *(ushort *)(DAT_004e89f0 + local_c * 0x20); local_8 = local_8 + 1) {
    FUN_0047ec50(*(byte **)(*(int *)(DAT_004e89f0 + 0x14 + local_c * 0x20) + local_8 * 4));
  }
  *(undefined4 *)(DAT_004e89f0 + 0x18 + local_c * 0x20) = 0;
  FUN_00478c30(local_c);
  *(undefined1 *)(DAT_004e89f0 + 3 + local_c * 0x20) = 0;
  *(undefined1 *)(DAT_004e89f0 + 2 + local_c * 0x20) = 1;
  local_8 = 0x479795;
  __chkesp();
  return;
}

