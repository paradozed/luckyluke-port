/* FUN_0048c510 @ 0048c510 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0048c510(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_54 [17];
  uint *local_10;
  int local_8;
  
  puVar3 = local_54;
  for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_10 = (uint *)(param_2 + (param_1 + -1) * 0x28 + 4);
  uVar1 = param_4 >> 1;
  while (local_8 = param_1 + -1, -1 < local_8) {
    *local_10 = *local_10 & 0xff000000 | uVar1 | uVar1 << 0x10 | uVar1 << 8;
    local_10 = local_10 + -10;
    param_1 = local_8;
  }
  return;
}

