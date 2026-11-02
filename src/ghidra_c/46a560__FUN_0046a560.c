/* FUN_0046a560 @ 0046a560 */
/* decompiled from Lucky.exe (Game.run) */


uint __cdecl FUN_0046a560(int *param_1,int *param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_44 [16];
  
  puVar4 = local_44;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  if (*param_1 == param_2[1]) {
    uVar1 = CONCAT31((int3)((uint)param_1 >> 8),1);
  }
  else if ((*param_1 < param_2[1]) && (*param_1 = *param_1 + *param_2, param_2[1] <= *param_1)) {
    iVar3 = param_2[1];
    *param_1 = iVar3;
    uVar1 = CONCAT31((int3)((uint)iVar3 >> 8),1);
  }
  else {
    piVar2 = (int *)*param_1;
    if ((param_2[1] < *param_1) &&
       (*param_1 = *param_1 - *param_2, piVar2 = param_2, *param_1 <= param_2[1])) {
      *param_1 = param_2[1];
      return CONCAT31((int3)((uint)param_2 >> 8),1);
    }
    uVar1 = (uint)piVar2 & 0xffffff00;
  }
  return uVar1;
}

