/* FUN_00442fb0 @ 00442fb0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00442fb0(byte *param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_4c [16];
  int local_c;
  
  puVar3 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  bVar1 = false;
  while (*param_1 != 0) {
    if ((((*param_1 < 0x21) && (*param_1 != 0)) || (bVar1)) || (*param_1 == 0x3b)) {
      local_c = 0;
      if (*param_1 == 0x3b) {
        bVar1 = true;
      }
      for (; param_1[local_c + 1] != 0; local_c = local_c + 1) {
        param_1[local_c] = param_1[local_c + 1];
      }
      param_1[local_c] = 0;
    }
    else {
      param_1 = param_1 + 1;
    }
  }
  return;
}

