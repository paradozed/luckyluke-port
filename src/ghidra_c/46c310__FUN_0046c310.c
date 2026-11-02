/* FUN_0046c310 @ 0046c310 */
/* decompiled from Lucky.exe (Game.run) */


uint __cdecl FUN_0046c310(short param_1,short param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_4c [16];
  short local_c;
  short local_8;
  
  puVar3 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  iVar2 = (int)param_1 - (int)param_2;
  if (iVar2 < 0) {
    local_c = -(param_1 - param_2);
  }
  else {
    iVar2 = (int)param_2;
    local_c = param_1 - param_2;
  }
  iVar2 = CONCAT22((short)((uint)iVar2 >> 0x10),local_c);
  local_8 = local_c;
  if (0x800 < local_c) {
    iVar2 = 0x1000 - local_c;
    local_8 = (short)iVar2;
  }
  if (local_8 < 0x400) {
    uVar1 = CONCAT22((short)((uint)iVar2 >> 0x10),param_2);
  }
  else {
    uVar1 = (int)param_2 + 0x800U & 0x80000fff;
    if ((int)uVar1 < 0) {
      uVar1 = (uVar1 - 1 | 0xfffff000) + 1;
    }
  }
  return uVar1;
}

