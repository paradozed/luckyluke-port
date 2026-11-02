/* FUN_0048ea00 @ 0048ea00 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_0048ea00(int param_1,int param_2,undefined4 param_3,undefined1 param_4,undefined1 param_5,
            undefined1 param_6,undefined1 param_7)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_6c [16];
  undefined1 local_2c [4];
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_25;
  undefined2 local_24;
  undefined2 local_22;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 *local_14;
  undefined2 *local_10;
  undefined2 *local_c;
  undefined2 *local_8;
  
  puVar2 = local_6c;
  for (iVar1 = 0x1a; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = *(undefined2 **)(param_1 + param_2 * 0x10);
  local_c = *(undefined2 **)(param_1 + 4 + param_2 * 0x10);
  local_10 = *(undefined2 **)(param_1 + 8 + param_2 * 0x10);
  local_14 = *(undefined2 **)(param_1 + 0xc + param_2 * 0x10);
  if ((local_8 != (undefined2 *)0x0) &&
     (iVar1 = FUN_00482db0(**(undefined4 **)(param_1 + param_2 * 0x10),
                           **(undefined4 **)(param_1 + 4 + param_2 * 0x10),
                           **(undefined4 **)(param_1 + 8 + param_2 * 0x10)), -1 < iVar1)) {
    local_24 = *local_8;
    local_22 = local_8[1];
    local_20 = *local_c;
    local_1e = local_c[1];
    local_1c = *local_14;
    local_1a = local_14[1];
    local_18 = *local_10;
    local_16 = local_10[1];
    local_28 = param_4;
    local_27 = param_5;
    local_26 = param_6;
    local_25 = 2;
    (*DAT_004e8a6c)(CONCAT31((int3)(CONCAT22((short)((uint)local_14 >> 0x10),local_18) >> 8),param_7
                            ));
    __chkesp();
    (*DAT_004e8a44)(local_2c,*(undefined4 *)(local_8 + 2),*(undefined4 *)(local_c + 2),
                    *(undefined4 *)(local_14 + 2),*(undefined4 *)(local_10 + 2));
    __chkesp();
  }
  local_8 = (undefined2 *)0x48eb60;
  __chkesp();
  return;
}

