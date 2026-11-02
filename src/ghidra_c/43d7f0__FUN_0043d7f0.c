/* FUN_0043d7f0 @ 0043d7f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043d7f0(int param_1,int param_2,int param_3)

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
  local_8 = (int *)FUN_00494c40(0x20,1);
  if (local_8 != (int *)0x0) {
    _memset(local_8,0,0x20);
    iVar1 = FUN_0043c4b0(250.0,125.0,25.0);
    *local_8 = iVar1;
    if (*local_8 != 0) {
      local_8[1] = param_1;
      local_8[2] = param_2;
      local_8[3] = param_3;
      local_8[4] = 0;
      local_8[5] = 0;
      local_8[6] = 0;
      local_8[7] = 0;
    }
  }
  local_8 = (int *)0x43d8ac;
  __chkesp();
  return;
}

