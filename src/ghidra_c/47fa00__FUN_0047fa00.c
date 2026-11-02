/* FUN_0047fa00 @ 0047fa00 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047fa00(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_58 [16];
  int local_18 [2];
  int local_10;
  int local_c;
  int local_8;
  
  puVar3 = local_58;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_c = DAT_005081a8;
  local_10 = DAT_005081a4;
  while (local_8 = param_3 + -1, -1 < local_8) {
    uVar1 = FUN_00482e60((short *)(param_1 + local_8 * 8),(short *)(param_2 + local_8 * 8),local_18)
    ;
    *(undefined4 *)(param_2 + 4 + local_8 * 8) = uVar1;
    if (*(int *)(param_2 + 4 + local_8 * 8) < local_c) {
      local_c = *(int *)(param_2 + 4 + local_8 * 8);
    }
    param_3 = local_8;
    if (local_10 < *(int *)(param_2 + 4 + local_8 * 8)) {
      local_10 = *(int *)(param_2 + 4 + local_8 * 8);
    }
  }
  DAT_005081a8 = local_c;
  DAT_005081a4 = local_10;
  local_8 = 0x47fac9;
  __chkesp();
  return;
}

