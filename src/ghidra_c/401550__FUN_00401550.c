/* FUN_00401550 @ 00401550 */
/* decompiled from Lucky.exe (Game.run) */


void __fastcall FUN_00401550(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  undefined4 local_5c [16];
  int local_1c;
  uint local_18;
  undefined4 local_14;
  undefined1 local_10 [4];
  uint local_c;
  int local_8;
  
  puVar5 = local_5c;
  for (iVar3 = 0x16; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  local_1c = param_1 + 0x198 + *(int *)(param_1 + 0x5c) * 0x8c;
  local_8 = param_1;
  timeGetTime();
  uVar1 = __chkesp();
  *(undefined4 *)(local_8 + 0x140) = uVar1;
  *(undefined4 *)(local_8 + 0x68) = 0;
  *(undefined4 *)(local_8 + 0x60) = 0;
  if (DAT_004bc058 != 0) {
    local_c = local_c & 0xffff0000;
    while( true ) {
      uVar4 = local_c & 0xffff;
      uVar2 = FUN_00425ec0(local_8 + 0xe8);
      if (uVar2 <= uVar4) break;
      local_18 = *(int *)(local_1c + 0x20) - *(int *)(local_8 + 0x68);
      if ((uint)(0x4000 / (ulonglong)*(uint *)(local_1c + 0x30)) < local_18) {
        local_18 = (uint)(0x4000 / (ulonglong)*(uint *)(local_1c + 0x30));
      }
      puVar7 = local_10;
      puVar5 = &local_14;
      uVar6 = 0x4000;
      uVar1 = FUN_00425db0(local_8 + 0xe8);
      AVIStreamRead(*(undefined4 *)(local_8 + 0x54),*(undefined4 *)(local_8 + 0x68),local_18,uVar1,
                    uVar6,puVar5,puVar7);
      *(uint *)(local_8 + 0x68) = *(int *)(local_8 + 0x68) + local_18;
      FUN_00425df0((void *)(local_8 + 0xe8),local_14);
      FUN_00425e30(local_8 + 0xe8);
      local_c = CONCAT22(local_c._2_2_,(short)local_c + 1);
    }
  }
  local_8 = 0x401697;
  __chkesp();
  return;
}

