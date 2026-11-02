/* FUN_0048fc30 @ 0048fc30 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0048fc30(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_88 [16];
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  int local_18;
  undefined2 *local_14;
  undefined2 *local_10;
  undefined2 *local_c;
  undefined2 *local_8;
  
  puVar2 = local_88;
  for (iVar1 = 0x21; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = *(undefined2 **)(param_1 + param_2 * 0x10);
  local_c = *(undefined2 **)(param_1 + 4 + param_2 * 0x10);
  local_10 = *(undefined2 **)(param_1 + 8 + param_2 * 0x10);
  local_14 = *(undefined2 **)(param_1 + 0xc + param_2 * 0x10);
  iVar1 = FUN_00482db0(**(undefined4 **)(param_1 + param_2 * 0x10),
                       **(undefined4 **)(param_1 + 4 + param_2 * 0x10),
                       **(undefined4 **)(param_1 + 8 + param_2 * 0x10));
  if (-1 < iVar1) {
    local_18 = param_3 + param_2 * 0x24;
    *(undefined2 *)(local_18 + 8) = *local_8;
    *(undefined2 *)(local_18 + 10) = local_8[1];
    *(undefined2 *)(local_18 + 0x10) = *local_c;
    *(undefined2 *)(local_18 + 0x12) = local_c[1];
    *(undefined2 *)(local_18 + 0x18) = *local_14;
    *(undefined2 *)(local_18 + 0x1a) = local_14[1];
    *(undefined2 *)(local_18 + 0x20) = *local_10;
    *(undefined2 *)(local_18 + 0x22) = local_10[1];
    local_28 = (uint)*(byte *)(local_18 + 4);
    local_38 = (uint)*(byte *)(local_18 + 5);
    local_48 = (uint)*(byte *)(local_18 + 6);
    local_24 = (uint)*(byte *)(local_18 + 0xc);
    local_34 = (uint)*(byte *)(local_18 + 0xd);
    local_44 = (uint)*(byte *)(local_18 + 0xe);
    local_20 = (uint)*(byte *)(local_18 + 0x14);
    local_30 = (uint)*(byte *)(local_18 + 0x15);
    local_40 = (uint)*(byte *)(local_18 + 0x16);
    local_1c = (uint)*(byte *)(local_18 + 0x1c);
    local_2c = (uint)*(byte *)(local_18 + 0x1d);
    local_3c = (uint)*(byte *)(local_18 + 0x1e);
    *(undefined1 *)(local_18 + 4) = 0;
    *(undefined1 *)(local_18 + 5) = 0;
    *(undefined1 *)(local_18 + 6) = 0xff;
    *(undefined1 *)(local_18 + 0xc) = 0;
    *(undefined1 *)(local_18 + 0xd) = 0;
    *(undefined1 *)(local_18 + 0xe) = 0xff;
    *(undefined1 *)(local_18 + 0x14) = 0;
    *(undefined1 *)(local_18 + 0x15) = 0;
    *(undefined1 *)(local_18 + 0x16) = 0xff;
    *(undefined1 *)(local_18 + 0x1c) = 0;
    *(undefined1 *)(local_18 + 0x1d) = 0;
    *(undefined1 *)(local_18 + 0x1e) = 0xff;
    (*DAT_004e8a4c)(local_18,*(undefined4 *)(local_8 + 2),*(undefined4 *)(local_c + 2),
                    *(undefined4 *)(local_14 + 2),*(undefined4 *)(local_10 + 2));
    __chkesp();
    *(undefined1 *)(local_18 + 4) = (undefined1)local_28;
    *(undefined1 *)(local_18 + 5) = (undefined1)local_38;
    *(undefined1 *)(local_18 + 6) = (undefined1)local_48;
    *(undefined1 *)(local_18 + 0xc) = (undefined1)local_24;
    *(undefined1 *)(local_18 + 0xd) = (undefined1)local_34;
    *(undefined1 *)(local_18 + 0xe) = (undefined1)local_44;
    *(undefined1 *)(local_18 + 0x14) = (undefined1)local_20;
    *(undefined1 *)(local_18 + 0x15) = (undefined1)local_30;
    *(undefined1 *)(local_18 + 0x16) = (undefined1)local_40;
    *(undefined1 *)(local_18 + 0x1c) = (undefined1)local_1c;
    *(undefined1 *)(local_18 + 0x1d) = (undefined1)local_2c;
    *(undefined1 *)(local_18 + 0x1e) = (undefined1)local_3c;
  }
  local_8 = (undefined2 *)0x48fecc;
  __chkesp();
  return;
}

