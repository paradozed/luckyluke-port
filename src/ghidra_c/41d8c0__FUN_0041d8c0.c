/* FUN_0041d8c0 @ 0041d8c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041d8c0(int param_1)

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
  FUN_00458ec0();
  local_8 = *(ushort **)(param_1 + 8);
  if (local_8 != (ushort *)0xdddddddd) {
    local_c = local_c & 0xffff0000;
    while ((local_c & 0xffff) < (uint)*local_8) {
      if (*(int *)(local_8 + (local_c & 0xffff) * 2 + 2) != 0) {
        FUN_0047f190(*(byte **)(local_8 + (local_c & 0xffff) * 2 + 2));
        FUN_00439c30(*(PVOID *)(local_8 + (local_c & 0xffff) * 2 + 2));
        (local_8 + (local_c & 0xffff) * 2 + 2)[0] = 0;
        (local_8 + (local_c & 0xffff) * 2 + 2)[1] = 0;
      }
      local_c = CONCAT22(local_c._2_2_,(short)local_c + 1);
    }
    if (local_8 != (ushort *)0x0) {
      FUN_00439c30(local_8);
    }
  }
  local_8 = (ushort *)0x41d9a3;
  __chkesp();
  return;
}

