/* FUN_0046df80 @ 0046df80 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046df80(int *param_1,int *param_2)

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
  FUN_0046df00(param_1,param_2);
  if (param_1 != (int *)0xdddddddd) {
    FUN_00495280(param_1);
  }
  uStack_8 = 0x46dfca;
  __chkesp();
  return;
}

