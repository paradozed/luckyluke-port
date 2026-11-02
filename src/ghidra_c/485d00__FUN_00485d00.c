/* FUN_00485d00 @ 00485d00 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00485d00(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = *(undefined4 *)(param_1 + 0xcc);
  if (*(int *)(param_1 + 0xcc) != 0) {
    FUN_00485a00(param_1);
    FUN_00439c30(*(PVOID *)(param_1 + 0xcc));
  }
  *(undefined4 *)(param_1 + 0xcc) = 0;
  local_8 = 0x485d68;
  __chkesp();
  return;
}

