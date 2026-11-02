/* FUN_0047aa50 @ 0047aa50 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047aa50(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  short local_c;
  int local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = **(int **)(param_1 + 8);
  local_c = FUN_0047a5d0(local_8);
  if ((*(char *)(DAT_004e89f0 + 5 + local_c * 0x20) == '\x01') ||
     (*(char *)(param_1 + 0x12) == '\x01')) {
    (**(code **)(*(int *)(local_8 + 0xd0) + 4))(local_8);
    __chkesp();
  }
  local_8 = 0x47aad1;
  __chkesp();
  return;
}

