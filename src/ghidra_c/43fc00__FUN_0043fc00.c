/* FUN_0043fc00 @ 0043fc00 */
/* decompiled from Lucky.exe (Game.run) */


uint __cdecl FUN_0043fc00(uint param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  bool bVar5;
  undefined4 local_48 [17];
  
  uVar2 = 0xcccccccc;
  puVar4 = local_48;
  for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  if ((param_1 < 2) || (9 < param_1)) {
    if (param_1 < 10) {
      if (param_1 == 0) {
        param_1 = uVar2;
        if (DAT_004f5b10 != 0) {
          return 0xcccccc01;
        }
      }
      else {
        bVar5 = param_1 == 1;
        param_1 = uVar2;
        if ((bVar5) && (DAT_004f5b14 != 0)) {
          return 0xcccccc01;
        }
      }
    }
    else {
      piVar1 = &DAT_004e8500 + param_1;
      param_1 = uVar2;
      if (*piVar1 != 0) {
        return 0xcccccc01;
      }
    }
  }
  else if ((&DAT_004e8510)[param_1] != 0) {
    return CONCAT31((int3)(param_1 >> 8),1);
  }
  return param_1 & 0xffffff00;
}

