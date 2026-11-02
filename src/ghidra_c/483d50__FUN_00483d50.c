/* FUN_00483d50 @ 00483d50 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00483d50(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  undefined4 *local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = (undefined4 *)(param_1 + 0xc);
  IsBadWritePtr((LPVOID)*local_8,1);
  __chkesp();
  local_8 = (undefined4 *)0x483da2;
  __chkesp();
  return;
}

