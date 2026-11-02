/* FUN_00481d00 @ 00481d00 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00481d00(byte *param_1)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  int *local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = *(int **)(param_1 + 0xc4);
  if (*(int *)(param_1 + 200) != 0) {
    FUN_00481af0((int)param_1);
  }
  if (local_8 == (int *)0x0) {
    FUN_004823a0((undefined4 *)(param_1 + 0x5c));
    FUN_004824a0(0x4c63f8);
    FUN_00481de0(param_1,0);
  }
  else {
    sVar1 = FUN_00484790(local_8);
    if (sVar1 != 0) {
      (*(code *)local_8[0xe])(local_8[0xf]);
      __chkesp();
    }
    if (*(int *)(param_1 + 200) == 0) {
      FUN_00480a40((int)param_1);
    }
    FUN_00481de0(param_1,2);
  }
  local_8 = (int *)0x481dcd;
  __chkesp();
  return;
}

