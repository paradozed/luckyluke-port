/* FUN_0046cbd0 @ 0046cbd0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046cbd0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_2 < *param_1) {
    *param_1 = *param_1 - param_3;
    if (*param_1 < param_2) {
      *param_1 = param_2;
    }
  }
  else if ((*param_1 < param_2) && (*param_1 = *param_1 + param_3, param_2 < *param_1)) {
    *param_1 = param_2;
  }
  return;
}

