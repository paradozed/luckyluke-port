/* FUN_0047e5b0 @ 0047e5b0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047e5b0(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_50 [16];
  int local_10;
  int local_c;
  ushort *local_8;
  
  puVar3 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_10 = 0;
  local_8 = *(ushort **)(param_1 + 0x30);
  local_c = *(int *)(param_1 + 0x4c + DAT_004e8ad8 * 4);
  do {
    if (local_8 == (ushort *)0x0) {
LAB_0047e69d:
      local_8 = (ushort *)0x47e6aa;
      __chkesp();
      return;
    }
    if (param_2 < (int)(local_10 + (uint)local_8[1])) {
      (**(code **)(&DAT_00507f9c + (uint)*local_8 * 0x34))(local_8 + 10,param_2 - local_10);
      uVar1 = __chkesp();
      *param_3 = uVar1;
      (**(code **)(&DAT_00507fa0 + (uint)*local_8 * 0x34))(local_8 + 10,param_2 - local_10);
      uVar1 = __chkesp();
      *param_4 = uVar1;
      goto LAB_0047e69d;
    }
    local_c = local_c + *(int *)(local_8 + 6);
    local_10 = local_10 + (uint)local_8[1];
    local_8 = *(ushort **)(local_8 + 8);
  } while( true );
}

