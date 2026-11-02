/* FUN_0041b970 @ 0041b970 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041b970(void *param_1,void *param_2)

{
  undefined2 uVar1;
  short sVar2;
  undefined2 extraout_var;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_80 [16];
  undefined4 *local_40;
  int local_3c;
  short local_38;
  undefined4 local_34;
  int local_30;
  short local_2c;
  ushort *local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined4 *local_c;
  undefined4 local_8;
  uint uVar3;
  
  puVar6 = local_80;
  for (iVar5 = 0x1f; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0xcccccccc;
    puVar6 = puVar6 + 1;
  }
  uVar1 = FUN_004074b0(param_2,3);
  uVar3 = CONCAT22(extraout_var,uVar1);
  sVar2 = FUN_004074b0(param_2,2);
  local_c = (undefined4 *)FUN_00473140(DAT_004f1804,sVar2,uVar3);
  if (local_c == (undefined4 *)0x0) {
    local_c = (undefined4 *)0x0;
  }
  else {
    local_8 = *local_c;
    local_c = local_c + 1;
    local_28 = (ushort *)FUN_004732e0((ushort)local_8);
    local_2c = FUN_004074b0(param_2,6);
    local_30 = FUN_0046e8d0((int)local_2c);
    local_34 = *(undefined4 *)(*(int *)(local_30 + 8) + 4);
    local_38 = FUN_004074b0(param_2,5);
    for (local_3c = 0; local_3c < (int)(uint)*local_28; local_3c = local_3c + 1) {
      uVar4 = FUN_00486410((ushort)local_34,local_38);
      *(undefined4 *)(*(int *)(local_28 + 8) + local_3c * 0x20) = uVar4;
      *(undefined2 *)(*(int *)(local_28 + 8) + 4 + local_3c * 0x20) = 1;
      *(undefined1 *)(*(int *)(local_28 + 8) + 6 + local_3c * 0x20) = 0;
      uVar1 = FUN_004074b0(param_2,7);
      *(undefined2 *)(*(int *)(local_28 + 8) + 8 + local_3c * 0x20) = uVar1;
      *(undefined1 *)(*(int *)(local_28 + 8) + 0x1f + local_3c * 0x20) = 1;
      *(undefined1 *)(*(int *)(local_28 + 8) + 0x1e + local_3c * 0x20) = 0;
      FUN_0047f0f0(*(byte **)(*(int *)(local_28 + 8) + local_3c * 0x20));
      FUN_00485a70(*(byte **)(*(int *)(local_28 + 8) + local_3c * 0x20),local_30,(ushort)local_34,0,
                   0,1,0,(int)local_38);
      *(undefined4 *)(*(int *)(local_28 + 8) + 0xc + local_3c * 0x20) = *local_c;
      *(undefined4 *)(*(int *)(local_28 + 8) + 0x10 + local_3c * 0x20) = local_c[1];
      *(undefined4 *)(*(int *)(local_28 + 8) + 0x14 + local_3c * 0x20) = local_c[2];
      local_c = local_c + 4;
      FUN_0041bd70(*(int *)(*(int *)(local_28 + 8) + local_3c * 0x20),
                   *(undefined4 *)(*(int *)(local_28 + 8) + 0xc + local_3c * 0x20),
                   *(undefined4 *)(*(int *)(local_28 + 8) + 0x10 + local_3c * 0x20),
                   *(undefined4 *)(*(int *)(local_28 + 8) + 0x14 + local_3c * 0x20));
      FUN_0041bcf0(*(int *)(*(int *)(local_28 + 8) + local_3c * 0x20),&local_24);
      if (local_24 < local_20) {
        local_1c = local_24;
      }
      else {
        local_1c = local_20;
      }
      if (local_14 < local_18) {
        local_10 = local_18;
      }
      else {
        local_10 = local_14;
      }
      FUN_0041bcb0(*(int *)(*(int *)(local_28 + 8) + local_3c * 0x20),&local_24);
    }
    local_40 = (undefined4 *)FUN_004714a0(DAT_004f1e24);
    uVar1 = FUN_004074b0(param_2,4);
    *(undefined2 *)(local_40 + 3) = uVar1;
    local_40[1] = FUN_004735e0;
    *(undefined1 *)(local_40 + 4) = 1;
    *local_40 = FUN_00473640;
    *(undefined1 *)((int)local_40 + 0x11) = 1;
    local_40[2] = local_28;
    *(undefined4 **)(&DAT_004f1e40 + (uint)*(ushort *)(local_40 + 3) * 4) = local_40;
    *(undefined1 *)(local_28 + 1) = 1;
    FUN_00412c50(param_1,local_40);
    FUN_00412ee0(param_1,FUN_00473350);
  }
  local_8 = 0x41bca2;
  __chkesp();
  return;
}

