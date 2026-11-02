/* FUN_004857c0 @ 004857c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004857c0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_58 [16];
  int local_18;
  int local_14;
  int local_10;
  ushort *local_c;
  int local_8;
  
  puVar2 = local_58;
  for (iVar1 = 0x15; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_10 = param_1 + *(int *)(param_1 + 0x44);
  local_8 = local_10 + 0x14;
  local_c = *(ushort **)(param_1 + 0x30);
  local_14 = *(int *)(param_1 + 0xcc);
  *(undefined2 *)(local_14 + 0x2e) = 0;
  *(undefined2 *)(local_14 + 0x42) = 0;
  *(undefined2 *)(local_14 + 0x56) = 0;
  *(undefined2 *)(local_14 + 0x6a) = 0;
  local_18 = 0;
  do {
    if (*(int *)(&DAT_00507fa4 + (uint)*local_c * 0x34) != 0) {
      (**(code **)(&DAT_00507fa4 + (uint)*local_c * 0x34))(param_1,local_8,local_c[1],local_18);
      iVar1 = __chkesp();
      if (iVar1 != 0) {
        *(ushort *)(local_14 + 0x2c + (uint)*(ushort *)(local_14 + 0xc) * 0x14) = *local_c;
        if (*(short *)(local_14 + 0xc) == 0) {
          *(undefined4 *)(local_14 + 0x3c + (uint)*(ushort *)(local_14 + 0xc) * 0x14) = 0;
        }
        else {
          *(uint *)(local_14 + 0x3c + (*(ushort *)(local_14 + 0xc) - 1) * 0x14) =
               local_14 + 0x2c + (uint)*(ushort *)(local_14 + 0xc) * 0x14;
          *(undefined4 *)(local_14 + 0x3c + (uint)*(ushort *)(local_14 + 0xc) * 0x14) = 0;
        }
        *(short *)(local_14 + 0xc) = *(short *)(local_14 + 0xc) + 1;
      }
    }
    local_8 = local_8 + *(int *)(local_c + 4);
    local_18 = local_18 + *(int *)(local_c + 6);
    local_c = *(ushort **)(local_c + 8);
  } while (local_c != (ushort *)0x0);
  local_8 = 0x48594a;
  __chkesp();
  return;
}

