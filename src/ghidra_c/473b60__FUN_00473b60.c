/* FUN_00473b60 @ 00473b60 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00473b60(PVOID param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_00458ec0();
  FUN_004713e0(DAT_004f1e24,param_1);
  for (local_8 = 0; local_8 < 0xfa; local_8 = local_8 + 1) {
    if (*(PVOID *)(&DAT_004f1e40 + local_8 * 4) == param_1) {
      *(undefined4 *)(&DAT_004f1e40 + local_8 * 4) = 0;
    }
  }
  local_8 = 0x473bdf;
  __chkesp();
  return;
}

