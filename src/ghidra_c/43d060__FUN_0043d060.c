/* FUN_0043d060 @ 0043d060 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043d060(int *param_1)

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
  if (param_1 != (int *)0x0) {
    if ((*param_1 != 0) && (*param_1 != -0x22222223)) {
      FUN_00495280((void *)*param_1);
    }
    if ((param_1[1] != 0) && (param_1[1] != -0x22222223)) {
      FUN_00495280((void *)param_1[1]);
    }
    if (param_1 != (int *)0xdddddddd) {
      FUN_00495280(param_1);
    }
  }
  uStack_8 = 0x43d0e7;
  __chkesp();
  return;
}

