/* FUN_00470010 @ 00470010 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00470010(PVOID param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  PVOID local_c;
  int local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_00458ec0();
  if (param_1 != (PVOID)0x0) {
    local_c = *(PVOID *)((int)param_1 + 8);
    FUN_00439c30(local_c);
    *(undefined4 *)((int)param_1 + 8) = 0;
    FUN_004713e0(DAT_004f1e24,param_1);
    for (local_8 = 0; local_8 < 0xfa; local_8 = local_8 + 1) {
      if (*(PVOID *)(&DAT_004f1e40 + local_8 * 4) == param_1) {
        *(undefined4 *)(&DAT_004f1e40 + local_8 * 4) = 0;
      }
    }
  }
  local_8 = 0x4700b4;
  __chkesp();
  return;
}

