/* FUN_004437e0 @ 004437e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004437e0(int param_1)

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
  if (param_1 == -1) {
    for (local_8 = DAT_004e8564; local_8 != 0; local_8 = *(int *)(local_8 + 0x34)) {
      if (*(int *)(local_8 + 0x28) != 0) {
        (**(code **)(local_8 + 0x28))();
        __chkesp();
      }
    }
  }
  else {
    for (local_8 = DAT_004e8564; local_8 != 0; local_8 = *(int *)(local_8 + 0x34)) {
      if ((*(int *)(local_8 + 0x28) != 0) && (*(int *)(local_8 + 0x20) == param_1)) {
        (**(code **)(local_8 + 0x28))();
        __chkesp();
      }
    }
  }
  local_8 = 0x44387f;
  __chkesp();
  return;
}

