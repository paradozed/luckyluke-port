/* FUN_004121d0 @ 004121d0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004121d0(void *param_1,void *param_2)

{
  ushort uVar1;
  undefined2 uVar2;
  short sVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_7c [16];
  undefined4 *local_3c;
  int local_38;
  short local_34;
  undefined4 local_30;
  int local_2c;
  short local_28;
  ushort *local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar6 = local_7c;
  for (iVar5 = 0x1e; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0xcccccccc;
    puVar6 = puVar6 + 1;
  }
  uVar1 = FUN_004074b0(param_2,5);
  local_8 = (int)(short)uVar1;
  local_24 = (ushort *)FUN_004732e0(uVar1);
  local_28 = FUN_004074b0(param_2,2);
  local_2c = FUN_0046e8d0((int)local_28);
  local_30 = *(undefined4 *)(*(int *)(local_2c + 8) + 4);
  local_34 = FUN_004074b0(param_2,3);
  for (local_38 = 0; local_38 < (int)(uint)*local_24; local_38 = local_38 + 1) {
    uVar4 = FUN_00486410((ushort)local_30,local_34);
    *(undefined4 *)(*(int *)(local_24 + 8) + local_38 * 0x20) = uVar4;
    *(undefined2 *)(*(int *)(local_24 + 8) + 4 + local_38 * 0x20) = 1;
    *(undefined1 *)(*(int *)(local_24 + 8) + 6 + local_38 * 0x20) = 0;
    uVar2 = FUN_004074b0(param_2,4);
    *(undefined2 *)(*(int *)(local_24 + 8) + 8 + local_38 * 0x20) = uVar2;
    *(undefined1 *)(*(int *)(local_24 + 8) + 0x1f + local_38 * 0x20) = 1;
    *(undefined1 *)(*(int *)(local_24 + 8) + 0x1e + local_38 * 0x20) = 0;
    FUN_0047f0f0(*(byte **)(*(int *)(local_24 + 8) + local_38 * 0x20));
    FUN_00485a70(*(byte **)(*(int *)(local_24 + 8) + local_38 * 0x20),local_2c,(ushort)local_30,0,0,
                 1,0,(int)local_34);
    sVar3 = FUN_004074b0(param_2,7);
    *(int *)(*(int *)(local_24 + 8) + 0xc + local_38 * 0x20) = sVar3 * 100;
    sVar3 = FUN_004074b0(param_2,8);
    *(int *)(*(int *)(local_24 + 8) + 0x10 + local_38 * 0x20) = sVar3 * 100;
    sVar3 = FUN_004074b0(param_2,9);
    *(int *)(*(int *)(local_24 + 8) + 0x14 + local_38 * 0x20) = sVar3 * 100;
    *(short *)(*(int *)(local_24 + 8) + 0x1c + local_38 * 0x20) =
         (short)(0x168 / (ulonglong)(longlong)(int)(uint)*local_24);
    FUN_00411c90(*(int *)(*(int *)(local_24 + 8) + local_38 * 0x20),
                 *(undefined4 *)(*(int *)(local_24 + 8) + 0xc + local_38 * 0x20),
                 *(undefined4 *)(*(int *)(local_24 + 8) + 0x10 + local_38 * 0x20),
                 *(undefined4 *)(*(int *)(local_24 + 8) + 0x14 + local_38 * 0x20));
    FUN_00411200(*(int *)(*(int *)(local_24 + 8) + local_38 * 0x20),&local_20);
    if (local_20 < local_1c) {
      local_18 = local_20;
    }
    else {
      local_18 = local_1c;
    }
    if (local_10 < local_14) {
      local_c = local_14;
    }
    else {
      local_c = local_10;
    }
    FUN_00411000(*(int *)(*(int *)(local_24 + 8) + local_38 * 0x20),&local_20);
  }
  local_3c = (undefined4 *)FUN_004714a0(DAT_004f1e24);
  uVar2 = FUN_004074b0(param_2,0xb);
  *(undefined2 *)(local_3c + 3) = uVar2;
  local_3c[1] = FUN_004735e0;
  *(undefined1 *)(local_3c + 4) = 1;
  *local_3c = FUN_00473660;
  *(undefined1 *)((int)local_3c + 0x11) = 1;
  local_3c[2] = local_24;
  *(undefined4 **)(&DAT_004f1e40 + (uint)*(ushort *)(local_3c + 3) * 4) = local_3c;
  *(undefined1 *)(local_24 + 1) = 1;
  local_24[2] = 0;
  local_24[3] = 0;
  local_24[4] = 0;
  local_24[6] = 0;
  uVar1 = FUN_004074b0(param_2,6);
  local_24[5] = uVar1;
  uVar1 = FUN_004074b0(param_2,10);
  local_24[7] = uVar1;
  FUN_00412c50(param_1,local_3c);
  FUN_00412ee0(param_1,FUN_00473350);
  local_8 = 0x412535;
  __chkesp();
  return;
}

