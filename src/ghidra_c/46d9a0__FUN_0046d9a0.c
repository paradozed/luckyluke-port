/* FUN_0046d9a0 @ 0046d9a0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046d9a0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_54 [16];
  int local_14;
  int local_10;
  void *local_c;
  int local_8;
  
  puVar2 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (void *)FUN_00494c40(0x1000,1);
  local_10 = (int)local_c + 0xffc;
  local_8 = FUN_0046d8e0(param_1);
  if (local_8 == 1) {
    if (local_c != (void *)0xdddddddd) {
      FUN_00495280(local_c);
    }
  }
  else {
    local_14 = FUN_0046de90(DAT_004f2288,0x1c);
    *(void **)(local_14 + 0x18) = local_c;
    *(int *)(local_14 + 0xc) = local_8;
    *(undefined4 *)(local_14 + 0x10) = 2;
  }
  local_8 = 0x46da4a;
  __chkesp();
  return;
}

