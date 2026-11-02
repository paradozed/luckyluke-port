/* FUN_00414e10 @ 00414e10 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00414e10(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_54 [16];
  int local_14;
  int local_10;
  short local_c;
  int local_8;
  
  puVar3 = local_54;
  for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = *(int *)(DAT_004e8820 + 4 + sVar1 * 4);
  local_c = FUN_004074b0(param_2,3);
  local_10 = FUN_0046e8d0((int)local_c);
  sVar1 = FUN_004074b0(param_2,4);
  local_14 = *(int *)(*(int *)(local_10 + 8) + 4 + sVar1 * 0xc);
  FUN_0046e220(local_14,local_8);
  local_8 = 0x414e9a;
  __chkesp();
  return;
}

