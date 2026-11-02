/* FUN_0046e030 @ 0046e030 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046e030(int *param_1)

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
  while (param_1[1] != 0) {
    FUN_0046df80((int *)param_1[1],param_1);
  }
  if (param_1 != (int *)0xdddddddd) {
    FUN_00495280(param_1);
  }
  uStack_8 = 0x46e088;
  __chkesp();
  return;
}

