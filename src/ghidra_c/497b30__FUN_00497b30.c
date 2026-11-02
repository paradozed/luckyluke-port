/* FUN_00497b30 @ 00497b30 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __cdecl FUN_00497b30(int *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  if ((param_1[3] & 0x40U) == 0) {
    if ((param_1 == (int *)0x0) &&
       (iVar2 = FUN_004999a0(2,0x4baed4,0x77,0,(byte *)"str != NULL"), iVar2 == 1)) {
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    if ((param_1[3] & 0x83U) != 0) {
      local_8 = FUN_004990b0(param_1);
      FUN_0049fdb0(param_1);
      iVar2 = FUN_0049fcc0(param_1[4]);
      if (iVar2 < 0) {
        local_8 = 0xffffffff;
      }
      else if (param_1[7] != 0) {
        FUN_004952a0((void *)param_1[7],2);
        param_1[7] = 0;
      }
    }
    param_1[3] = 0;
  }
  else {
    param_1[3] = 0;
    local_8 = 0xffffffff;
  }
  return local_8;
}

