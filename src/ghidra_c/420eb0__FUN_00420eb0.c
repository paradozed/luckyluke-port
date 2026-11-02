/* FUN_00420eb0 @ 00420eb0 */
/* decompiled from Lucky.exe (Game.run) */


void __fastcall FUN_00420eb0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  void *local_c;
  int local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = param_1;
  if (*(int *)(param_1 + 0x18) != 0) {
    local_c = *(void **)(param_1 + 0x18);
    FUN_004966d0(local_c);
  }
  *(undefined4 *)(local_8 + 0x18) = 0;
  local_8 = 0x420f02;
  __chkesp();
  return;
}

