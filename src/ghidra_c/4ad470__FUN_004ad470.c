/* FUN_004ad470 @ 004ad470 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004ad470(int *param_1,uint param_2,int param_3)

{
  uint uVar1;
  ushort local_18;
  undefined4 uStack_16;
  undefined2 uStack_12;
  undefined4 local_10;
  ushort *local_c;
  undefined *local_8;
  
  local_8 = &DAT_004c7ba8;
  if (param_2 != 0) {
    if ((int)param_2 < 0) {
      param_2 = -param_2;
      local_8 = &DAT_004c7d08;
    }
    uStack_16 = CONCAT22(uStack_16._2_2_,(undefined2)uStack_16);
    if (param_3 == 0) {
      *(undefined2 *)param_1 = 0;
      uStack_16 = CONCAT22(uStack_16._2_2_,(undefined2)uStack_16);
    }
    while (param_2 != 0) {
      local_8 = local_8 + 0x54;
      uVar1 = param_2 & 7;
      param_2 = (int)param_2 >> 3;
      if (uVar1 != 0) {
        local_c = (ushort *)(local_8 + uVar1 * 0xc);
        if (0x7fff < *local_c) {
          local_18 = (ushort)*(undefined4 *)local_c;
          uStack_16._0_2_ = (undefined2)((uint)*(undefined4 *)local_c >> 0x10);
          uStack_16._2_2_ = (undefined2)*(undefined4 *)(local_c + 2);
          uStack_12 = (undefined2)((uint)*(undefined4 *)(local_c + 2) >> 0x10);
          local_10 = *(undefined4 *)(local_c + 4);
          uStack_16 = CONCAT22(uStack_16._2_2_,(undefined2)uStack_16) + -1;
          local_c = &local_18;
        }
        FUN_004ad030(param_1,(int *)local_c);
      }
    }
  }
  return;
}

