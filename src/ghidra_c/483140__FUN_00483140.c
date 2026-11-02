/* FUN_00483140 @ 00483140 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00483140(undefined4 *param_1)

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
  for (local_28 = 0; local_28 < 3; local_28 = local_28 + 1) {
    for (local_2c = 0; local_2c < 3; local_2c = local_2c + 1) {
      iVar1 = (int)(short)(&DAT_00508840)[local_2c * 3] *
              (int)*(short *)((int)param_1 + local_28 * 2) +
              (int)(short)(&DAT_00508842)[local_2c * 3] *
              (int)*(short *)((int)param_1 + local_28 * 2 + 6) +
              (int)(short)(&DAT_00508844)[local_2c * 3] *
              (int)*(short *)((int)param_1 + local_28 * 2 + 0xc);
      local_30 = (int)(iVar1 + (iVar1 >> 0x1f & 0xfffU)) >> 0xc;
      *(undefined2 *)((int)local_24 + local_28 * 2 + local_2c * 6) = (undefined2)local_30;
    }
  }
  FUN_00482600(param_1,local_24);
  uStack_8 = 0x48324a;
  __chkesp();
  return;
}

