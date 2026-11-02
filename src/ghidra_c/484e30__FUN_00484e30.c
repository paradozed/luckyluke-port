/* FUN_00484e30 @ 00484e30 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_00484e30(int param_1,int param_2,undefined2 param_3,undefined2 param_4,undefined1 param_5,
            undefined1 param_6)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_68 [16];
  int local_28;
  SIZE_T local_24;
  ushort local_20 [4];
  short local_18;
  short local_16;
  short local_14;
  ushort *local_c;
  int *local_8;
  
  puVar2 = local_68;
  for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (*(int *)(param_1 + 0xc4) == 0) {
    local_24 = *(int *)(param_1 + 0x1c) * 0x28 + 0x58;
    local_28 = FUN_00439af0(local_24);
    *(int *)(param_1 + 0xc4) = local_28;
    local_8 = *(int **)(param_1 + 0xc4);
    local_8[0x10] = 0;
    local_8[0x11] = 0;
    local_8[0x12] = local_28 + 0x50;
    local_24 = *(int *)(param_1 + 0x1c) * 0x14 + 0x54;
    local_8[0x13] = local_28 + local_24;
  }
  else {
    local_8 = *(int **)(param_1 + 0xc4);
  }
  if (*(uint *)(param_1 + 0x1c) < (uint)*(ushort *)(param_2 + 2)) {
    *(undefined2 *)(param_2 + 2) = *(undefined2 *)(param_1 + 0x1c);
  }
  *local_8 = param_1;
  *(undefined1 *)(local_8 + 1) = 0;
  local_8[2] = param_2;
  local_8[3] = 0;
  FUN_00483700((int)local_8,CONCAT22((short)((uint)param_2 >> 0x10),param_3),1,local_20);
  local_c = local_20;
  local_8[5] = (int)local_18;
  local_8[6] = (int)local_16;
  local_8[7] = (int)local_14;
  *(undefined2 *)((int)local_8 + 0x32) = param_3;
  *(undefined1 *)(local_8 + 9) = 0;
  *(undefined2 *)((int)local_8 + 0x2a) = 0;
  *(undefined2 *)(local_8 + 0xb) = 0;
  *(undefined2 *)((int)local_8 + 0x2e) = 0;
  FUN_00484db0(param_1);
  FUN_00485080(param_1,0);
  FUN_00484ff0(param_1,param_4,param_5,param_6);
  FUN_00485040(param_1,0,0);
  FUN_00483e30(local_8);
  local_8 = (int *)0x484fec;
  __chkesp();
  return;
}

