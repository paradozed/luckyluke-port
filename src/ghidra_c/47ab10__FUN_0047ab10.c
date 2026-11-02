/* FUN_0047ab10 @ 0047ab10 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047ab10(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  int *local_c;
  int local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = **(int **)(param_1 + 8);
  local_c = *(int **)(local_8 + 0xdc);
  if ((((local_c == (int *)0x0) || (*local_c == 0)) || (*local_c == -0x22222223)) ||
     ((*(byte *)*local_c & 2) == 0)) {
    (**(code **)(*(int *)(local_8 + 0xd0) + 4))(local_8);
    __chkesp();
  }
  local_8 = 0x47ab93;
  __chkesp();
  return;
}

