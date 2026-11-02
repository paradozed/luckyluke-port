/* FUN_0042c280 @ 0042c280 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0042c280(int param_1,int param_2,byte *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_78 [16];
  uint local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c [2];
  short local_24;
  short local_22;
  short local_1c;
  short local_1a;
  short local_14;
  short local_12;
  short local_c;
  short local_a;
  undefined4 uStack_8;
  
  puVar2 = local_78;
  for (iVar1 = 0x1d; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_38 = (uint)(DAT_004be3c8 << 3) / 0x280;
  param_1 = param_1 + 3;
  while (*param_3 != 0) {
    if (*param_3 == 0x20) {
      param_1 = param_1 + local_38;
      param_3 = param_3 + 1;
    }
    else if (*(int *)(&DAT_004f6140 + (uint)*param_3 * 4) == 0) {
      param_3 = param_3 + 1;
    }
    else {
      FUN_00497690(local_2c,*(undefined4 **)(&DAT_004f6544 + (uint)*param_3 * 0xc),0x28);
      local_30 = *(undefined4 *)(&DAT_004f6544 + (uint)*param_3 * 0xc);
      *(undefined4 **)(&DAT_004f6544 + (uint)*param_3 * 0xc) = local_2c;
      local_12 = (short)(((longlong)
                          (int)(((longlong)(int)local_12 * (longlong)DAT_004be3cc & 0xffffffffU) /
                               0x1e0) * (longlong)DAT_004bcfe4 & 0xffffffffU) / 100);
      local_34 = param_2 - local_12;
      local_24 = local_24 + (short)param_1;
      local_22 = local_22 + (short)local_34;
      local_1c = (short)(((longlong)
                          (int)(((longlong)(int)local_1c * (longlong)DAT_004be3c8 & 0xffffffffU) /
                               0x280) * (longlong)DAT_004bcfe0 & 0xffffffffU) / 100) +
                 (short)param_1;
      local_1a = local_1a + (short)local_34;
      local_14 = local_14 + (short)param_1;
      local_12 = local_12 + (short)local_34;
      local_c = (short)(((longlong)
                         (int)(((longlong)(int)local_c * (longlong)DAT_004be3c8 & 0xffffffffU) /
                              0x280) * (longlong)DAT_004bcfe0 & 0xffffffffU) / 100) + (short)param_1
      ;
      local_a = (short)(((longlong)
                         (int)(((longlong)(int)local_a * (longlong)DAT_004be3cc & 0xffffffffU) /
                              0x1e0) * (longlong)DAT_004bcfe4 & 0xffffffffU) / 100) +
                (short)local_34;
      (*DAT_004e8a30)();
      __chkesp();
      FUN_004442e0((int *)(&DAT_004f6540 + (uint)*param_3 * 0xc),0x11,0x11,0x11,0x11);
      *(undefined4 *)(&DAT_004f6544 + (uint)*param_3 * 0xc) = local_30;
      param_1 = param_1 + ((int)local_1c - (int)local_24);
      param_3 = param_3 + 1;
    }
  }
  uStack_8 = 0x42c4c1;
  __chkesp();
  return;
}

