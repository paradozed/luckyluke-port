/* FUN_004442e0 @ 004442e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_004442e0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_60 [16];
  char local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar4 = local_60;
  for (iVar2 = 0x17; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  if (**(int **)(*param_1 + 8) == 0) {
    FUN_00444550(*(int **)(*param_1 + 8),DAT_004e8574 + DAT_004e8570 * 4);
    uVar1 = *(undefined4 *)(*(int *)(*param_1 + 8) + 4);
    (*DAT_004e8a24)(CONCAT31((int3)((uint)uVar1 >> 8),
                             *(undefined1 *)(DAT_004e8574 + DAT_004e8570 * 4)),uVar1);
    __chkesp();
    DAT_004e8570 = DAT_004e8570 + 1;
    if (DAT_004e8570 == DAT_004e856c) {
      DAT_004e8570 = 0;
    }
  }
  iVar3 = (int)*(short *)*param_1;
  iVar2 = (int)*(short *)(*param_1 + 2);
  local_10 = (int)*(short *)(*param_1 + 4);
  local_14 = (int)*(short *)(*param_1 + 6);
  local_18 = iVar3 + local_10;
  local_1c = iVar2 + local_14;
  if (0xff < local_18) {
    local_18 = 0xff;
  }
  if (0xff < local_1c) {
    local_1c = 0xff;
  }
  local_20 = (char)param_1[2];
  local_8._0_1_ = (undefined1)*(short *)*param_1;
  local_c._0_1_ = (undefined1)*(short *)(*param_1 + 2);
  local_c = iVar2;
  local_8 = iVar3;
  if (local_20 == '\x03') {
    *(undefined2 *)(param_1[1] + 0x16) = *(undefined2 *)**(undefined4 **)(*param_1 + 8);
    *(undefined1 *)(param_1[1] + 0xc) = (undefined1)local_8;
    *(undefined1 *)(param_1[1] + 0xd) = (undefined1)local_c;
    *(undefined1 *)(param_1[1] + 0x14) = (undefined1)local_18;
    *(undefined1 *)(param_1[1] + 0x15) = (undefined1)local_c;
    *(undefined1 *)(param_1[1] + 0x1c) = (undefined1)local_8;
    *(undefined1 *)(param_1[1] + 0x1d) = (undefined1)local_1c;
    *(undefined1 *)(param_1[1] + 0x24) = (undefined1)local_18;
    *(undefined1 *)(param_1[1] + 0x25) = (undefined1)local_1c;
    (*DAT_004e8a54)(param_1[1],param_2,param_3,param_4,param_5);
    __chkesp();
    iVar2 = local_c;
  }
  else if (local_20 == '\a') {
    *(undefined2 *)(param_1[1] + 0x1a) = *(undefined2 *)**(undefined4 **)(*param_1 + 8);
    *(undefined1 *)(param_1[1] + 0xc) = (undefined1)local_8;
    *(undefined1 *)(param_1[1] + 0xd) = (undefined1)local_c;
    *(undefined1 *)(param_1[1] + 0x18) = (undefined1)local_18;
    *(undefined1 *)(param_1[1] + 0x19) = (undefined1)local_c;
    *(undefined1 *)(param_1[1] + 0x24) = (undefined1)local_8;
    *(undefined1 *)(param_1[1] + 0x25) = (undefined1)local_1c;
    *(undefined1 *)(param_1[1] + 0x30) = (undefined1)local_18;
    *(undefined1 *)(param_1[1] + 0x31) = (undefined1)local_1c;
    (*DAT_004e8a5c)(param_1[1],param_2,param_3,param_4,param_5);
    __chkesp();
    iVar2 = local_c;
  }
  local_c = iVar2;
  local_8 = 0x44454b;
  __chkesp();
  return;
}

