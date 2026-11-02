/* FUN_0048f1c0 @ 0048f1c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0048f1c0(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_60 [16];
  uint local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  undefined2 *local_10;
  undefined2 *local_c;
  undefined2 *local_8;
  
  puVar2 = local_60;
  for (iVar1 = 0x17; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = *(undefined2 **)(param_1 + param_2 * 0xc);
  local_c = *(undefined2 **)(param_1 + 4 + param_2 * 0xc);
  local_10 = *(undefined2 **)(param_1 + 8 + param_2 * 0xc);
  iVar1 = FUN_00482db0(**(undefined4 **)(param_1 + param_2 * 0xc),
                       **(undefined4 **)(param_1 + 4 + param_2 * 0xc),
                       **(undefined4 **)(param_1 + 8 + param_2 * 0xc));
  if (-1 < iVar1) {
    local_14 = param_3 + param_2 * 0x14;
    *(undefined2 *)(local_14 + 8) = *local_8;
    *(undefined2 *)(local_14 + 10) = local_8[1];
    *(undefined2 *)(local_14 + 0xc) = *local_c;
    *(undefined2 *)(local_14 + 0xe) = local_c[1];
    *(undefined2 *)(local_14 + 0x10) = *local_10;
    *(undefined2 *)(local_14 + 0x12) = local_10[1];
    local_18 = (uint)*(byte *)(local_14 + 4);
    local_1c = (uint)*(byte *)(local_14 + 5);
    local_20 = (uint)*(byte *)(local_14 + 6);
    *(undefined1 *)(local_14 + 4) = 0;
    *(undefined1 *)(local_14 + 5) = 0;
    *(undefined1 *)(local_14 + 6) = 0xff;
    (*DAT_004e8a40)(local_14,*(undefined4 *)(local_8 + 2),*(undefined4 *)(local_c + 2),
                    *(undefined4 *)(local_10 + 2));
    __chkesp();
    *(undefined1 *)(local_14 + 4) = (undefined1)local_18;
    *(undefined1 *)(local_14 + 5) = (undefined1)local_1c;
    *(undefined1 *)(local_14 + 6) = (undefined1)local_20;
  }
  local_8 = (undefined2 *)0x48f32e;
  __chkesp();
  return;
}

