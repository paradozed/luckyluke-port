/* FUN_00487d50 @ 00487d50 */
/* decompiled from Lucky.exe (Game.run) */


int __cdecl FUN_00487d50(int param_1,byte param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_4c [17];
  int local_8;
  
  puVar3 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = **(int **)(param_1 + 0xd8);
  for (bVar1 = 0; (local_8 != 0 && (bVar1 < param_2)); bVar1 = bVar1 + 1) {
    local_8 = *(int *)(*(int *)(local_8 + 0xdc) + 0x3c);
  }
  return local_8;
}

