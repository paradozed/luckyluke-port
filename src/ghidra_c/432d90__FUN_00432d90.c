/* FUN_00432d90 @ 00432d90 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00432d90(char *param_1,uint *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  void *local_c;
  undefined4 local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 != (char *)0x0) {
    FUN_00458ec0();
    local_c = (void *)FUN_00431fe0(param_1,param_2);
    if (local_c != (void *)0x0) {
      FUN_00458ec0();
      local_8 = FUN_00443cc0((int)local_c,DAT_004e8488,DAT_004e848c);
      FUN_00458ec0();
      if (local_c != (void *)0xdddddddd) {
        FUN_00495280(local_c);
      }
    }
  }
  local_8 = 0x432e3b;
  __chkesp();
  return;
}

