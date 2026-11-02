/* FUN_00475020 @ 00475020 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00475020(char *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  uint local_c;
  uint local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  for (local_8 = 0; local_8 < 0x14; local_8 = local_8 + 1) {
    iVar1 = _strcmp(param_1,(&PTR_s_abilene_004be118)[local_8]);
    if (iVar1 == 0) {
      for (local_c = 0; local_c < 0x1d; local_c = local_c + 1) {
        if ((byte)(&DAT_004be22c)[local_c] == local_8) goto LAB_0047509e;
      }
    }
  }
LAB_0047509e:
  local_8 = 0x4750ab;
  __chkesp();
  return;
}

