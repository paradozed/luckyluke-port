/* FUN_00421370 @ 00421370 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall FUN_00421370(void *this,int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 local_50 [16];
  int local_10;
  int local_c;
  void *local_8;
  
  puVar2 = local_50;
  for (iVar3 = 0x13; iVar3 != 0; iVar3 = iVar3 + -1) {
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
  iVar3 = FUN_004222b0((undefined4 *)((int)local_8 + 0x24));
  if (local_c == iVar3) {
    local_10 = 0;
  }
  else {
    local_10 = local_c + 1;
  }
  local_8 = (void *)0x421414;
  __chkesp();
  return;
}

