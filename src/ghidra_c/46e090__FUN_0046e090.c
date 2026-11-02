/* FUN_0046e090 @ 0046e090 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046e090(int *param_1,undefined *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 != (int *)0x0) {
    for (local_8 = *param_1; local_8 != 0; local_8 = *(int *)(local_8 + 4)) {
      (*(code *)param_2)(local_8 + 8);
      __chkesp();
    }
  }
  local_8 = 0x46e0ea;
  __chkesp();
  return;
}

