/* FUN_00478510 @ 00478510 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00478510(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  uint local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)(DAT_004e89f0 + 3 + param_1 * 0x20) = 1;
  for (local_8 = 0; local_8 < *(ushort *)(DAT_004e89f0 + param_1 * 0x20); local_8 = local_8 + 1) {
    FUN_0047ea50(*(int *)(*(int *)(DAT_004e89f0 + 0x14 + param_1 * 0x20) + local_8 * 4));
  }
  local_8 = 0x478590;
  __chkesp();
  return;
}

