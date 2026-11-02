/* FUN_00446430 @ 00446430 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00446430(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_54 [16];
  PVOID local_14;
  PVOID local_10;
  PVOID local_c;
  PVOID local_8;
  
  puVar2 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 != 0) {
    local_8 = *(PVOID *)(param_1 + 0xc);
    while (local_8 != (PVOID)0x0) {
      local_10 = *(PVOID *)((int)local_8 + 0x34);
      while (local_10 != (PVOID)0x0) {
        FUN_00439c30(*(PVOID *)((int)local_10 + 0x1c));
        FUN_00439c30(*(PVOID *)((int)local_10 + 0x20));
        local_14 = *(PVOID *)((int)local_10 + 0x18);
        FUN_00439c30(local_10);
        local_10 = local_14;
      }
      local_c = *(PVOID *)((int)local_8 + 0x2c);
      FUN_00439c30(local_8);
      local_8 = local_c;
    }
    DAT_004f2e04 = 0;
  }
  local_8 = (PVOID)0x4464e0;
  __chkesp();
  return;
}

