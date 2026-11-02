/* FUN_004939a0 @ 004939a0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_004939a0(int param_1,short *param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  int local_c;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = 0;
  for (; 0 < param_3; param_3 = param_3 + -1) {
    *param_2 = *param_2 + (short)((uint)(*(short *)(param_1 + (local_c >> 8) * 2) * param_5) >> 8);
    param_2[1] = param_2[1] +
                 (short)((uint)(*(short *)(param_1 + (local_c + param_4 >> 8) * 2) * param_6) >> 8);
    param_2 = param_2 + 2;
    local_c = local_c + param_4 + param_4;
  }
  return;
}

