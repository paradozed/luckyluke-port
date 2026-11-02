/* FUN_00401f80 @ 00401f80 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall FUN_00401f80(void *this,undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined4 local_74 [16];
  int local_34;
  uint local_30;
  int *local_2c;
  uint local_28;
  undefined4 local_24;
  undefined1 local_20 [4];
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  uint local_c;
  void *local_8;
  
  puVar3 = local_74;
  for (iVar2 = 0x1c; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_c = local_c & 0xffff0000;
  local_30 = local_30 & 0xffffff00;
  local_2c = (int *)((int)this + 0x198);
  local_8 = this;
  timeGetTime();
  uVar1 = __chkesp();
  *(undefined4 *)((int)local_8 + 0x144) = uVar1;
  *(int *)((int)local_8 + 0x144) = *(int *)((int)local_8 + 0x144) - *(int *)((int)local_8 + 0x140);
  uVar1 = AVIStreamTimeToSample
                    (*(undefined4 *)((int)local_8 + 0x50),*(undefined4 *)((int)local_8 + 0x144));
  *(undefined4 *)((int)local_8 + 0x60) = uVar1;
  local_10 = CONCAT22(local_10._2_2_,*(undefined2 *)((int)local_8 + 0xffc));
  while ((local_10 & 0xffff) != 0) {
    local_34 = *local_2c;
    if (local_34 == 0x73646976) {
      if (*(int *)((int)local_8 + 100) == *(int *)((int)local_8 + 0x60)) {
        if ((local_30 & 0xff) == 0) {
          *param_2 = 0;
        }
      }
      else if ((local_30 & 0xff) == 0) {
        local_18 = AVIStreamGetFrame(*(undefined4 *)((int)local_8 + (local_c & 0xffff) * 4 + 0x148),
                                     *(undefined4 *)((int)local_8 + 0x60));
        local_1c = local_18 + 0x28;
        *param_2 = local_1c;
        *(undefined4 *)((int)local_8 + 100) = *(undefined4 *)((int)local_8 + 0x60);
        local_30 = CONCAT31(local_30._1_3_,1);
      }
    }
    else if ((local_34 == 0x73647561) && (DAT_004bc058 != 0)) {
      for (local_14 = FUN_00425ec0((int)local_8 + 0xe8); local_14 != 0; local_14 = local_14 + -1) {
        local_28 = local_2c[8] - *(int *)((int)local_8 + 0x68);
        if ((uint)(0x4000 / (ulonglong)(uint)local_2c[0xc]) < local_28) {
          local_28 = (uint)(0x4000 / (ulonglong)(uint)local_2c[0xc]);
        }
        puVar5 = local_20;
        puVar3 = &local_24;
        uVar4 = 0x4000;
        uVar1 = FUN_00425db0((int)local_8 + 0xe8);
        AVIStreamRead(*(undefined4 *)((int)local_8 + 0x54),*(undefined4 *)((int)local_8 + 0x68),
                      local_28,uVar1,uVar4,puVar3,puVar5);
        *(uint *)((int)local_8 + 0x68) = *(int *)((int)local_8 + 0x68) + local_28;
        FUN_00425df0((void *)((int)local_8 + 0xe8),local_24);
        FUN_00425e30((int)local_8 + 0xe8);
      }
    }
    local_2c = local_2c + 0x23;
    local_c = CONCAT22(local_c._2_2_,(short)local_c + 1);
    local_10 = CONCAT22(local_10._2_2_,(short)local_10 + -1);
  }
  local_10 = 0x4021ca;
  __chkesp();
  return;
}

