/* FUN_0047e260 @ 0047e260 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047e260(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  int local_10;
  int local_c;
  ushort *local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_10 = 0;
  local_8 = *(ushort **)(param_1 + 0x30);
  local_c = *(int *)(param_1 + 0x4c + DAT_004e8ad8 * 4);
  do {
    if (local_8 == (ushort *)0x0) {
LAB_0047e30a:
      local_8 = (ushort *)0x47e317;
      __chkesp();
      return;
    }
    if (param_2 < (int)(local_10 + (uint)local_8[1])) {
      (**(code **)(&DAT_00507f8c + (uint)*local_8 * 0x34))(local_8 + 10,param_2 - local_10,local_c);
      __chkesp();
      goto LAB_0047e30a;
    }
    local_c = local_c + *(int *)(local_8 + 6);
    local_10 = local_10 + (uint)local_8[1];
    local_8 = *(ushort **)(local_8 + 8);
  } while( true );
}

