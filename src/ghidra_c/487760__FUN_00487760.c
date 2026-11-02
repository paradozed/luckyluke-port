/* FUN_00487760 @ 00487760 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00487760(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((param_1 != -0x22222223) && (**(int **)(param_1 + 0xd8) != -0x22222223)) {
    for (local_8 = **(int **)(param_1 + 0xd8); local_8 != 0;
        local_8 = *(int *)(*(int *)(local_8 + 0xdc) + 0x3c)) {
      if (local_8 != -0x22222223) {
        (**(code **)(*(int *)(local_8 + 0xd0) + 4))(local_8);
        __chkesp();
      }
    }
  }
  local_8 = 0x4877f1;
  __chkesp();
  return;
}

