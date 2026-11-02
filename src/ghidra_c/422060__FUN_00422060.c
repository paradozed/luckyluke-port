/* FUN_00422060 @ 00422060 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall FUN_00422060(void *this,uint param_1,short param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_4c [16];
  int local_c;
  void *local_8;
  
  puVar1 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0xcccccccc;
    puVar1 = puVar1 + 1;
  }
  local_8 = this;
  local_c = FUN_00421370(this,param_1 & 0xffff);
  if (local_c == 0) {
    FUN_00477a60();
  }
  puVar1 = (undefined4 *)FUN_00422270((void *)((int)local_8 + 0x24),local_c + -1);
  FUN_004257b0((void *)*puVar1,param_2);
  local_8 = (void *)0x4220cf;
  __chkesp();
  return;
}

