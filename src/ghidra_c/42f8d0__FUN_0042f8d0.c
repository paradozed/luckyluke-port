/* FUN_0042f8d0 @ 0042f8d0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0042f8d0(int *param_1,undefined1 *param_2)

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
  while (local_8 = FUN_00498340(param_1), local_8 != 0xd) {
    if (local_8 == 0xffffffff) goto LAB_0042f92e;
    *param_2 = (undefined1)local_8;
    param_2 = param_2 + 1;
  }
  *param_2 = 0;
  FUN_00498340(param_1);
LAB_0042f92e:
  local_8 = 0x42f93b;
  __chkesp();
  return;
}

