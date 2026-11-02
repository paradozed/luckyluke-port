/* FUN_00410390 @ 00410390 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00410390(int param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_64 [16];
  int local_24;
  int local_20;
  undefined4 local_1c [2];
  int local_14;
  int local_8;
  
  puVar3 = local_64;
  for (iVar2 = 0x18; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_20 = FUN_00407580(param_1);
  local_24 = **(int **)(local_20 + 8);
  FUN_00411200(local_24,local_1c);
  sVar1 = FUN_004074b0(param_2,2);
  local_14 = (int)sVar1;
  sVar1 = FUN_004074b0(param_2,3);
  local_8 = (int)sVar1;
  FUN_00411000(local_24,local_1c);
  local_8 = 0x41040b;
  __chkesp();
  return;
}

