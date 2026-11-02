/* FUN_0048c7d0 @ 0048c7d0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0048c7d0(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_64 [16];
  uint local_24;
  uint local_20;
  uint local_1c;
  int local_18;
  undefined2 *local_14;
  undefined2 *local_10;
  undefined2 *local_c;
  undefined2 *local_8;
  
  puVar2 = local_64;
  for (iVar1 = 0x18; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = *(undefined2 **)(param_1 + param_2 * 0x10);
  local_c = *(undefined2 **)(param_1 + 4 + param_2 * 0x10);
  local_10 = *(undefined2 **)(param_1 + 8 + param_2 * 0x10);
  local_14 = *(undefined2 **)(param_1 + 0xc + param_2 * 0x10);
  iVar1 = FUN_00482db0(**(undefined4 **)(param_1 + param_2 * 0x10),
                       **(undefined4 **)(param_1 + 4 + param_2 * 0x10),
                       **(undefined4 **)(param_1 + 0xc + param_2 * 0x10));
  if (-1 < iVar1) {
    local_18 = param_3 + param_2 * 0x28;
    *(undefined2 *)(local_18 + 8) = *local_8;
    *(undefined2 *)(local_18 + 10) = local_8[1];
    *(undefined2 *)(local_18 + 0x10) = *local_c;
    *(undefined2 *)(local_18 + 0x12) = local_c[1];
    *(undefined2 *)(local_18 + 0x18) = *local_14;
    *(undefined2 *)(local_18 + 0x1a) = local_14[1];
    *(undefined2 *)(local_18 + 0x20) = *local_10;
    *(undefined2 *)(local_18 + 0x22) = local_10[1];
    local_1c = (uint)*(byte *)(local_18 + 4);
    local_20 = (uint)*(byte *)(local_18 + 5);
    local_24 = (uint)*(byte *)(local_18 + 6);
    *(undefined1 *)(local_18 + 4) = 0;
    *(undefined1 *)(local_18 + 5) = 0;
    *(undefined1 *)(local_18 + 6) = 0xff;
    (*DAT_004e8a54)(local_18,*(undefined4 *)(local_8 + 2),*(undefined4 *)(local_c + 2),
                    *(undefined4 *)(local_14 + 2),*(undefined4 *)(local_10 + 2));
    __chkesp();
    *(undefined1 *)(local_18 + 4) = (undefined1)local_1c;
    *(undefined1 *)(local_18 + 5) = (undefined1)local_20;
    *(undefined1 *)(local_18 + 6) = (undefined1)local_24;
  }
  local_8 = (undefined2 *)0x48c970;
  __chkesp();
  return;
}

