/* FUN_0047d550 @ 0047d550 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047d550(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  ushort *local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = *(ushort **)(param_1 + 0x30);
  do {
    (**(code **)(&DAT_00507fac + (uint)*local_8 * 0x34))(local_8[1],param_3,param_2);
    __chkesp();
    param_3 = param_3 + *(int *)(local_8 + 6);
    local_8 = *(ushort **)(local_8 + 8);
  } while (local_8 != (ushort *)0x0);
  local_8 = (ushort *)0x47d5c8;
  __chkesp();
  return;
}

