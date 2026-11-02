/* FUN_00493c40 @ 00493c40 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_00493c40(int param_1,short *param_2,int param_3,int param_4,int param_5,int param_6)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_4c [16];
  int local_c;
  
  puVar3 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_c = 0;
  for (; 0 < param_3; param_3 = param_3 + -1) {
    sVar1 = *(short *)(param_1 + (local_c + 0x7f >> 8) * 2);
    *param_2 = *param_2 + (short)((uint)(sVar1 * param_5) >> 8);
    param_2[1] = param_2[1] + (short)((uint)(sVar1 * param_6) >> 8);
    param_2 = param_2 + 2;
    local_c = local_c + param_4;
  }
  return;
}

