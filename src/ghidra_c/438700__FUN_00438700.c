/* FUN_00438700 @ 00438700 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00438700(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  int *local_10;
  void *local_c;
  void *local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_004392f0((int)param_1);
  if (param_1 == DAT_004e84d8) {
    DAT_004e84d8 = (int *)param_1[0xe];
  }
  else {
    for (local_10 = DAT_004e84d8; (int *)local_10[0xe] != param_1; local_10 = (int *)local_10[0xe])
    {
    }
    local_10[0xe] = *(int *)(local_10[0xe] + 0x38);
  }
  if (param_1 != (int *)0x0) {
    if (param_1 == DAT_004e84d0) {
      DAT_004e84d0 = (int *)0x0;
    }
    local_8 = (void *)param_1[0xc];
    while (local_8 != (void *)0x0) {
      local_c = *(void **)((int)local_8 + 4);
      if (local_8 != (void *)0xdddddddd) {
        FUN_00495280(local_8);
      }
      local_8 = local_c;
    }
    if (*param_1 != -0x22222223) {
      FUN_00495280((void *)*param_1);
    }
    if (param_1 != (int *)0xdddddddd) {
      FUN_00495280(param_1);
    }
  }
  local_8 = (void *)0x4387fb;
  __chkesp();
  return;
}

