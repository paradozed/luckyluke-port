/* FUN_004851b0 @ 004851b0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004851b0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (*(int *)(param_1 + 0x20) != 0) {
    FUN_00485230(param_1,1,0,0,0);
  }
  if (*(int *)(param_1 + 0xc4) != 0) {
    FUN_00439c30(*(PVOID *)(param_1 + 0xc4));
  }
  *(undefined4 *)(param_1 + 0xc4) = 0;
  uStack_8 = 0x48521d;
  __chkesp();
  return;
}

