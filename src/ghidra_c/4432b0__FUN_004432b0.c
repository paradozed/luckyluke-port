/* FUN_004432b0 @ 004432b0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004432b0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int *local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 != (int *)0x0) {
    if (*param_1 != 0) {
      FUN_00497b30((int *)*param_1);
    }
    local_8 = (int *)param_1[0x84];
    while (local_8 != (int *)0x0) {
      param_1[0x84] = *local_8;
      if (local_8 != (int *)0xdddddddd) {
        FUN_00495280(local_8);
      }
      local_8 = (int *)param_1[0x84];
    }
    if (param_1 != (int *)0xdddddddd) {
      FUN_00495280(param_1);
    }
  }
  local_8 = (int *)0x443349;
  __chkesp();
  return;
}

