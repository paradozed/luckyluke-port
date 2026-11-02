/* FUN_00481de0 @ 00481de0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00481de0(byte *param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_9c [16];
  uint local_5c;
  ushort local_58;
  ushort local_56;
  ushort local_54;
  uint local_50;
  short *local_4c;
  int local_48;
  int local_44;
  int local_40;
  ushort *local_38;
  int local_34;
  short local_30 [10];
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  uint *local_c;
  uint local_8;
  
  puVar2 = local_9c;
  for (iVar1 = 0x26; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((*param_1 & 2) == 0) {
    local_c = (uint *)(*(int *)(param_1 + 0x28) + param_2 * 4);
    local_34 = *(int *)(param_1 + 0x20);
    FUN_004828f0((undefined4 *)local_30);
    for (local_8 = param_2; local_8 < *(uint *)(param_1 + 0x24); local_8 = local_8 + 1) {
      local_5c = *local_c;
      local_c = local_c + 1;
      local_10 = local_5c;
      if (local_5c == 0xfffffffd) {
        FUN_00483390();
        FUN_00483250();
      }
      else if (local_5c == 0xfffffffe) {
        FUN_00483390();
      }
      else if (local_5c == 0xffffffff) {
        FUN_00483250();
      }
      else {
        local_38 = (ushort *)(local_34 + local_5c * 0x28);
        if (local_5c != param_2) {
          local_4c = *(short **)(local_38 + 8);
          local_1c = (int)*local_4c;
          local_18 = (int)local_4c[1];
          local_14 = (int)local_4c[2];
          FUN_004824a0((int)local_30);
        }
        local_50 = (uint)(byte)local_38[10];
        if (((byte)local_38[10] & 2) != 0) {
          local_58 = local_38[0xe];
          local_56 = local_38[0xf];
          local_54 = local_38[0x10];
          FUN_0047f6d0((int)&local_58,(int)&local_58,1);
          local_1c = (int)(short)local_58;
          local_18 = (int)(short)local_56;
          local_14 = (int)(short)local_54;
          FUN_004824a0((int)local_30);
        }
        if ((local_50 & 1) == 1) {
          FUN_0047c630(local_30,local_38[0xb],local_38[0xc],local_38[0xd]);
          FUN_00483140((undefined4 *)local_30);
          FUN_004823a0((undefined4 *)local_30);
        }
        else {
          FUN_00482130(local_30,(undefined2 *)(param_1 + 0x5c));
        }
        if (local_50 < 2) {
          FUN_0047f6d0(*(int *)(local_38 + 2),*(int *)(local_38 + 4),(uint)*local_38);
        }
        else if ((local_50 & 2) == 0) {
          local_48 = (short)local_38[0x11] + 0x1000;
          local_44 = (short)local_38[0x12] + 0x1000;
          local_40 = (short)local_38[0x13] + 0x1000;
          FUN_0047f830(*(int *)(local_38 + 2),*(int *)(local_38 + 4),&local_48,(uint)*local_38);
        }
        else if ((local_50 & 4) == 0) {
          FUN_0047f6d0(*(int *)(local_38 + 2),*(int *)(local_38 + 4),(uint)*local_38);
        }
        else {
          local_48 = (short)local_38[0x11] + 0x1000;
          local_44 = (short)local_38[0x12] + 0x1000;
          local_40 = (short)local_38[0x13] + 0x1000;
          if ((*local_c == 0xfffffffe) || (*local_c == 0xfffffffd)) {
            FUN_004823e0(local_30,&local_48);
            FUN_004823a0((undefined4 *)local_30);
            FUN_0047f6d0(*(int *)(local_38 + 2),*(int *)(local_38 + 4),(uint)*local_38);
          }
          else {
            FUN_0047f830(*(int *)(local_38 + 2),*(int *)(local_38 + 4),&local_48,(uint)*local_38);
          }
        }
      }
    }
  }
  local_8 = 0x48211f;
  __chkesp();
  return;
}

