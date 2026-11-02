/* FUN_004798a0 @ 004798a0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004798a0(int param_1)

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
  if ((*(char *)(DAT_004e89f0 + 2 + param_1 * 0x20) != '\0') ||
     (*(char *)(DAT_004e89f0 + 3 + param_1 * 0x20) != '\0')) {
    if (*(char *)(DAT_004e89f0 + 3 + param_1 * 0x20) == '\x01') {
      FUN_0044bb90(0x4796e0,param_1);
      *(undefined1 *)(DAT_004e89f0 + 3 + local_c * 0x20) = 0;
    }
    for (local_8 = 0; local_8 < *(ushort *)(DAT_004e89f0 + local_c * 0x20); local_8 = local_8 + 1) {
      if (DAT_004be3bc != 0) {
        FUN_0047f190(*(byte **)(*(int *)(DAT_004e89f0 + 0x14 + local_c * 0x20) + local_8 * 4));
      }
    }
    *(undefined1 *)(DAT_004e89f0 + 2 + local_c * 0x20) = 0;
  }
  local_8 = 0x479996;
  __chkesp();
  return;
}

