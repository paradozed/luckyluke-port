/* FUN_00421930 @ 00421930 */
/* decompiled from Lucky.exe (Game.run) */


void __fastcall FUN_00421930(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  void *local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined2 *)((int)param_1 + 0x72) = *(undefined2 *)(*(int *)((int)param_1 + 0x84) + 10);
  *(undefined4 *)((int)param_1 + 0x74) = 1;
  if (*(short *)((int)param_1 + 0x72) == -1) {
    local_8 = param_1;
    FUN_00417250(param_1,2,1);
    *(undefined4 *)((int)local_8 + 0x74) = 0;
  }
  local_8 = (void *)0x42199e;
  __chkesp();
  return;
}

