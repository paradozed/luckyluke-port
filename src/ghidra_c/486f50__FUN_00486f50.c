/* FUN_00486f50 @ 00486f50 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00486f50(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar3 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_00439af0(0xc);
  *(undefined4 *)(param_1 + 0xd8) = uVar1;
  *(undefined4 *)(*(int *)(param_1 + 0xd8) + 4) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(*(int *)(param_1 + 0xd8) + 8) = *(undefined4 *)(param_1 + 0x2c);
  **(undefined4 **)(param_1 + 0xd8) = 0;
  if (*(int *)(param_1 + 0xdc) == 0) {
    *(undefined1 *)(param_1 + 1) = 2;
  }
  else {
    *(undefined1 *)(param_1 + 1) = 3;
  }
  *(undefined ***)(param_1 + 0xd0) = &PTR_FUN_004c6480 + (uint)*(byte *)(param_1 + 1) * 5;
  uStack_8 = 0x486ff1;
  __chkesp();
  return;
}

