/* FUN_004385e0 @ 004385e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004385e0(char *param_1,int param_2)

{
  size_t sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_4c [16];
  int *local_c;
  int *local_8;
  
  puVar3 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = (int *)FUN_00494c40(0x3c,1);
  if (local_8 != (int *)0x0) {
    iVar2 = FUN_00494c40(param_2,1);
    *local_8 = iVar2;
    if (*local_8 == 0) {
      if (local_8 != (int *)0xdddddddd) {
        FUN_00495280(local_8);
      }
    }
    else {
      local_8[0xc] = 0;
      local_8[0xd] = 0;
      local_8[2] = param_2;
      local_8[1] = param_2;
      local_8[0xe] = 0;
      sVar1 = _strlen(param_1);
      FUN_00497690(local_8 + 4,(undefined4 *)param_1,sVar1 + 1);
      if (DAT_004e84d8 == (int *)0x0) {
        DAT_004e84d8 = local_8;
      }
      else {
        for (local_c = DAT_004e84d8; local_c[0xe] != 0; local_c = (int *)local_c[0xe]) {
        }
        local_c[0xe] = (int)local_8;
      }
      FUN_004390e0((int)local_8);
    }
  }
  local_8 = (int *)0x4386f5;
  __chkesp();
  return;
}

