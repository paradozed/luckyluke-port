/* FUN_00489d00 @ 00489d00 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00489d00(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_68 [16];
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined2 *local_14;
  undefined2 *local_10;
  undefined2 *local_c;
  undefined2 *local_8;
  
  puVar2 = local_68;
  for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = *(undefined2 **)(param_1 + param_2 * 0x10);
  local_c = *(undefined2 **)(param_1 + 4 + param_2 * 0x10);
  local_10 = *(undefined2 **)(param_1 + 8 + param_2 * 0x10);
  local_14 = *(undefined2 **)(param_1 + 0xc + param_2 * 0x10);
  iVar1 = FUN_00482db0(**(undefined4 **)(param_1 + param_2 * 0x10),
                       **(undefined4 **)(param_1 + 4 + param_2 * 0x10),
                       **(undefined4 **)(param_1 + 8 + param_2 * 0x10));
  if (-1 < iVar1) {
    local_18 = param_3 + param_2 * 0x34;
    *(undefined2 *)(local_18 + 8) = *local_8;
    *(undefined2 *)(local_18 + 10) = local_8[1];
    *(undefined2 *)(local_18 + 0x14) = *local_c;
    *(undefined2 *)(local_18 + 0x16) = local_c[1];
    *(undefined2 *)(local_18 + 0x20) = *local_14;
    *(undefined2 *)(local_18 + 0x22) = local_14[1];
    *(undefined2 *)(local_18 + 0x2c) = *local_10;
    *(undefined2 *)(local_18 + 0x2e) = local_10[1];
    local_28 = *(int *)(local_8 + 2) + param_4;
    local_24 = *(int *)(local_c + 2) + param_4;
    local_20 = *(int *)(local_10 + 2) + param_4;
    local_1c = *(int *)(local_14 + 2) + param_4;
    FUN_0047d910(local_18,local_28,local_24,local_20,local_1c,7);
  }
  local_8 = (undefined2 *)0x489e6b;
  __chkesp();
  return;
}

