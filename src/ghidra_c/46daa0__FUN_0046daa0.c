/* FUN_0046daa0 @ 0046daa0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046daa0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  iVar1 = FUN_0046da50(param_1);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 1;
  }
  local_8 = 0x46daed;
  __chkesp();
  return;
}

