/* FUN_00483700 @ 00483700 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00483700(int param_1,uint param_2,uint param_3,ushort *param_4)

{
  int iVar1;
  ushort *puVar2;
  undefined4 *puVar3;
  undefined4 local_54 [16];
  ushort *local_14;
  ushort local_10;
  ushort *local_c;
  uint local_8;
  
  puVar3 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_14 = param_4;
  local_c = (ushort *)(*(int *)(*(int *)(param_1 + 8) + 0xc + (param_2 & 0xffff) * 4) + 2);
  for (local_8 = 0; local_8 <= (param_3 & 0xffff); local_8 = local_8 + 1) {
    _memset(local_14,0,0x14);
    local_10 = *local_c;
    puVar2 = local_c + 1;
    if (((int)(short)local_10 & 0x8000U) != 0) {
      *local_14 = *local_14 | 1;
      if ((local_10 & 1) != 0) {
        local_14[1] = *puVar2;
        puVar2 = local_c + 2;
      }
      local_c = puVar2;
      if ((local_10 & 2) != 0) {
        local_14[2] = *local_c;
        local_c = local_c + 1;
      }
      puVar2 = local_c;
      if ((local_10 & 4) != 0) {
        local_14[3] = *local_c;
        puVar2 = local_c + 1;
      }
    }
    local_c = puVar2;
    if ((local_10 & 0x4000) != 0) {
      *local_14 = *local_14 | 2;
      if ((local_10 & 8) != 0) {
        local_14[4] = *local_c;
        local_c = local_c + 1;
      }
      if ((local_10 & 0x10) != 0) {
        local_14[5] = *local_c;
        local_c = local_c + 1;
      }
      if ((local_10 & 0x20) != 0) {
        local_14[6] = *local_c;
        local_c = local_c + 1;
      }
    }
    if ((local_10 & 0x2000) != 0) {
      *local_14 = *local_14 | 4;
      if ((local_10 & 0x40) != 0) {
        local_14[7] = *local_c;
        local_c = local_c + 1;
      }
      if ((local_10 & 0x80) != 0) {
        local_14[8] = *local_c;
        local_c = local_c + 1;
      }
      if ((local_10 & 0x100) != 0) {
        local_14[9] = *local_c;
        local_c = local_c + 1;
      }
    }
  }
  local_8 = 0x48391a;
  __chkesp();
  return;
}

