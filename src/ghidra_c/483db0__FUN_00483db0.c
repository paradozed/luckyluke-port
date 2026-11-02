/* FUN_00483db0 @ 00483db0 */
/* decompiled from Lucky.exe (Game.run) */


void __fastcall FUN_00483db0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_5c [16];
  ushort local_1c [4];
  short local_14;
  short local_12;
  short local_10;
  undefined4 local_8;
  
  puVar2 = local_5c;
  for (iVar1 = 0x16; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_00483700(param_3,CONCAT22((short)((uint)param_2 >> 0x10),*(undefined2 *)(param_3 + 0x32)),1,
               local_1c);
  *(int *)(param_3 + 0x14) = (int)local_14;
  *(int *)(param_3 + 0x18) = (int)local_12;
  *(int *)(param_3 + 0x1c) = (int)local_10;
  *(undefined1 *)(param_3 + 0x24) = 0;
  *(undefined1 *)(param_3 + 4) = 0;
  local_8 = 0x483e2a;
  __chkesp();
  return;
}

