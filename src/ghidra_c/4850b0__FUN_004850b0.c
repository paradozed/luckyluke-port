/* FUN_004850b0 @ 004850b0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_004850b0(int param_1,int param_2,short param_3,undefined2 param_4,undefined1 param_5,
            undefined1 param_6)

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
  if (((*(int *)(param_1 + 0xc4) == 0) || (*(int *)(*(int *)(param_1 + 0xc4) + 8) != param_2)) ||
     (*(short *)(*(int *)(param_1 + 0xc4) + 0x32) == param_3)) {
    if (*(int *)(param_1 + 0xc4) == 0) {
      FUN_00484e30(param_1,param_2,param_3,param_4,param_5,param_6);
    }
    else {
      *(int *)(*(int *)(param_1 + 0xc4) + 8) = param_2;
      *(short *)(*(int *)(param_1 + 0xc4) + 0x32) = param_3;
      *(undefined1 *)(*(int *)(param_1 + 0xc4) + 4) = 1;
      FUN_00484ff0(param_1,param_4,param_5,param_6);
      if (*(uint *)(param_1 + 0x1c) < (uint)*(ushort *)(param_2 + 2)) {
        *(undefined2 *)(param_2 + 2) = *(undefined2 *)(param_1 + 0x1c);
      }
    }
  }
  uStack_8 = 0x4851a6;
  __chkesp();
  return;
}

