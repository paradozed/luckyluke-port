/* FUN_004163b0 @ 004163b0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004163b0(int param_1,void *param_2)

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
  local_c = FUN_00417220(**(int **)(local_8 + 8));
  sVar1 = FUN_004074b0(param_2,2);
  FUN_00470a30(local_c,sVar1);
  local_8 = 0x41640b;
  __chkesp();
  return;
}

