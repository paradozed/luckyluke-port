/* FUN_00465810 @ 00465810 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00465810(LPCSTR param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  uint *local_c;
  int local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (uint *)FUN_00497d00(param_1,"rb");
  if (local_c != (uint *)0x0) {
    FUN_004988b0(local_c,0,2);
    local_8 = FUN_00498dc0(local_c);
    FUN_00497b30((int *)local_c);
  }
  local_8 = 0x465881;
  __chkesp();
  return;
}

