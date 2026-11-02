/* FUN_004079a0 @ 004079a0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004079a0(int param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_54 [16];
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  puVar3 = local_54;
  for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,3);
  local_8 = (uint)sVar1;
  local_c = FUN_00407580(param_1);
  local_10 = **(int **)(local_c + 8);
  sVar1 = FUN_004074b0(param_2,2);
  local_14 = **(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  FUN_00407700(local_10,local_14,local_8);
  local_8 = 0x407a1b;
  __chkesp();
  return;
}

