/* FUN_00443e30 @ 00443e30 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00443e30(short *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_54 [16];
  int local_14;
  int local_10;
  int local_c;
  short *local_8;
  
  puVar2 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (*(int *)(param_2 + 8) == 0) {
    *(short **)(param_2 + 8) = param_1;
    *(short **)(param_2 + 0xc) = param_1;
    param_1[6] = 0;
    param_1[7] = 0;
    param_1[8] = 0;
    param_1[9] = 0;
    *param_1 = 0;
    param_1[1] = 0;
    *(int *)(param_1 + 4) = param_2;
  }
  else {
    local_10 = 0;
    local_14 = 0;
    for (local_c = *(int *)(param_2 + 8); local_c != 0; local_c = *(int *)(local_c + 0xc)) {
      local_10 = 0;
      local_8 = *(short **)(param_2 + 8);
      while( true ) {
        if (local_8 == (short *)0x0) break;
        *param_1 = (short)local_10;
        param_1[1] = (short)local_14;
        iVar1 = FUN_00444060(param_1,param_2);
        if (iVar1 != 0) {
          *(short **)(*(int *)(param_2 + 0xc) + 0xc) = param_1;
          param_1[6] = 0;
          param_1[7] = 0;
          *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 0xc);
          *(short **)(param_2 + 0xc) = param_1;
          *(int *)(param_1 + 4) = param_2;
          goto LAB_00444048;
        }
        local_10 = (int)*local_8 + (int)local_8[2];
        local_8 = *(short **)(local_8 + 6);
      }
      *param_1 = (short)local_10;
      param_1[1] = (short)local_14;
      iVar1 = FUN_00444060(param_1,param_2);
      if (iVar1 != 0) {
        *(short **)(*(int *)(param_2 + 0xc) + 0xc) = param_1;
        param_1[6] = 0;
        param_1[7] = 0;
        *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 0xc);
        *(short **)(param_2 + 0xc) = param_1;
        *(int *)(param_1 + 4) = param_2;
        goto LAB_00444048;
      }
      local_14 = (int)*(short *)(local_c + 2) + (int)*(short *)(local_c + 6);
    }
    *param_1 = (short)local_10;
    param_1[1] = (short)local_14;
    iVar1 = FUN_00444060(param_1,param_2);
    if (iVar1 != 0) {
      *(short **)(*(int *)(param_2 + 0xc) + 0xc) = param_1;
      param_1[6] = 0;
      param_1[7] = 0;
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 0xc);
      *(short **)(param_2 + 0xc) = param_1;
      *(int *)(param_1 + 4) = param_2;
    }
  }
LAB_00444048:
  local_8 = (short *)0x444055;
  __chkesp();
  return;
}

