/* FUN_0040ef40 @ 0040ef40 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040ef40(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  int local_c;
  int local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = FUN_00407580(param_1);
  local_c = **(int **)(local_8 + 8);
  if (*(int *)(local_c + 0xc4) != 0) {
    FUN_004851b0(local_c);
  }
  local_8 = 0x40ef93;
  __chkesp();
  return;
}

