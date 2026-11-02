/* FUN_00485950 @ 00485950 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00485950(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  int local_10;
  int local_c;
  int local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = *(int *)(param_1 + 0xcc);
  local_c = *(int *)(param_1 + 0x4c) - *(int *)(local_8 + 0x20);
  local_10 = *(int *)(param_1 + 0x50) - *(int *)(local_8 + 0x24);
  if ((local_c != 0) || (local_10 != 0)) {
    *(undefined4 *)(local_8 + 0x20) = *(undefined4 *)(param_1 + 0x4c);
    *(undefined4 *)(local_8 + 0x24) = *(undefined4 *)(param_1 + 0x50);
    FUN_004853e0(*(int *)(param_1 + 0xcc) + 0x2c,local_c,local_10);
  }
  local_8 = 0x4859ee;
  __chkesp();
  return;
}

