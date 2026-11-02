/* FUN_0047ea50 @ 0047ea50 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047ea50(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_0047e8d0(param_1);
  if (*(int *)(param_1 + 8) == 0) {
    if (*(uint *)(param_1 + 0x3c) < 10000) {
      *(int *)(param_1 + 0x3c) = param_1 + *(int *)(param_1 + 0x3c);
    }
  }
  else {
    iVar1 = *(int *)(param_1 + 8);
    if (*(uint *)(iVar1 + 0x3c) < 10000) {
      *(int *)(param_1 + 0x3c) = iVar1 + *(int *)(iVar1 + 0x3c);
    }
    else {
      *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(iVar1 + 0x3c);
    }
  }
  local_8 = 0x47ead9;
  __chkesp();
  return;
}

