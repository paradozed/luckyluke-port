/* FUN_004396f0 @ 004396f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004396f0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_50 [16];
  int local_10;
  undefined4 *local_c;
  undefined4 local_8;
  
  puVar3 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_c = (undefined4 *)FUN_00494840(0x10);
  if (local_c != (undefined4 *)0x0) {
    local_c[3] = 0;
    local_c[1] = param_3;
    *local_c = param_2;
    local_c[2] = param_4;
    uVar1 = FUN_004397c0(param_2);
    uVar1 = uVar1 % (uint)param_1[1];
    if (*(int *)(*param_1 + uVar1 * 4) == 0) {
      *(undefined4 **)(*param_1 + uVar1 * 4) = local_c;
    }
    else {
      for (local_10 = *(int *)(*param_1 + uVar1 * 4); *(int *)(local_10 + 0xc) != 0;
          local_10 = *(int *)(local_10 + 0xc)) {
      }
      *(undefined4 **)(local_10 + 0xc) = local_c;
    }
  }
  local_8 = 0x4397b7;
  __chkesp();
  return;
}

