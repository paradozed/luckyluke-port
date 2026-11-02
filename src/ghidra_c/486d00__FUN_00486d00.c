/* FUN_00486d00 @ 00486d00 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00486d00(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  int local_c;
  int local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = **(int **)(param_2 + 0xd8);
  for (local_8 = local_c; (local_8 != 0 && (local_8 != param_1));
      local_8 = *(int *)(*(int *)(local_8 + 0xdc) + 0x3c)) {
    local_c = local_8;
  }
  if (local_8 == param_1) {
    FUN_00439c30(*(PVOID *)(*(int *)(param_1 + 0xdc) + 0x38));
    *(int *)(*(int *)(param_2 + 0xd8) + 4) =
         *(int *)(*(int *)(param_2 + 0xd8) + 4) - *(int *)(param_1 + 0x10);
    *(int *)(*(int *)(param_2 + 0xd8) + 8) =
         *(int *)(*(int *)(param_2 + 0xd8) + 8) - *(int *)(param_1 + 0x2c);
    if (*(int *)(param_1 + 0xd8) == 0) {
      *(undefined1 *)(param_1 + 1) = 1;
    }
    else {
      *(undefined1 *)(param_1 + 1) = 2;
    }
    *(undefined ***)(param_1 + 0xd0) = &PTR_FUN_004c6480 + (uint)*(byte *)(param_1 + 1) * 5;
    if ((**(int **)(param_2 + 0xd8) == param_1) && (*(int *)(*(int *)(param_1 + 0xdc) + 0x3c) == 0))
    {
      FUN_00439c30(*(PVOID *)(param_2 + 0xd8));
      *(undefined4 *)(param_2 + 0xd8) = 0;
      if (*(int *)(param_2 + 0xdc) == 0) {
        *(undefined1 *)(param_2 + 1) = 1;
      }
      else {
        *(undefined1 *)(param_2 + 1) = 4;
      }
      *(undefined ***)(param_2 + 0xd0) = &PTR_FUN_004c6480 + (uint)*(byte *)(param_2 + 1) * 5;
    }
    else if (*(int *)(*(int *)(param_1 + 0xdc) + 0x3c) == 0) {
      *(undefined4 *)(*(int *)(local_c + 0xdc) + 0x3c) =
           *(undefined4 *)(*(int *)(local_8 + 0xdc) + 0x3c);
    }
    else {
      **(undefined4 **)(param_2 + 0xd8) = *(undefined4 *)(*(int *)(param_1 + 0xdc) + 0x3c);
    }
    FUN_00439c30(*(PVOID *)(param_1 + 0xdc));
    *(undefined4 *)(param_1 + 0xdc) = 0;
  }
  FUN_00487e60((undefined2 *)(param_1 + 0x5c),(undefined2 *)(param_1 + 0x7c));
  local_8 = 0x486edc;
  __chkesp();
  return;
}

