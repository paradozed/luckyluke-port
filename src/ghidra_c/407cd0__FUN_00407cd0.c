/* FUN_00407cd0 @ 00407cd0 */
/* decompiled from Lucky.exe (Game.run) */


uint __cdecl
FUN_00407cd0(int param_1,int param_2,int param_3,undefined4 param_4,int param_5,int param_6,
            int param_7,short param_8)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_44 [16];
  
  puVar3 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (param_7 < param_3) {
    if ((((param_5 + param_8 < param_1) &&
         (uVar1 = (uint)param_8, param_1 <= (int)(param_5 - uVar1))) ||
        ((uVar1 = param_7 + param_8, (int)uVar1 < param_3 && (param_7 - param_8 <= param_3)))) ||
       ((uVar1 = (uint)param_8, (int)(param_6 + uVar1) < param_2 &&
        (uVar1 = param_6 - param_8, param_2 <= (int)uVar1)))) {
      uVar1 = uVar1 & 0xffffff00;
    }
    else {
      uVar1 = CONCAT31((int3)(uVar1 >> 8),1);
    }
  }
  else if ((((param_5 + param_8 < param_1) &&
            (uVar1 = (uint)param_8, param_1 <= (int)(param_5 - uVar1))) ||
           ((uVar1 = param_7 + param_8, param_3 < (int)uVar1 && (param_3 <= param_7 - param_8)))) ||
          ((uVar1 = (uint)param_8, (int)(param_6 + uVar1) < param_2 &&
           (uVar1 = param_6 - param_8, param_2 <= (int)uVar1)))) {
    uVar1 = uVar1 & 0xffffff00;
  }
  else {
    uVar1 = CONCAT31((int3)(uVar1 >> 8),1);
  }
  return uVar1;
}

