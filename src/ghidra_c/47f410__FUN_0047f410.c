/* FUN_0047f410 @ 0047f410 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047f410(int param_1,char param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  int local_10;
  uint local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x20);
  if (param_2 == '\0') {
    for (local_8 = 0; local_8 < *(uint *)(param_1 + 0x1c); local_8 = local_8 + 1) {
      *(undefined1 *)(iVar1 + 0x15 + local_8 * 0x28) = 0;
    }
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x10);
  }
  else {
    local_10 = 0;
    for (local_8 = 0; local_8 < *(uint *)(param_1 + 0x1c); local_8 = local_8 + 1) {
      if (*(ushort *)(iVar1 + local_8 * 0x28) < 10) {
        *(undefined1 *)(iVar1 + 0x15 + local_8 * 0x28) = 0;
        local_10 = local_10 + (uint)*(ushort *)(iVar1 + local_8 * 0x28);
      }
      else {
        *(undefined1 *)(iVar1 + 0x15 + local_8 * 0x28) = 1;
      }
    }
    *(int *)(param_1 + 0x14) = local_10;
  }
  return;
}

