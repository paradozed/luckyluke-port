/* FUN_0045d7a0 @ 0045d7a0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0045d7a0(uint param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  uint local_c;
  undefined4 local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = CONCAT22(local_8._2_2_,*(short *)(param_2 + 8) * 8 + 0x30);
  local_c = param_1 & 0xffff;
  if (local_c == 0) {
    FUN_004266b0();
  }
  else if (local_c == 1) {
    if (((DAT_004f2750 & 0x80) != 0) && (DAT_004e8976 != 0)) {
      DAT_004e8976 = DAT_004e8976 - 1;
    }
    if (((DAT_004f2750 & 0x20) != 0) &&
       ((&PTR_s_abi_boss_004be11c)[DAT_004e8976] != (undefined *)0x0)) {
      DAT_004e8976 = DAT_004e8976 + 1;
    }
    FUN_004266b0();
  }
  local_8 = 0x45d8b8;
  __chkesp();
  return;
}

