/* FUN_004542c0 @ 004542c0 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __cdecl FUN_004542c0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  undefined1 local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((((param_1 < 100) && (-100 < param_1)) || ((0x79c < param_1 && (param_1 < 0x864)))) ||
     ((0xf9c < param_1 && (param_1 < 0x1064)))) {
    local_8 = 1;
  }
  else {
    local_8 = 0;
  }
  return CONCAT31(0xcccccc,local_8);
}

