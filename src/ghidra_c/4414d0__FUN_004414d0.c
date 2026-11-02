/* FUN_004414d0 @ 004414d0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004414d0(LPCSTR param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  int local_c;
  uint *local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = (uint *)FUN_00497d00(param_1,"rb");
  if (local_8 != (uint *)0x0) {
    FUN_004988b0(local_8,0,2);
    local_c = FUN_00498dc0(local_8);
    FUN_004988b0(local_8,0,0);
    FUN_00497b30((int *)local_8);
  }
  local_8 = (uint *)0x441553;
  __chkesp();
  return;
}

