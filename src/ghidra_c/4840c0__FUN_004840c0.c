/* FUN_004840c0 @ 004840c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004840c0(int param_1,int param_2)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  ushort *local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  puVar1 = *(undefined2 **)(*(int *)(param_1 + 8) + 0xc + param_2 * 4);
  if (*(undefined2 **)(param_1 + 0x44) != puVar1) {
    *(undefined2 **)(param_1 + 0x44) = puVar1;
    **(undefined2 **)(param_1 + 0x4c) = *puVar1;
    local_8 = puVar1 + 1;
    FUN_00483920(*(short *)(*(int *)(param_1 + 8) + 2),local_8,
                 (ushort *)(*(int *)(param_1 + 0x4c) + 4));
  }
  local_8 = (ushort *)0x484144;
  __chkesp();
  return;
}

