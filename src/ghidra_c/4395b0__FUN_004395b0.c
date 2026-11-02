/* FUN_004395b0 @ 004395b0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004395b0(int param_1)

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
  local_8 = (int *)FUN_00494840(8);
  if (local_8 != (int *)0x0) {
    iVar1 = FUN_00494840(param_1 << 2);
    *local_8 = iVar1;
    if (*local_8 == 0) {
      FUN_00495280(local_8);
    }
    else {
      _memset((void *)*local_8,0,param_1 << 2);
      local_8[1] = param_1;
    }
  }
  local_8 = (int *)0x43963b;
  __chkesp();
  return;
}

