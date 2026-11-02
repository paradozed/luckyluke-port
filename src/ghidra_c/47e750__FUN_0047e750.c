/* FUN_0047e750 @ 0047e750 */
/* decompiled from Lucky.exe (Game.run) */


int __cdecl FUN_0047e750(int param_1,int param_2)

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
  local_8 = 0;
  while( true ) {
    if (*(int *)(param_1 + 0x10) <= local_8) {
      return 0;
    }
    if (*(int *)(param_1 + 0xc0) + local_8 * 8 == param_2) break;
    local_8 = local_8 + 1;
  }
  return *(int *)(*(int *)(param_1 + 0x20) + 4) + local_8 * 8;
}

