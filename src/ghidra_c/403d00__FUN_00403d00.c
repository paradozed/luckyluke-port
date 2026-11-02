/* FUN_00403d00 @ 00403d00 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00403d00(short param_1)

{
  int iVar1;
  undefined4 *puVar2;
  longlong lVar3;
  undefined4 local_4c [16];
  int local_c;
  undefined4 local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((DAT_004d1d64 != 0) && (DAT_004d1cc4 != -1)) {
    local_c = (int)param_1;
    lVar3 = __ftol();
    local_8 = (undefined4)lVar3;
    FUN_00402800(*(void **)(&DAT_004d1ce0 + DAT_004d1ccc * 4),DAT_004d1cc8,DAT_004d1cc4,local_8);
  }
  local_8 = 0x403d7f;
  __chkesp();
  return;
}

