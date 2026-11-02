/* FUN_00482930 @ 00482930 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00482930(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_70 [16];
  int local_30;
  short local_2c;
  short local_28;
  undefined4 local_24 [7];
  undefined4 uStack_8;
  
  puVar2 = local_70;
  for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_004823a0(param_1);
  for (local_28 = 0; local_28 < 3; local_28 = local_28 + 1) {
    for (local_2c = 0; local_2c < 3; local_2c = local_2c + 1) {
      iVar1 = (int)*(short *)((int)param_1 + local_2c * 6) * (int)*(short *)(param_2 + local_28 * 2)
              + (int)*(short *)((int)param_1 + local_2c * 6 + 2) *
                (int)*(short *)(param_2 + 6 + local_28 * 2) +
              (int)*(short *)((int)param_1 + local_2c * 6 + 4) *
              (int)*(short *)(param_2 + 0xc + local_28 * 2);
      local_30 = (int)(iVar1 + (iVar1 >> 0x1f & 0xfffU)) >> 0xc;
      *(undefined2 *)((int)local_24 + local_28 * 2 + local_2c * 6) = (undefined2)local_30;
    }
  }
  FUN_00482600(param_1,local_24);
  uStack_8 = 0x482a48;
  __chkesp();
  return;
}

