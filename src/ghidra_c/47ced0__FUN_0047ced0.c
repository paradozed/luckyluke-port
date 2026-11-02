/* FUN_0047ced0 @ 0047ced0 */
/* decompiled from Lucky.exe (Game.run) */


int __cdecl FUN_0047ced0(int param_1,uint param_2,int param_3,int *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_54 [18];
  ushort *local_c;
  int local_8;
  
  puVar2 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = param_1 + *(int *)(param_1 + 0x44) + 0x14;
  local_c = *(ushort **)(param_1 + 0x30);
  do {
    if (*local_c == param_2) {
      switch(*local_c) {
      case 0:
        *param_4 = *(int *)(param_1 + 0x18) + (uint)*(ushort *)(local_8 + param_3 * 0xc) * 8;
        param_4[1] = *(int *)(param_1 + 0x18) + (uint)*(ushort *)(local_8 + 2 + param_3 * 0xc) * 8;
        param_4[2] = *(int *)(param_1 + 0x18) + (uint)*(ushort *)(local_8 + 4 + param_3 * 0xc) * 8;
        return local_8;
      case 2:
        *param_4 = *(int *)(param_1 + 0x18) + (uint)*(ushort *)(local_8 + param_3 * 0x14) * 8;
        param_4[1] = *(int *)(param_1 + 0x18) + (uint)*(ushort *)(local_8 + 2 + param_3 * 0x14) * 8;
        param_4[2] = *(int *)(param_1 + 0x18) + (uint)*(ushort *)(local_8 + 4 + param_3 * 0x14) * 8;
        return local_8;
      case 4:
        *param_4 = *(int *)(param_1 + 0x18) + (uint)*(ushort *)(local_8 + param_3 * 0x14) * 8;
        param_4[1] = *(int *)(param_1 + 0x18) + (uint)*(ushort *)(local_8 + 2 + param_3 * 0x14) * 8;
        param_4[2] = *(int *)(param_1 + 0x18) + (uint)*(ushort *)(local_8 + 4 + param_3 * 0x14) * 8;
        return local_8;
      case 6:
        *param_4 = *(int *)(param_1 + 0x18) + (uint)*(ushort *)(local_8 + param_3 * 0x1c) * 8;
        param_4[1] = *(int *)(param_1 + 0x18) + (uint)*(ushort *)(local_8 + 2 + param_3 * 0x1c) * 8;
        param_4[2] = *(int *)(param_1 + 0x18) + (uint)*(ushort *)(local_8 + 4 + param_3 * 0x1c) * 8;
        return local_8;
      }
    }
    local_8 = local_8 + *(int *)(local_c + 4);
    local_c = *(ushort **)(local_c + 8);
  } while (local_c != (ushort *)0x0);
  return 0;
}

