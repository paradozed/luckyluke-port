/* FUN_0047c530 @ 0047c530 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047c530(int param_1,int param_2,uint param_3,int *param_4,int *param_5)

{
  short sVar1;
  short sVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_4c [18];
  
  puVar4 = local_4c;
  for (iVar3 = 0x12; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  if (param_3 == 0) {
    *param_4 = param_1;
    *param_5 = param_2;
  }
  else {
    sVar1 = *(short *)(&DAT_004c6534 + (param_3 + 0x100 & 0x3ff) * 2);
    sVar2 = *(short *)(&DAT_004c6534 + (param_3 & 0x3ff) * 2);
    *param_4 = param_1 * sVar1 - param_2 * sVar2 >> 0xc;
    *param_5 = param_1 * sVar2 + param_2 * sVar1 >> 0xc;
  }
  return;
}

