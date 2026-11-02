/* FUN_0047f370 @ 0047f370 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047f370(byte *param_1)

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
  FUN_0047ec50(param_1);
  if (*(int *)(param_1 + 0xc4) != 0) {
    *(uint *)(*(int *)(param_1 + 0xc4) + 0x10) = DAT_004e8abc;
  }
  if ((*(int *)(param_1 + 0xcc) != 0) && (*(short *)(*(int *)(param_1 + 0xcc) + 0xc) != 0)) {
    *(uint *)(*(int *)(param_1 + 0xcc) + 8) = DAT_004e8abc >> 5;
    FUN_00485950((int)param_1);
  }
  *param_1 = *param_1 & 0xfd;
  uStack_8 = 0x47f40b;
  __chkesp();
  return;
}

