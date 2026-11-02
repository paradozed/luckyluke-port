/* FUN_0047ccc0 @ 0047ccc0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047ccc0(short *param_1,short *param_2,short *param_3,short param_4)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_54 [20];
  
  puVar4 = local_54;
  for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  sVar1 = *param_2;
  *param_1 = *param_1 + *param_2;
  iVar3 = (int)*param_3 - (int)*param_1;
  if (*param_2 < param_4) {
    if (-(int)param_4 < (int)*param_2) {
      if ((int)*param_1 <= (int)*param_3 - (int)param_4) {
        *param_2 = *param_2 + param_4;
      }
      if ((int)*param_3 + (int)param_4 <= (int)*param_1) {
        *param_2 = *param_2 - param_4;
      }
    }
    else {
      iVar2 = -((int)*param_2 * ((int)sVar1 / (int)param_4 + -1)) / 2;
      if (iVar2 < iVar3) {
        *param_2 = *param_2 + param_4;
      }
      if (iVar3 <= (iVar2 + *param_2) - (int)param_4) {
        *param_2 = *param_2 - param_4;
      }
    }
  }
  else {
    iVar2 = ((int)*param_2 * ((int)sVar1 / (int)param_4 + 1)) / 2;
    if (iVar3 < iVar2) {
      *param_2 = *param_2 - param_4;
    }
    if (iVar2 + *param_2 + (int)param_4 <= iVar3) {
      *param_2 = *param_2 + param_4;
    }
  }
  return;
}

