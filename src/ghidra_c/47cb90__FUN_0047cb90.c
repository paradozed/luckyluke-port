/* FUN_0047cb90 @ 0047cb90 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047cb90(int *param_1,int *param_2,int *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_54 [20];
  
  puVar3 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  iVar1 = *param_2;
  *param_1 = *param_1 + *param_2;
  iVar2 = *param_3 - *param_1;
  if (*param_2 < param_4) {
    if (-param_4 < *param_2) {
      if (*param_1 <= *param_3 - param_4) {
        *param_2 = *param_2 + param_4;
      }
      if (*param_3 + param_4 <= *param_1) {
        *param_2 = *param_2 - param_4;
      }
    }
    else {
      iVar1 = -(*param_2 * (iVar1 / param_4 + -1)) / 2;
      if (iVar1 < iVar2) {
        *param_2 = *param_2 + param_4;
      }
      if (iVar2 <= (iVar1 + *param_2) - param_4) {
        *param_2 = *param_2 - param_4;
      }
    }
  }
  else {
    iVar1 = (*param_2 * (iVar1 / param_4 + 1)) / 2;
    if (iVar2 < iVar1) {
      *param_2 = *param_2 - param_4;
    }
    if (iVar1 + *param_2 + param_4 <= iVar2) {
      *param_2 = *param_2 + param_4;
    }
  }
  return;
}

