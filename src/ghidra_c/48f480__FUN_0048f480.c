/* FUN_0048f480 @ 0048f480 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0048f480(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_60 [16];
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined2 *local_10;
  undefined2 *local_c;
  undefined2 *local_8;
  
  puVar2 = local_60;
  for (iVar1 = 0x17; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = *(undefined2 **)(param_1 + param_2 * 0xc);
  local_c = *(undefined2 **)(param_1 + 4 + param_2 * 0xc);
  local_10 = *(undefined2 **)(param_1 + 8 + param_2 * 0xc);
  iVar1 = FUN_00482db0(**(undefined4 **)(param_1 + param_2 * 0xc),
                       **(undefined4 **)(param_1 + 4 + param_2 * 0xc),
                       **(undefined4 **)(param_1 + 8 + param_2 * 0xc));
  if (-1 < iVar1) {
    local_14 = param_3 + param_2 * 0x14;
    *(undefined2 *)(local_14 + 8) = *local_8;
    *(undefined2 *)(local_14 + 10) = local_8[1];
    *(undefined2 *)(local_14 + 0xc) = *local_c;
    *(undefined2 *)(local_14 + 0xe) = local_c[1];
    *(undefined2 *)(local_14 + 0x10) = *local_10;
    *(undefined2 *)(local_14 + 0x12) = local_10[1];
    local_20 = *(int *)(local_8 + 2) + param_4;
    local_1c = *(int *)(local_c + 2) + param_4;
    local_18 = *(int *)(local_10 + 2) + param_4;
    FUN_0047d910(local_14,local_20,local_1c,local_18,0,0);
  }
  local_8 = (undefined2 *)0x48f5b2;
  __chkesp();
  return;
}

