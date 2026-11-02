/* FUN_00456f30 @ 00456f30 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00456f30(ushort param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_58 [16];
  uint local_18;
  uint local_14;
  undefined2 *local_10;
  int *local_c;
  undefined4 *local_8;
  
  puVar3 = local_58;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_10 = (undefined2 *)(DAT_004e8820 + *(int *)(DAT_004e8820 + 4 + (uint)param_1 * 4));
  local_8 = (undefined4 *)FUN_00439a90(DAT_004e85ec,0x14);
  _memset(local_8,0,0x14);
  *local_8 = FUN_00456ef0;
  local_8[1] = local_10 + 4;
  local_8[2] = (int)local_10 + *(int *)(local_10 + 2) + 8;
  *(undefined2 *)(local_8 + 3) = local_10[1];
  *(undefined2 *)((int)local_8 + 0xe) = *local_10;
  *(ushort *)(local_8 + 4) = param_1;
  local_c = (int *)local_8[1];
  IsBadWritePtr((LPVOID)local_c[1],1);
  iVar2 = __chkesp();
  if (iVar2 != 0) {
    local_14 = local_14 & 0xffff0000;
    while ((local_14 & 0xffff) < (uint)*(ushort *)(local_8 + 3)) {
      local_c[1] = local_c[1] + local_8[2];
      local_c[2] = local_c[2] + local_8[2];
      piVar1 = local_c + 4;
      local_c = local_c + 5;
      local_18 = CONCAT22(local_18._2_2_,(short)*piVar1);
      while ((local_18 & 0xffff) != 0) {
        *local_c = *local_c + local_8[1];
        local_c = local_c + 1;
        local_18 = CONCAT22(local_18._2_2_,(short)local_18 + -1);
      }
      local_14 = CONCAT22(local_14._2_2_,(short)local_14 + 1);
    }
  }
  local_8 = (undefined4 *)0x4570a9;
  __chkesp();
  return;
}

