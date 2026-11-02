/* FUN_004712c0 @ 004712c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004712c0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  uint local_c;
  uint local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    local_8 = local_8 & 0xffff0000;
    while ((local_8 & 0xffff) < (uint)*(ushort *)(param_1 + 1)) {
      FUN_00439c30(*(PVOID *)(*param_1 + (local_8 & 0xffff) * 4));
      local_c = local_c & 0xffff0000;
      while ((local_c & 0xffff) < 0xfa) {
        if (*(int *)(&DAT_004f1e40 + (local_c & 0xffff) * 4) ==
            *(int *)(*param_1 + (local_8 & 0xffff) * 4)) {
          *(undefined4 *)(&DAT_004f1e40 + (local_c & 0xffff) * 4) = 0;
          break;
        }
        local_c = CONCAT22(local_c._2_2_,(short)local_c + 1);
      }
      local_8 = CONCAT22(local_8._2_2_,(short)local_8 + 1);
    }
    FUN_00439c30((PVOID)*param_1);
    *param_1 = 0;
    *(undefined2 *)(param_1 + 1) = 0;
    *(undefined2 *)((int)param_1 + 6) = 0;
  }
  local_8 = 0x4713cd;
  __chkesp();
  return;
}

