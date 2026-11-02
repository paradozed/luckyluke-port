/* FUN_004713e0 @ 004713e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004713e0(int *param_1,PVOID param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  undefined4 local_c;
  uint local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = local_8 & 0xffff0000;
  while ((local_8 & 0xffff) < (uint)*(ushort *)(param_1 + 1)) {
    if (*(PVOID *)(*param_1 + (local_8 & 0xffff) * 4) == param_2) {
      *(short *)(param_1 + 1) = (short)param_1[1] + -1;
      local_c = *(undefined4 *)(*param_1 + (uint)*(ushort *)(param_1 + 1) * 4);
      *(undefined4 *)(*param_1 + (local_8 & 0xffff) * 4) = local_c;
      FUN_00439c30(param_2);
    }
    local_8 = CONCAT22(local_8._2_2_,(short)local_8 + 1);
  }
  local_8 = 0x47148d;
  __chkesp();
  return;
}

