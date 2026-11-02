/* FUN_004425a0 @ 004425a0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004425a0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_58 [17];
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar2 = local_58;
  for (iVar1 = 0x15; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_10 = 0x29b8;
  local_14 = 0;
  for (local_c = 0; local_c < DAT_004e8550; local_c = local_c + 1) {
    for (local_8 = 0; local_8 < DAT_004e854c; local_8 = local_8 + 1) {
      *(undefined2 *)(*(int *)(DAT_004f58a4 + 0x20) + (local_10 + local_8) * 2) =
           *(undefined2 *)((&DAT_004e8544)[param_1] + local_14 * 2);
      local_14 = local_14 + 1;
    }
    local_10 = local_10 + 0x100;
  }
  (*DAT_004e8a24)(8,*(undefined4 *)(DAT_004f58a4 + 0x20));
  __chkesp();
  local_8 = 0x442668;
  __chkesp();
  return;
}

