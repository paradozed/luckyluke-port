/* FUN_004869e0 @ 004869e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004869e0(int param_1,int param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_90 [16];
  undefined2 local_50 [16];
  undefined4 local_30 [8];
  int local_10;
  int local_c;
  uint local_8;
  
  puVar2 = local_90;
  for (iVar1 = 0x23; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_10 = 0;
  local_c = *(int *)(param_1 + 0x20);
  puVar2 = (undefined4 *)(param_1 + 0x5c);
  puVar3 = local_30;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  for (local_8 = 0; local_8 < *(uint *)(param_2 + 0x2c); local_8 = local_8 + 1) {
    local_10 = local_c + *(int *)(*(int *)(param_2 + 0x30) + local_8 * 4) * 0x28;
    if (((*(byte *)(local_10 + 0x14) & 1) == 1) &&
       (((*(short *)(local_10 + 0x16) != 0 || (*(short *)(local_10 + 0x18) != 0)) ||
        (*(short *)(local_10 + 0x1a) != 0)))) {
      FUN_0047c630(local_50,*(short *)(local_10 + 0x16),*(short *)(local_10 + 0x18),
                   *(short *)(local_10 + 0x1a));
      FUN_00482930(local_30,(int)local_50);
    }
  }
  FUN_00487e60(param_3,(undefined2 *)local_30);
  local_8 = 0x486ae7;
  __chkesp();
  return;
}

