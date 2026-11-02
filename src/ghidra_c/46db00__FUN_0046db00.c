/* FUN_0046db00 @ 0046db00 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046db00(int param_1)

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
    *(undefined4 *)(iVar1 + 0x10) = 2;
  }
  local_8 = 0x46db4d;
  __chkesp();
  return;
}

