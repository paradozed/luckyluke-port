/* FUN_0043c230 @ 0043c230 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043c230(void *param_1)

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
  if (param_1 != (void *)0x0) {
    if ((*(int *)((int)param_1 + 0x10) != 0) && (*(int *)((int)param_1 + 0x10) != -0x22222223)) {
      FUN_00495280(*(void **)((int)param_1 + 0x10));
    }
    if ((*(int *)((int)param_1 + 0xc) != 0) && (*(int *)((int)param_1 + 0xc) != -0x22222223)) {
      FUN_00495280(*(void **)((int)param_1 + 0xc));
    }
    if ((*(int *)((int)param_1 + 8) != 0) && (*(int *)((int)param_1 + 8) != -0x22222223)) {
      FUN_00495280(*(void **)((int)param_1 + 8));
    }
    if ((*(int *)((int)param_1 + 0x14) != 0) && (*(int *)((int)param_1 + 0x14) != -0x22222223)) {
      FUN_00495280(*(void **)((int)param_1 + 0x14));
    }
    if ((*(int *)((int)param_1 + 0x5c) != 0) && (*(int *)((int)param_1 + 0x5c) != -0x22222223)) {
      FUN_00495280(*(void **)((int)param_1 + 0x5c));
    }
    if (param_1 != (void *)0xdddddddd) {
      FUN_00495280(param_1);
    }
  }
  uStack_8 = 0x43c329;
  __chkesp();
  return;
}

