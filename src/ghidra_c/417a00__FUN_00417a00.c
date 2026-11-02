/* FUN_00417a00 @ 00417a00 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00417a00(int *param_1)

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
      if (local_8 == (byte *)0x0) goto LAB_00417b11;
      if (*(int *)(local_8 + 0xd8) != 0) {
        if (*(int *)(local_8 + 0xd8) == -0x33333334) goto LAB_00417b11;
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
      if (local_14 != (undefined4 *)0x0) {
        (*(code *)*local_14)(local_14);
        __chkesp();
      }
    }
    if (param_1 != (int *)0x0) {
      FUN_00439c30(param_1);
    }
  }
LAB_00417b11:
  local_8 = (byte *)0x417b1e;
  __chkesp();
  return;
}

