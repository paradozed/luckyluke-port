/* FUN_00446540 @ 00446540 */
/* decompiled from Lucky.exe (Game.run) */


int __cdecl FUN_00446540(int param_1,byte param_2)

{
  int iVar1;
  byte bVar2;
  undefined4 *puVar3;
  undefined4 local_4c [17];
  int local_8;
  
  puVar3 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (param_1 == 0) {
    local_8 = 0;
  }
  else if (param_2 < *(byte *)(param_1 + 0x12)) {
    local_8 = *(int *)(param_1 + 0xc);
    for (bVar2 = 0; bVar2 < param_2; bVar2 = bVar2 + 1) {
      local_8 = *(int *)(local_8 + 0x2c);
    }
  }
  else {
    local_8 = 0;
  }
  return local_8;
}

