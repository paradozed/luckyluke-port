/* FUN_00483e30 @ 00483e30 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00483e30(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_5c [16];
  uint local_1c;
  int local_18;
  int local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  puVar2 = local_5c;
  for (iVar1 = 0x16; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((*(byte *)*param_1 & 2) != 0) {
    FUN_0047f140((byte *)*param_1);
  }
  FUN_004840c0((int)param_1,(uint)*(ushort *)((int)param_1 + 0x32));
  iVar1 = param_1[0x13];
  local_10 = iVar1 + 4;
  param_1[4] = DAT_004e8abc;
  param_1[3] = param_1[0x13];
  if ((uint)*(ushort *)(param_1[2] + 2) < *(uint *)(*param_1 + 0x1c)) {
    local_1c = (uint)*(ushort *)(param_1[2] + 2);
  }
  else {
    local_1c = *(uint *)(*param_1 + 0x1c);
  }
  local_c = local_1c;
  local_14 = *(int *)(*param_1 + 0x20);
  local_8 = local_1c;
  while (local_8 = local_8 - 1, -1 < (int)local_8) {
    *(undefined1 *)(local_14 + 0x14 + local_8 * 0x28) = *(undefined1 *)(local_10 + local_8 * 0x14);
    *(undefined2 *)(local_14 + 0x16 + local_8 * 0x28) = *(undefined2 *)(iVar1 + 6 + local_8 * 0x14);
    *(undefined2 *)(local_14 + 0x18 + local_8 * 0x28) = *(undefined2 *)(iVar1 + 8 + local_8 * 0x14);
    *(undefined2 *)(local_14 + 0x1a + local_8 * 0x28) = *(undefined2 *)(iVar1 + 10 + local_8 * 0x14)
    ;
    *(undefined2 *)(local_14 + 0x1c + local_8 * 0x28) =
         *(undefined2 *)(iVar1 + 0xc + local_8 * 0x14);
    *(undefined2 *)(local_14 + 0x1e + local_8 * 0x28) =
         *(undefined2 *)(iVar1 + 0xe + local_8 * 0x14);
    *(undefined2 *)(local_14 + 0x20 + local_8 * 0x28) =
         *(undefined2 *)(iVar1 + 0x10 + local_8 * 0x14);
    *(undefined2 *)(local_14 + 0x22 + local_8 * 0x28) =
         *(undefined2 *)(iVar1 + 0x12 + local_8 * 0x14);
    *(undefined2 *)(local_14 + 0x24 + local_8 * 0x28) =
         *(undefined2 *)(iVar1 + 0x14 + local_8 * 0x14);
    *(undefined2 *)(local_14 + 0x26 + local_8 * 0x28) =
         *(undefined2 *)(iVar1 + 0x16 + local_8 * 0x14);
  }
  FUN_00483b60((int)param_1,(ushort *)param_1[2],(short *)((int)param_1 + 0x32));
  iVar1 = param_1[0x12];
  param_1[0x12] = param_1[0x13];
  param_1[0x13] = iVar1;
  local_18 = param_1[0x10];
  param_1[0x10] = param_1[0x11];
  param_1[0x11] = local_18;
  FUN_004840c0((int)param_1,(uint)*(ushort *)((int)param_1 + 0x32));
  local_8 = 0x4840b3;
  __chkesp();
  return;
}

