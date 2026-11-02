/* FUN_0048afd0 @ 0048afd0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_0048afd0(int param_1,int param_2,undefined4 param_3,undefined1 param_4,undefined1 param_5,
            undefined1 param_6,undefined1 param_7)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_64 [16];
  undefined1 local_24 [4];
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;
  undefined2 *local_10;
  undefined2 *local_c;
  undefined2 *local_8;
  
  puVar2 = local_64;
  for (iVar1 = 0x18; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = *(undefined2 **)(param_1 + param_2 * 0xc);
  local_c = *(undefined2 **)(param_1 + 4 + param_2 * 0xc);
  local_10 = *(undefined2 **)(param_1 + 8 + param_2 * 0xc);
  if ((local_8 != (undefined2 *)0x0) &&
     (iVar1 = FUN_00482db0(**(undefined4 **)(param_1 + param_2 * 0xc),
                           **(undefined4 **)(param_1 + 4 + param_2 * 0xc),
                           **(undefined4 **)(param_1 + 8 + param_2 * 0xc)), -1 < iVar1)) {
    local_1c = *local_8;
    local_1a = local_8[1];
    local_18 = *local_c;
    local_16 = local_c[1];
    local_14 = *local_10;
    local_12 = local_10[1];
    local_20 = param_4;
    local_1f = param_5;
    local_1e = param_6;
    local_1d = 2;
    (*DAT_004e8a6c)(CONCAT31((int3)(CONCAT22((short)((uint)local_c >> 0x10),local_14) >> 8),param_7)
                   );
    __chkesp();
    (*DAT_004e8a40)(local_24,*(undefined4 *)(local_8 + 2),*(undefined4 *)(local_c + 2),
                    *(undefined4 *)(local_10 + 2));
    __chkesp();
  }
  local_8 = (undefined2 *)0x48b104;
  __chkesp();
  return;
}

