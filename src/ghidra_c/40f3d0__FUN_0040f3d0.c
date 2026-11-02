/* FUN_0040f3d0 @ 0040f3d0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040f3d0(int param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_4c [16];
  int local_c;
  int local_8;
  
  puVar3 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = FUN_00407580(param_1);
  DAT_004e8474 = **(int **)(local_8 + 8);
  local_c = DAT_004e8474;
  sVar1 = FUN_004074b0(param_2,2);
  FUN_00478980(local_c,(int)sVar1);
  local_8 = 0x40f431;
  __chkesp();
  return;
}

