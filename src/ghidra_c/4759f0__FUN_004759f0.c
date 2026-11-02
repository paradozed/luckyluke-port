/* FUN_004759f0 @ 004759f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004759f0(PVOID param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  int local_c;
  PVOID local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_00458ec0();
  local_8 = *(PVOID *)((int)param_1 + 8);
  if (local_8 != (PVOID)0xdddddddd) {
    FUN_00439c30(*(PVOID *)((int)local_8 + 4));
    FUN_004713e0(DAT_004f1e24,param_1);
    if (local_8 != (PVOID)0x0) {
      FUN_00439c30(local_8);
    }
    for (local_c = 0; local_c < 0xfa; local_c = local_c + 1) {
      if (*(PVOID *)(&DAT_004f1e40 + local_c * 4) == param_1) {
        *(undefined4 *)(&DAT_004f1e40 + local_c * 4) = 0;
      }
    }
  }
  local_8 = (PVOID)0x475aa9;
  __chkesp();
  return;
}

