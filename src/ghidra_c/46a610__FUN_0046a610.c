/* FUN_0046a610 @ 0046a610 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046a610(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (*param_1 != *param_3) {
    if ((*param_1 < *param_3) && (*param_1 = *param_1 + (*param_2 >> 8), *param_3 <= *param_1)) {
      *param_1 = *param_3;
    }
    else if ((*param_3 < *param_1) && (*param_1 = *param_1 - (*param_2 >> 8), *param_1 <= *param_3))
    {
      *param_1 = *param_3;
    }
    else {
      FUN_0046a560(param_2,param_3 + 1);
    }
  }
  uStack_8 = 0x46a6d1;
  __chkesp();
  return;
}

