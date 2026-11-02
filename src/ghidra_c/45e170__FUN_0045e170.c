/* FUN_0045e170 @ 0045e170 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0045e170(ushort *param_1)

{
  ushort uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  ushort *local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = (ushort *)(*(int *)(param_1 + 4) + (uint)*param_1 * 8);
  param_1[3] = param_1[3] | (ushort)DAT_004f2750;
  if (param_1[3] == *local_8) {
    if (*(int *)(local_8 + 2) != 0) {
      (**(code **)(local_8 + 2))();
      __chkesp();
    }
    if (local_8[4] == 0) {
      *param_1 = 0;
    }
    else {
      *param_1 = *param_1 + 1;
    }
    param_1[2] = 0;
    param_1[3] = 0;
  }
  uVar1 = param_1[2];
  param_1[2] = param_1[2] + 1;
  if (param_1[1] <= uVar1) {
    *param_1 = 0;
    param_1[2] = 0;
    param_1[3] = 0;
  }
  local_8 = (ushort *)0x45e26e;
  __chkesp();
  return;
}

