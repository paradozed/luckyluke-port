/* FUN_00417b30 @ 00417b30 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00417b30(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_54 [16];
  undefined4 *local_14;
  int local_10;
  int local_c;
  byte *local_8;
  
  puVar2 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 != (int *)0x0) {
    if (param_1 != (int *)0xdddddddd) {
      local_8 = (byte *)*param_1;
      if ((local_8 == (byte *)0x0) || (10000 < *(uint *)(local_8 + 0x10))) goto LAB_00417c86;
      if ((*(int *)(local_8 + 0xd8) != 0) && (100000 < *(uint *)(local_8 + 0xd8))) {
        local_c = **(int **)(local_8 + 0xd8);
        FUN_00486d00(local_c,(int)local_8);
      }
      if (*(int *)(local_8 + 0xdc) != 0) {
        local_10 = **(int **)(local_8 + 0xdc);
        FUN_00486d00((int)local_8,local_10);
      }
      if ((*local_8 & 1) != 0) {
        FUN_0047f190(local_8);
      }
      FUN_004179e0();
      local_14 = *(undefined4 **)(local_8 + 0xe4);
      if ((local_14 != (undefined4 *)0x0) && (((uint)local_14 & 0xff000000) == 0)) {
        (*(code *)*local_14)(local_14);
        __chkesp();
      }
      if (local_8 != (byte *)0x0) {
        _memset(local_8,0,0xe8);
        FUN_00439c30(local_8);
        local_8 = (byte *)0x0;
      }
    }
    if (param_1 != (int *)0x0) {
      FUN_00439c30(param_1);
    }
  }
LAB_00417c86:
  local_8 = (byte *)0x417c93;
  __chkesp();
  return;
}

