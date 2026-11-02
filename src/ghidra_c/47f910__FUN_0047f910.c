/* FUN_0047f910 @ 0047f910 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047f910(int param_1,int param_2,int *param_3,undefined4 *param_4,int param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_64 [16];
  short local_24;
  short local_22;
  short local_20;
  undefined2 local_1c [2];
  undefined2 local_18;
  undefined2 local_14;
  int local_8;
  
  puVar2 = local_64;
  for (iVar1 = 0x18; local_8 = param_5, iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  while (local_8 = local_8 + -1, -1 < local_8) {
    local_24 = (short)((int)*(short *)(param_1 + local_8 * 8) * *param_3 >> 0xc) + (short)*param_4;
    local_22 = (short)((int)*(short *)(param_1 + 2 + local_8 * 8) * param_3[1] >> 0xc) +
               (short)param_4[1];
    local_20 = (short)((int)*(short *)(param_1 + 4 + local_8 * 8) * param_3[2] >> 0xc) +
               (short)param_4[2];
    FUN_004826e0(&local_24,(int *)local_1c);
    *(undefined2 *)(param_2 + local_8 * 8) = local_1c[0];
    *(undefined2 *)(param_2 + 2 + local_8 * 8) = local_18;
    *(undefined2 *)(param_2 + 4 + local_8 * 8) = local_14;
  }
  local_8 = 0x47f9f2;
  __chkesp();
  return;
}

