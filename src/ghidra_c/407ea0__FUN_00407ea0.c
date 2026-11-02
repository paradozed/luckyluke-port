/* FUN_00407ea0 @ 00407ea0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00407ea0(int param_1,int param_2,int param_3)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_64 [16];
  uint local_24;
  uint local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  int local_c;
  int local_8;
  
  puVar3 = local_64;
  for (iVar2 = 0x18; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_1c = *(int *)(param_1 + 0x90);
  local_18 = *(undefined4 *)(param_1 + 0x94);
  local_14 = *(int *)(param_1 + 0x98);
  local_8 = param_2 - local_1c;
  local_c = param_3 - local_14;
  if ((local_8 != 0) || (local_c != 0)) {
    sVar1 = FUN_004081b0(param_1);
    local_20 = (int)sVar1 & 0xfff;
    sVar1 = FUN_004836a0(-local_c,local_8);
    local_24 = sVar1 + -0x400 + local_20 & 0xfff;
  }
  local_8 = 0x407f84;
  __chkesp();
  return;
}

