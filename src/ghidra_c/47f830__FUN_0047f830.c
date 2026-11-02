/* FUN_0047f830 @ 0047f830 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047f830(int param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_64 [16];
  undefined2 local_24 [2];
  undefined2 local_20;
  undefined2 local_1c;
  short local_14;
  undefined2 local_12;
  undefined2 local_10;
  int local_8;
  
  puVar2 = local_64;
  for (iVar1 = 0x18; local_8 = param_4, iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  while (local_8 = local_8 + -1, -1 < local_8) {
    local_14 = (short)((int)*(short *)(param_1 + local_8 * 8) * *param_3 >> 0xc);
    local_12 = (undefined2)((int)*(short *)(param_1 + 2 + local_8 * 8) * param_3[1] >> 0xc);
    local_10 = (undefined2)((int)*(short *)(param_1 + 4 + local_8 * 8) * param_3[2] >> 0xc);
    FUN_004826e0(&local_14,(int *)local_24);
    *(undefined2 *)(param_2 + local_8 * 8) = local_24[0];
    *(undefined2 *)(param_2 + 2 + local_8 * 8) = local_20;
    *(undefined2 *)(param_2 + 4 + local_8 * 8) = local_1c;
  }
  local_8 = 0x47f901;
  __chkesp();
  return;
}

