/* FUN_004755a0 @ 004755a0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004755a0(int param_1)

{
  undefined4 uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_90 [16];
  uint local_50;
  uint local_4c;
  ushort *local_48;
  int local_44;
  ushort local_40;
  undefined2 uStack_3e;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined2 local_28;
  undefined2 uStack_26;
  undefined2 local_24;
  undefined2 uStack_22;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar4 = local_90;
  for (iVar3 = 0x23; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_44 = **(int **)(*(int *)(DAT_004f2458 + 0x9c) + 8);
  local_48 = *(ushort **)(param_1 + 8);
  local_20 = 0;
  do {
    if ((int)(uint)*local_48 <= local_20) {
LAB_0047587a:
      local_8 = 0x47588a;
      __chkesp();
      return;
    }
    FUN_00475890(local_44,&local_1c);
    local_10 = local_10 + *(int *)(local_44 + 0x90);
    local_1c = local_1c + *(int *)(local_44 + 0x90);
    local_c = local_c + *(int *)(local_44 + 0x94);
    local_18 = local_18 + *(int *)(local_44 + 0x94);
    local_8 = local_8 + *(int *)(local_44 + 0x98);
    local_14 = local_14 + *(int *)(local_44 + 0x98);
    uVar1 = FUN_0040d810(&local_1c,(int *)(*(int *)(local_48 + 2) + local_20 * 0x2c));
    if ((short)uVar1 != 0) {
      local_3c = *(int *)(local_44 + 0x90);
      local_38 = *(undefined4 *)(local_44 + 0x94);
      local_34 = *(undefined4 *)(local_44 + 0x98);
      if (local_3c - *(int *)(*(int *)(local_48 + 2) + 0x1c + local_20 * 0x2c) < 0) {
        local_4c = -(local_3c - *(int *)(*(int *)(local_48 + 2) + 0x1c + local_20 * 0x2c));
      }
      else {
        local_4c = local_3c - *(int *)(*(int *)(local_48 + 2) + 0x1c + local_20 * 0x2c);
      }
      _local_24 = CONCAT22(uStack_22,(undefined2)local_4c);
      if (*(int *)(*(int *)(local_48 + 2) + 0x1c + local_20 * 0x2c) -
          *(int *)(*(int *)(local_48 + 2) + local_20 * 0x2c) < 0) {
        local_50 = -(*(int *)(*(int *)(local_48 + 2) + 0x1c + local_20 * 0x2c) -
                    *(int *)(*(int *)(local_48 + 2) + local_20 * 0x2c));
      }
      else {
        local_50 = *(int *)(*(int *)(local_48 + 2) + 0x1c + local_20 * 0x2c) -
                   *(int *)(*(int *)(local_48 + 2) + local_20 * 0x2c);
      }
      _local_28 = CONCAT22(uStack_26,(undefined2)local_50);
      if ((int)((local_50 & 0xffff) - 1) < (int)(local_4c & 0xffff)) {
        if (*DAT_004f58a8 != 0x536f6674) {
          FUN_0047d700(local_44,(uint)*(byte *)(*(int *)(local_48 + 2) + 0x18 + local_20 * 0x2c));
        }
      }
      else {
        uVar2 = (ushort)*(byte *)(*(int *)(local_48 + 2) + 0x19 + local_20 * 0x2c) -
                (short)(((uint)*(byte *)(*(int *)(local_48 + 2) + 0x18 + local_20 * 0x2c) *
                        (local_4c & 0xffff)) / (local_50 & 0xffff));
        _local_40 = CONCAT22(uStack_3e,uVar2);
        if (*DAT_004f58a8 != 0x536f6674) {
          FUN_0047d700(local_44,(uint)uVar2);
        }
        DAT_004f167a = 1;
        _DAT_004f17f0 = *(undefined4 *)(*(int *)(local_48 + 2) + 0x1c + local_20 * 0x2c);
        _DAT_004f17f4 = *(undefined4 *)(*(int *)(local_48 + 2) + 4 + local_20 * 0x2c);
        _DAT_004f17f8 = *(undefined4 *)(*(int *)(local_48 + 2) + 8 + local_20 * 0x2c);
      }
      goto LAB_0047587a;
    }
    DAT_004f167a = 0;
    local_20 = local_20 + 1;
  } while( true );
}

