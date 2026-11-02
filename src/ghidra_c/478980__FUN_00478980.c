/* FUN_00478980 @ 00478980 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00478980(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_58 [16];
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  ushort *local_8;
  
  puVar2 = local_58;
  for (iVar1 = 0x15; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_10 = 0;
  FUN_00497690((undefined4 *)&DAT_004be2fc,(undefined4 *)&DAT_004be35c,0x60);
  local_8 = *(ushort **)(param_1 + 0x30);
  local_c = *(int *)(param_1 + 0x4c);
  if (param_2 == 1) {
    for (; local_8 != (ushort *)0x0; local_8 = *(ushort **)(local_8 + 8)) {
      if (0x70 < (int)(local_10 + (uint)local_8[1])) {
        FUN_00478780(local_8 + 10,0x70 - local_10,local_c);
        break;
      }
      local_10 = local_10 + (uint)local_8[1];
      local_c = local_c + *(int *)(local_8 + 6);
    }
  }
  else if (param_2 == 2) {
    for (; local_8 != (ushort *)0x0; local_8 = *(ushort **)(local_8 + 8)) {
      if (0xa1 < (int)(local_10 + (uint)local_8[1])) {
        FUN_004787e0(local_8 + 10,0xa1 - local_10,local_c);
        break;
      }
      local_10 = local_10 + (uint)local_8[1];
      local_c = local_c + *(int *)(local_8 + 6);
    }
  }
  else if (param_2 == 3) {
    for (; local_8 != (ushort *)0x0; local_8 = *(ushort **)(local_8 + 8)) {
      for (local_14 = 0; local_14 < 0xc; local_14 = local_14 + 1) {
        if ((*(int *)(&DAT_004be2fc + local_14 * 8) < (int)(local_10 + (uint)local_8[1])) &&
           (*(int *)(&DAT_004be300 + local_14 * 8) == 0)) {
          *(undefined4 *)(&DAT_004be300 + local_14 * 8) = 1;
          FUN_00478840();
        }
      }
      local_10 = local_10 + (uint)local_8[1];
      local_c = local_c + *(int *)(local_8 + 6);
    }
  }
  else if (param_2 == 1000) {
    FUN_00478860(local_8 + 10,0,local_c);
  }
  else {
    for (; local_8 != (ushort *)0x0; local_8 = *(ushort **)(local_8 + 8)) {
      local_18 = (uint)*local_8;
      if (local_18 == 2) {
        FUN_004785a0(local_8 + 10,(uint)local_8[1],local_c);
      }
      else if (local_18 == 6) {
        FUN_004788b0(local_8 + 10,(uint)local_8[1],local_c);
      }
      local_10 = local_10 + (uint)local_8[1];
      local_c = local_c + *(int *)(local_8 + 6);
    }
  }
  local_8 = (ushort *)0x478c22;
  __chkesp();
  return;
}

