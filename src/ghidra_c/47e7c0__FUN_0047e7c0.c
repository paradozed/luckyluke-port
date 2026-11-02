/* FUN_0047e7c0 @ 0047e7c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047e7c0(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  uint local_c;
  ushort *local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  IsBadWritePtr(*(LPVOID *)(param_1 + 0x34),1);
  iVar1 = __chkesp();
  if (iVar1 != 0) {
    *(int *)(param_1 + 0x34) = param_1 + *(int *)(param_1 + 0x34);
  }
  local_8 = *(ushort **)(param_1 + 0x34);
  local_c = 0;
  do {
    if (*(int *)(&DAT_00507f40 + (uint)*local_8 * 4) != 0) {
      (**(code **)(&DAT_00507f40 + (uint)*local_8 * 4))
                (local_8 + 8,local_8[1],param_2 + *(int *)(local_8 + 4));
      __chkesp();
    }
    local_c = local_c + local_8[1];
    if (local_c < *(uint *)(param_1 + 0x2c)) {
      *(uint *)(local_8 + 6) = (int)local_8 + *(int *)(local_8 + 2) * (uint)local_8[1] + 0x10;
    }
    else {
      local_8[6] = 0;
      local_8[7] = 0;
    }
    local_8 = *(ushort **)(local_8 + 6);
  } while (local_8 != (ushort *)0x0);
  local_8 = (ushort *)0x47e8c2;
  __chkesp();
  return;
}

