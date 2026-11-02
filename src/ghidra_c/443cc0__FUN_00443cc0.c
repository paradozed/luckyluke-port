/* FUN_00443cc0 @ 00443cc0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00443cc0(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_60 [16];
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  short *local_8;
  
  puVar2 = local_60;
  for (iVar1 = 0x17; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = 1;
  if (((DAT_004e8578 != 0) || (iVar1 = FUN_00443bc0(), iVar1 != 0)) &&
     (local_8 = (short *)FUN_00439af0(0x14), local_8 != (short *)0x0)) {
    local_8[2] = (short)param_2;
    local_8[3] = (short)param_3;
    local_10 = DAT_004e8578;
    while (local_c != 0) {
      while ((local_10 != 0 && (iVar1 = FUN_00443e30(local_8,local_10), iVar1 == 0))) {
        local_10 = *(int *)(local_10 + 0x10);
      }
      if (local_10 == 0) {
        iVar1 = FUN_00443bc0();
        if (iVar1 == 0) {
          FUN_00439c30(local_8);
          goto LAB_00443e10;
        }
        local_10 = DAT_004e857c;
      }
      else {
        local_c = 0;
      }
    }
    local_1c = (int)*local_8;
    local_20 = (int)local_8[1];
    for (local_18 = 0; local_18 < param_3; local_18 = local_18 + 1) {
      for (local_14 = 0; local_14 < param_2; local_14 = local_14 + 1) {
        *(undefined2 *)
         (*(int *)(local_10 + 4) + ((local_20 + local_18) * 0x100 + local_1c + local_14) * 2) =
             *(undefined2 *)(param_1 + (local_18 * param_2 + local_14) * 2);
      }
    }
  }
LAB_00443e10:
  local_8 = (short *)0x443e1d;
  __chkesp();
  return;
}

