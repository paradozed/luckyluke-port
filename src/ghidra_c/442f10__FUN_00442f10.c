/* FUN_00442f10 @ 00442f10 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00442f10(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  int local_10;
  int local_c;
  char *local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = (char *)(param_1 + 4);
  local_c = 0;
  local_10 = 0;
  while (*local_8 != '\0') {
    if (*local_8 == '=') {
      local_c = local_c + 1;
      local_8 = local_8 + 1;
    }
    else {
      if (local_c == param_2) {
        *(char *)(param_1 + local_10 + 0x104) = *local_8;
        local_10 = local_10 + 1;
      }
      local_8 = local_8 + 1;
    }
  }
  *(undefined1 *)(param_1 + local_10 + 0x104) = 0;
  return;
}

