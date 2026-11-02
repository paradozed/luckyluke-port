/* FUN_00439850 @ 00439850 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00439850(int *param_1,int param_2,int *param_3,int *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  uint local_10;
  int *local_c;
  int *local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (int *)0x0;
  local_10 = FUN_004397c0(param_2);
  local_10 = local_10 % (uint)param_1[1];
  if (*(int *)(*param_1 + local_10 * 4) != 0) {
    for (local_8 = *(int **)(*param_1 + local_10 * 4); local_8 != (int *)0x0;
        local_8 = (int *)local_8[3]) {
      if (param_2 == *local_8) {
        *param_3 = local_8[1];
        *param_4 = local_8[2];
        if (local_c == (int *)0x0) {
          *(int *)(*param_1 + local_10 * 4) = local_8[3];
        }
        else {
          local_c[3] = local_8[3];
        }
        FUN_00495280(local_8);
        break;
      }
      local_c = local_8;
    }
  }
  local_8 = (int *)0x439923;
  __chkesp();
  return;
}

