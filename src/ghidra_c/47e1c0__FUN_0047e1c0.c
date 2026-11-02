/* FUN_0047e1c0 @ 0047e1c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047e1c0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  int local_c;
  ushort *local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = *(ushort **)(param_1 + 0x30);
  local_c = *(int *)(param_1 + 0x4c + DAT_004e8ad8 * 4);
  do {
    (**(code **)(&DAT_00507f88 + (uint)*local_8 * 0x34))
              (local_8 + 10,local_8[1],local_c,DAT_00508158);
    __chkesp();
    local_c = local_c + *(int *)(local_8 + 6);
    local_8 = *(ushort **)(local_8 + 8);
  } while (local_8 != (ushort *)0x0);
  local_8 = (ushort *)0x47e252;
  __chkesp();
  return;
}

