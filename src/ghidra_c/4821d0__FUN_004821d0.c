/* FUN_004821d0 @ 004821d0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004821d0(byte *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_88 [16];
  int local_48;
  int local_44;
  uint local_40;
  short *local_3c;
  ushort *local_38;
  int local_34;
  undefined4 local_30 [5];
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int *local_c;
  int local_8;
  
  puVar2 = local_88;
  for (iVar1 = 0x21; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((*param_1 & 2) == 0) {
    local_c = *(int **)(param_1 + 0x28);
    local_34 = *(int *)(param_1 + 0x20);
    FUN_004823a0((undefined4 *)(param_1 + 0x5c));
    FUN_004824a0(0x4c63f8);
    FUN_004828f0(local_30);
    local_44 = 0;
    for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
      local_48 = *local_c;
      local_c = local_c + 1;
      local_10 = local_48;
      if (local_48 == -3) {
        FUN_00483390();
        FUN_00483250();
      }
      else if (local_48 == -2) {
        FUN_00483390();
      }
      else if (local_48 == -1) {
        FUN_00483250();
      }
      else {
        local_38 = (ushort *)(local_34 + local_48 * 0x28);
        if (local_48 != local_44) {
          local_3c = *(short **)(local_38 + 8);
          local_1c = (int)*local_3c;
          local_18 = (int)local_3c[1];
          local_14 = (int)local_3c[2];
          FUN_004824a0((int)local_30);
        }
        local_40 = (uint)(byte)local_38[10];
        if ((local_40 & 1) == 1) {
          FUN_0047c630((undefined2 *)local_30,local_38[0xb],local_38[0xc],local_38[0xd]);
          FUN_00483140(local_30);
          FUN_004823a0(local_30);
        }
        else {
          FUN_00482130((undefined2 *)local_30,(undefined2 *)(param_1 + 0x5c));
        }
        if (local_40 < 2) {
          FUN_0047f6d0(*(int *)(local_38 + 2),*(int *)(local_38 + 4),(uint)*local_38);
        }
      }
    }
  }
  local_8 = 0x482395;
  __chkesp();
  return;
}

