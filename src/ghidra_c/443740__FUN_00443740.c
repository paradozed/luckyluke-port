/* FUN_00443740 @ 00443740 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00443740(void *param_1)

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
  if (param_1 == DAT_004e8564) {
    DAT_004e8564 = *(void **)((int)param_1 + 0x34);
  }
  if (param_1 == DAT_004e8568) {
    DAT_004e8568 = *(void **)((int)param_1 + 0x30);
  }
  if (*(int *)((int)param_1 + 0x30) != 0) {
    *(undefined4 *)(*(int *)((int)param_1 + 0x30) + 0x34) = *(undefined4 *)((int)param_1 + 0x34);
  }
  if (*(int *)((int)param_1 + 0x34) != 0) {
    *(undefined4 *)(*(int *)((int)param_1 + 0x34) + 0x30) = *(undefined4 *)((int)param_1 + 0x30);
  }
  if (param_1 != (void *)0xdddddddd) {
    FUN_00495280(param_1);
  }
  uStack_8 = 0x4437d8;
  __chkesp();
  return;
}

