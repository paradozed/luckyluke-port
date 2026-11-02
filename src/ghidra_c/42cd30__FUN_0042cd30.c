/* FUN_0042cd30 @ 0042cd30 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0042cd30(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [17];
  uint local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = 0;
  do {
    if (DAT_004e85a4 <= local_8) {
LAB_0042cdac:
      local_8 = 0x42cdb9;
      __chkesp();
      return;
    }
    if (*(int *)(DAT_004d1e74 + 0x14 + local_8 * 0x18) == param_1) {
      (*DAT_004e8a2c)(param_2,param_3,DAT_004d1e74 + local_8 * 0x18);
      __chkesp();
      goto LAB_0042cdac;
    }
    local_8 = local_8 + 1;
  } while( true );
}

