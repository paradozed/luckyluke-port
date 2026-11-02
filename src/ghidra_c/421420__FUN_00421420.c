/* FUN_00421420 @ 00421420 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall FUN_00421420(void *this,int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 local_4c [16];
  int local_c;
  void *local_8;
  
  puVar2 = local_4c;
  for (iVar3 = 0x12; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = 0;
  local_8 = this;
  while (iVar3 = FUN_004222b0((undefined4 *)((int)local_8 + 0x24)), local_c < iVar3) {
    piVar1 = (int *)FUN_00422270((void *)((int)local_8 + 0x24),local_c);
    if (*piVar1 != 0) {
      puVar2 = (undefined4 *)FUN_00422270((void *)((int)local_8 + 0x24),local_c);
      iVar3 = FUN_004214c0((undefined4 *)*puVar2);
      if (iVar3 == param_1) break;
    }
    local_c = local_c + 1;
  }
  FUN_00422270((void *)((int)local_8 + 0x24),local_c);
  local_8 = (void *)0x4214b0;
  __chkesp();
  return;
}

