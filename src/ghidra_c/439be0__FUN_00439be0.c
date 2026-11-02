/* FUN_00439be0 @ 00439be0 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __cdecl FUN_00439be0(int param_1)

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
  local_8 = DAT_004e84e8;
  while( true ) {
    if (local_8 == 0) {
      return 0;
    }
    if (local_8 == param_1) break;
    local_8 = *(int *)(local_8 + 4);
  }
  return 1;
}

