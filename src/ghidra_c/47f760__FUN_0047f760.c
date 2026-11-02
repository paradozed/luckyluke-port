/* FUN_0047f760 @ 0047f760 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047f760(int param_1,int param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_64 [16];
  undefined2 local_24 [2];
  undefined2 local_20;
  undefined2 local_1c;
  short local_14;
  short local_12;
  short local_10;
  int local_8;
  
  puVar2 = local_64;
  for (iVar1 = 0x18; local_8 = param_4, iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  while (local_8 = local_8 + -1, -1 < local_8) {
    local_14 = *(short *)(param_1 + local_8 * 8) + (short)*param_3;
    local_12 = *(short *)(param_1 + 2 + local_8 * 8) + (short)param_3[1];
    local_10 = *(short *)(param_1 + 4 + local_8 * 8) + (short)param_3[2];
    FUN_004826e0(&local_14,(int *)local_24);
    *(undefined2 *)(param_2 + local_8 * 8) = local_24[0];
    *(undefined2 *)(param_2 + 2 + local_8 * 8) = local_20;
    *(undefined2 *)(param_2 + 4 + local_8 * 8) = local_1c;
  }
  local_8 = 0x47f825;
  __chkesp();
  return;
}

