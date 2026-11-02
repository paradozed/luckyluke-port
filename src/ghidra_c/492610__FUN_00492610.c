/* FUN_00492610 @ 00492610 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00492610(int param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  longlong lVar3;
  undefined4 local_80 [16];
  int local_40;
  int local_3c;
  uint local_38;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  undefined4 uStack_28;
  uint local_24;
  uint local_20;
  int local_1c;
  int local_18;
  uint local_14;
  int local_10;
  undefined1 *local_c;
  char *local_8;
  
  puVar2 = local_80;
  for (iVar1 = 0x1f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = (char *)(param_1 + 0x40);
  local_2c = 0;
  uStack_28 = 0;
  local_34 = 0;
  uStack_30 = 0;
  local_38 = 0;
  while( true ) {
    local_18 = (int)*(char *)((int)local_8 + 1);
    if (local_18 == 7) break;
    local_8 = (char *)((int)local_8 + 0x10);
    local_38 = local_38 + 0x38;
  }
  param_2[1] = local_38;
  *(undefined1 *)((int)param_2 + 9) = 0x10;
  *(undefined1 *)(param_2 + 2) = 2;
  local_8 = (char *)((int)local_8 + 2);
  FUN_00497270((uint *)(param_2 + 5),(uint *)(param_1 + 0x20));
  iVar1 = FUN_004925b0(*(undefined4 *)(param_1 + 0x10));
  param_2[3] = iVar1;
  param_2[4] = (uint)(param_2[3] << 8) / DAT_00508e28;
  iVar1 = FUN_00494840(local_38);
  *param_2 = iVar1;
  if (*param_2 != 0) {
    local_8 = (char *)(param_1 + 0x40);
    local_c = (undefined1 *)*param_2;
    while( true ) {
      local_14 = (int)*local_8 & 0xf;
      local_10 = (int)*local_8 >> 4;
      local_18 = (int)local_8[1];
      local_8 = local_8 + 2;
      if (local_18 == 7) break;
      for (local_1c = 0; local_1c < 0x1c; local_1c = local_1c + 2) {
        local_20 = (uint)*local_8;
        local_8 = local_8 + 1;
        local_24 = (local_20 & 0xf) << 0xc;
        if ((local_24 & 0x8000) != 0) {
          local_24 = local_24 | 0xffff0000;
        }
        local_3c = (int)local_24 >> (sbyte)local_14;
        *(double *)(&DAT_00508e40 + local_1c * 8) = (double)local_3c;
        local_24 = (local_20 & 0xf0) << 8;
        if ((local_24 & 0x8000) != 0) {
          local_24 = local_24 | 0xffff0000;
        }
        local_40 = (int)local_24 >> (sbyte)local_14;
        *(double *)(&DAT_00508e48 + local_1c * 8) = (double)local_40;
      }
      for (local_1c = 0; local_1c < 0x1c; local_1c = local_1c + 1) {
        *(double *)(&DAT_00508e40 + local_1c * 8) =
             (double)CONCAT44(uStack_30,local_34) * *(double *)(&DAT_004c6db0 + local_10 * 0x10) +
             (double)CONCAT44(uStack_28,local_2c) * *(double *)(&DAT_004c6da8 + local_10 * 0x10) +
             *(double *)(&DAT_00508e40 + local_1c * 8);
        local_34 = local_2c;
        uStack_30 = uStack_28;
        local_2c = *(undefined4 *)(&DAT_00508e40 + local_1c * 8);
        uStack_28 = *(undefined4 *)(&DAT_00508e44 + local_1c * 8);
        lVar3 = __ftol();
        local_20 = (uint)lVar3;
        *local_c = (char)lVar3;
        local_c[1] = (char)((ulonglong)lVar3 >> 8);
        local_c = local_c + 2;
      }
    }
    local_18 = 7;
  }
  local_8 = (char *)0x4928eb;
  __chkesp();
  return;
}

