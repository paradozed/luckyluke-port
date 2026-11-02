/* FUN_0048d670 @ 0048d670 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0048d670(int param_1,int param_2,int param_3,int param_4)

{
  ushort uVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_6c [16];
  char local_2c [4];
  char local_28 [4];
  int local_24;
  int local_20;
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  iVar4 = 0x1a;
  puVar5 = local_6c;
  while( true ) {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  local_8 = *(int *)(param_1 + 0xcc);
  uVar1 = *(ushort *)(local_8 + 0xc);
  local_10 = CONCAT22(local_10._2_2_,uVar1);
  sVar2 = *(short *)(local_8 + 0x10);
  local_14 = CONCAT22(local_14._2_2_,sVar2);
  local_c = param_3;
  while (local_c = local_c + -1, -1 < local_c) {
    if (*(short *)(*(int *)(param_1 + 0x3c) + (uint)*(ushort *)(param_2 + 6 + local_c * 0x14) * 4)
        == sVar2) {
      *(short *)(local_8 + 0x2e + (uint)uVar1 * 0x14) =
           *(short *)(local_8 + 0x2e + (uint)uVar1 * 0x14) + 1;
    }
  }
  if (*(short *)(local_8 + 0x2e + (uint)uVar1 * 0x14) != 0) {
    uVar3 = FUN_00437c30((uint)*(ushort *)(local_8 + 0x2e + (uint)uVar1 * 0x14) << 4);
    *(undefined4 *)(local_8 + 0x30 + (local_10 & 0xffff) * 0x14) = uVar3;
    *(uint *)(local_8 + 0x34 + (local_10 & 0xffff) * 0x14) =
         *(int *)(local_8 + 0x30 + (local_10 & 0xffff) * 0x14) +
         (uint)*(ushort *)(local_8 + 0x2e + (local_10 & 0xffff) * 0x14) * 4;
    *(uint *)(local_8 + 0x38 + (local_10 & 0xffff) * 0x14) =
         *(int *)(local_8 + 0x34 + (local_10 & 0xffff) * 0x14) +
         (uint)*(ushort *)(local_8 + 0x2e + (local_10 & 0xffff) * 0x14) * 4;
    local_24 = *(int *)(param_1 + 0x4c) + param_4;
    local_20 = *(int *)(param_1 + 0x50) + param_4;
    local_18 = local_18 & 0xffff0000;
    FUN_00470c70(local_14 & 0xffff,local_28,local_2c);
    local_1c = (uint)local_1c._2_2_ << 0x10;
    while (local_c = param_3 + -1, -1 < local_c) {
      param_3 = local_c;
      if ((uint)*(ushort *)
                 (*(int *)(param_1 + 0x3c) + (uint)*(ushort *)(param_2 + 6 + local_c * 0x14) * 4) ==
          (local_14 & 0xffff)) {
        *(int *)(*(int *)(local_8 + 0x30 + (local_10 & 0xffff) * 0x14) + (local_18 & 0xffff) * 4) =
             local_24 + local_c * 0x20;
        *(int *)(*(int *)(local_8 + 0x34 + (local_10 & 0xffff) * 0x14) + (local_18 & 0xffff) * 4) =
             local_20 + local_c * 0x20;
        *(char *)(*(int *)(local_8 + 0x38 + (local_10 & 0xffff) * 0x14) + (local_1c & 0xffff) * 2) =
             *(char *)(param_2 + 0xc + local_c * 0x14) - local_28[0];
        *(char *)(*(int *)(local_8 + 0x38 + (local_10 & 0xffff) * 0x14) + 1 +
                 (local_1c & 0xffff) * 2) = *(char *)(param_2 + 0xd + local_c * 0x14) - local_2c[0];
        *(char *)(*(int *)(local_8 + 0x38 + (local_10 & 0xffff) * 0x14) + 2 +
                 (local_1c & 0xffff) * 2) = *(char *)(param_2 + 0xe + local_c * 0x14) - local_28[0];
        *(char *)(*(int *)(local_8 + 0x38 + (local_10 & 0xffff) * 0x14) + 3 +
                 (local_1c & 0xffff) * 2) = *(char *)(param_2 + 0xf + local_c * 0x14) - local_2c[0];
        *(char *)(*(int *)(local_8 + 0x38 + (local_10 & 0xffff) * 0x14) + 4 +
                 (local_1c & 0xffff) * 2) = *(char *)(param_2 + 0x10 + local_c * 0x14) - local_28[0]
        ;
        *(char *)(*(int *)(local_8 + 0x38 + (local_10 & 0xffff) * 0x14) + 5 +
                 (local_1c & 0xffff) * 2) = *(char *)(param_2 + 0x11 + local_c * 0x14) - local_2c[0]
        ;
        local_18 = CONCAT22(local_18._2_2_,(short)local_18 + 1);
        local_1c = CONCAT22(local_1c._2_2_,(short)local_1c + 4);
      }
    }
  }
  local_8 = 0x48da5c;
  __chkesp();
  return;
}

