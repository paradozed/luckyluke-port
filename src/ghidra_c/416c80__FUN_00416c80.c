/* FUN_00416c80 @ 00416c80 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00416c80(int param_1,void *param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  int local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = FUN_00407580(param_1);
  uVar1 = FUN_004074b0(param_2,2);
  *(undefined2 *)(*(int *)(local_8 + 8) + 0x3c) = uVar1;
  local_8 = 0x416cc4;
  __chkesp();
  return;
}

