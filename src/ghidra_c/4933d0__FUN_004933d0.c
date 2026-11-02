/* FUN_004933d0 @ 004933d0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004933d0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  longlong lVar3;
  undefined4 local_58 [16];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 uStack_c;
  int local_8;
  
  puVar2 = local_58;
  for (iVar1 = 0x15; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = param_1;
  local_10 = param_2;
  uStack_c = 0;
  local_18 = DAT_00508e28;
  local_14 = 0;
  lVar3 = __ftol();
  *(int *)(local_8 + 0xc) = (int)lVar3;
  return;
}

