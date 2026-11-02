/* FUN_00452d60 @ 00452d60 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00452d60(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_5c [16];
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar2 = local_5c;
  for (iVar1 = 0x16; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  DAT_004e8698 = *(undefined4 *)(DAT_004f2458 + 0x10);
  *(uint *)(DAT_004f2458 + 0x10) = *(uint *)(DAT_004f2458 + 0x10) | 0x3e01;
  DAT_004e8690 = 1;
  DAT_004f2b6c = DAT_004f2b6c + DAT_004f2bec;
  DAT_004f2b7c = DAT_004f2b7c + DAT_004f2bec;
  DAT_004f2bec = 0;
  if (param_1 < 0) {
    local_c = -param_1;
  }
  else {
    local_c = param_1;
  }
  if (param_2 < 0) {
    local_10 = -param_2;
  }
  else {
    local_10 = param_2;
  }
  if (local_10 < local_c) {
    if (param_1 < 0) {
      local_14 = -param_1;
    }
    else {
      local_14 = param_1;
    }
    local_18 = local_14;
  }
  else {
    if (param_2 < 0) {
      local_1c = -param_2;
    }
    else {
      local_1c = param_2;
    }
    local_18 = local_1c;
  }
  if (DAT_004bc4e8 * 2 < local_18) {
    local_8 = local_18 / 0x15e;
  }
  else {
    local_8 = local_18 / 0xfa;
  }
  FUN_00454d50(DAT_004f2bbc,_DAT_004f2c34,DAT_004f2be8,DAT_004f2bf4,200 - local_8);
  (*(code *)PTR_FUN_004bd5d8)();
  __chkesp();
  local_8 = 0x452eb9;
  __chkesp();
  return;
}

