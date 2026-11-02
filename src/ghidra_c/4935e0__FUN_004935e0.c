/* FUN_004935e0 @ 004935e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004935e0(int param_1,uint param_2,short param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  longlong lVar4;
  undefined4 local_54 [16];
  int local_14;
  int local_10;
  int local_8;
  
  puVar3 = local_54;
  for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = param_1;
  local_10 = (int)DAT_004e8aec - (int)DAT_004c6df8;
  local_14 = (int)param_3 - (int)DAT_004c6df8;
  lVar4 = __ftol();
  uVar1 = (undefined2)((uint)*(undefined4 *)(&DAT_00508a20 + (short)lVar4 * 4) >> 8);
  if (local_8 != 0) {
    if ((param_2 & 1) != 0) {
      *(undefined2 *)(local_8 + 0x10) = uVar1;
    }
    if ((param_2 & 2) != 0) {
      *(undefined2 *)(local_8 + 0x12) = uVar1;
    }
  }
  return;
}

