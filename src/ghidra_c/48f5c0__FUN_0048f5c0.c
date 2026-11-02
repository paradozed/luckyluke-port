/* FUN_0048f5c0 @ 0048f5c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0048f5c0(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  for (local_8 = param_2; local_8 < param_3; local_8 = local_8 + 1) {
    FUN_00497690((undefined4 *)(param_1 + local_8 * 0xc),
                 (undefined4 *)(param_1 + (local_8 + 1) * 0xc),0xc);
    FUN_00497690((undefined4 *)(param_4 + local_8 * 0x14),
                 (undefined4 *)(param_4 + (local_8 + 1) * 0x14),0x14);
  }
  local_8 = 0x48f64a;
  __chkesp();
  return;
}

