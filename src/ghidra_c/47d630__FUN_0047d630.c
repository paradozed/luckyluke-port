/* FUN_0047d630 @ 0047d630 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047d630(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_54 [16];
  int local_14;
  int local_10;
  int local_c;
  ushort *local_8;
  
  puVar2 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 != 0) {
    if (*(int *)(param_1 + 8) == 0) {
      local_14 = param_1;
    }
    else {
      local_14 = *(int *)(param_1 + 8);
    }
    local_8 = *(ushort **)(param_1 + 0x30);
    local_c = local_14 + *(int *)(local_14 + 0x44);
    local_10 = local_c + 0x14;
    do {
      (**(code **)(&DAT_00507fb0 + (uint)*local_8 * 0x34))(local_8[1],param_3,local_10,param_2);
      __chkesp();
      param_3 = param_3 + *(int *)(local_8 + 6);
      local_10 = local_10 + *(int *)(local_8 + 4);
      local_8 = *(ushort **)(local_8 + 8);
    } while (local_8 != (ushort *)0x0);
  }
  local_8 = (ushort *)0x47d6f2;
  __chkesp();
  return;
}

