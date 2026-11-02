/* FUN_004436c0 @ 004436c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004436c0(char *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  char *local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = DAT_004e8564;
  do {
    if (local_8 == (char *)0x0) {
LAB_0044372d:
      local_8 = (char *)0x44373a;
      __chkesp();
      return;
    }
    iVar1 = _strcmp(local_8,param_1);
    if (iVar1 == 0) {
      if (*(int *)(local_8 + 0x2c) != 0) {
        (**(code **)(local_8 + 0x2c))();
        __chkesp();
      }
      FUN_00443740(local_8);
      goto LAB_0044372d;
    }
    local_8 = *(char **)(local_8 + 0x34);
  } while( true );
}

