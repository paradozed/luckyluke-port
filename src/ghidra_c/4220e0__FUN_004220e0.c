/* FUN_004220e0 @ 004220e0 */
/* decompiled from Lucky.exe (Game.run) */


void __fastcall FUN_004220e0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_80 [29];
  undefined4 local_c;
  int local_8;
  
  puVar1 = local_80;
  for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0xcccccccc;
    puVar1 = puVar1 + 1;
  }
  local_c = 0;
  local_8 = param_1;
  puVar1 = (undefined4 *)FUN_00422270((void *)(param_1 + 0x24),0);
  FUN_00422b50((undefined4 *)*puVar1);
  local_8 = 0x422127;
  __chkesp();
  return;
}

