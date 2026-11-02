/* FUN_00439930 @ 00439930 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00439930(SIZE_T param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  int *local_c;
  int *local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = (int *)FUN_00494c40(1,8);
  if (local_8 != (int *)0x0) {
    HeapCreate(1,param_1,0);
    iVar1 = __chkesp();
    *local_8 = iVar1;
    if (*local_8 == 0) {
      FUN_00495280(local_8);
    }
    else {
      local_8[1] = 0;
      if (DAT_004e84e8 == (int *)0x0) {
        DAT_004e84e8 = local_8;
      }
      else {
        for (local_c = DAT_004e84e8; local_c[1] != 0; local_c = (int *)local_c[1]) {
        }
        local_c[1] = (int)local_8;
      }
    }
  }
  local_8 = (int *)0x4399ea;
  __chkesp();
  return;
}

