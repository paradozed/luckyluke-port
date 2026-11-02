/* FUN_00416470 @ 00416470 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00416470(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_4c [16];
  int local_c;
  int *local_8;
  
  puVar3 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = *(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  local_c = FUN_00417220(*local_8);
  sVar1 = FUN_004074b0(param_2,3);
  FUN_00470b00(local_c,sVar1);
  local_8 = (int *)0x4164d7;
  __chkesp();
  return;
}

