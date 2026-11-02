/* FUN_004341f0 @ 004341f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004341f0(int param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_54 [17];
  int local_10;
  int local_c;
  int local_8;
  
  puVar3 = local_54;
  for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = 0;
  local_c = 0;
  local_10 = 0;
  bVar1 = false;
  while (*(char *)(param_1 + local_8) != '\0') {
    if ((*(char *)(param_1 + local_8) != ' ') || (bVar1)) {
      if (*(char *)(param_1 + local_8) == '\"') {
        bVar1 = (bool)(bVar1 ^ 1);
      }
      if (param_3 == local_10) {
        *(undefined1 *)(param_2 + local_c) = *(undefined1 *)(param_1 + local_8);
        local_c = local_c + 1;
      }
      local_8 = local_8 + 1;
    }
    else {
      local_8 = local_8 + 1;
      local_10 = local_10 + 1;
    }
  }
  *(undefined1 *)(param_2 + local_c) = 0;
  return;
}

