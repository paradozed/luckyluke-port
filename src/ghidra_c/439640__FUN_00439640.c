/* FUN_00439640 @ 00439640 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00439640(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  void *local_10;
  void *local_c;
  uint local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (*param_1 != 0) {
    for (local_8 = 0; local_8 < (uint)param_1[1]; local_8 = local_8 + 1) {
      if (*(int *)(*param_1 + local_8 * 4) != 0) {
        local_c = *(void **)(*param_1 + local_8 * 4);
        while (local_c != (void *)0x0) {
          local_10 = *(void **)((int)local_c + 0xc);
          FUN_00495280(local_c);
          local_c = local_10;
        }
      }
    }
    FUN_00495280((void *)*param_1);
  }
  FUN_00495280(param_1);
  local_8 = 0x4396e7;
  __chkesp();
  return;
}

