/* FUN_00477b30 @ 00477b30 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00477b30(ushort *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  uint local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 == (ushort *)0x0) {
    FUN_00497610((byte *)"Failed File: %s Line:%d\n");
  }
  else {
    local_8 = local_8 & 0xffff0000;
    while ((local_8 & 0xffff) < (uint)*param_1) {
      if (*(int *)(param_1 + (local_8 & 0xffff) * 2 + 2) != -0x22222223) {
        FUN_00495280(*(void **)(param_1 + (local_8 & 0xffff) * 2 + 2));
      }
      local_8 = CONCAT22(local_8._2_2_,(short)local_8 + 1);
    }
    if (param_1 != (ushort *)0xdddddddd) {
      FUN_00495280(param_1);
    }
  }
  local_8 = 0x477be9;
  __chkesp();
  return;
}

