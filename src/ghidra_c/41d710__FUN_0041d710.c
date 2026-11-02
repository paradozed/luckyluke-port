/* FUN_0041d710 @ 0041d710 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041d710(ushort param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  size_t local_c;
  ushort *local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (uint)param_1 * 4 + 8;
  local_8 = (ushort *)FUN_00439a90(DAT_004e85ec,local_c);
  _memset(local_8,0,local_c);
  *local_8 = param_1;
  local_8 = (ushort *)0x41d77b;
  __chkesp();
  return;
}

