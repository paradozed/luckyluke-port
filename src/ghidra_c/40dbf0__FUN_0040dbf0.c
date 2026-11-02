/* FUN_0040dbf0 @ 0040dbf0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_0040dbf0(int *param_1,int param_2,int *param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8,int param_9)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar3 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (param_2 == 0) {
    FUN_0040e5f0(*param_1,param_3);
  }
  else {
    if ((param_1[7] != param_2) || (param_1[8] != DAT_004e8abc >> 5)) {
      FUN_0040d950(*param_1,param_2,param_1 + 9);
      param_1[7] = param_2;
      param_1[8] = DAT_004e8abc >> 5;
    }
    piVar2 = param_1 + 9;
    piVar4 = param_3;
    for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar4 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar4 = piVar4 + 1;
    }
  }
  *param_3 = *param_3 + param_4;
  param_3[1] = param_3[1] + param_5;
  param_3[2] = param_3[2] + param_6;
  param_3[3] = param_3[3] + param_7;
  param_3[4] = param_3[4] + param_8;
  param_3[5] = param_3[5] + param_9;
  FUN_0040e410(*param_1,param_3);
  uStack_8 = 0x40dcf6;
  __chkesp();
  return;
}

