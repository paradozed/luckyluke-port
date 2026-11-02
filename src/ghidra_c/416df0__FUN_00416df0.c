/* FUN_00416df0 @ 00416df0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00416df0(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_60 [16];
  int local_20;
  int local_1c [5];
  undefined4 uStack_8;
  
  puVar3 = local_60;
  for (iVar2 = 0x17; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_20 = **(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  FUN_0047fbe0(local_20,local_1c);
  FUN_00416e60(local_20,local_1c);
  uStack_8 = 0x416e51;
  __chkesp();
  return;
}

