/* FUN_00410310 @ 00410310 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00410310(int param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_64 [16];
  int local_24;
  int local_20;
  int local_1c [3];
  int local_10;
  undefined4 uStack_8;
  
  puVar3 = local_64;
  for (iVar2 = 0x18; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_20 = FUN_00407580(param_1);
  local_24 = **(int **)(local_20 + 8);
  FUN_00411200(local_24,local_1c);
  sVar1 = FUN_004074b0(param_2,2);
  local_1c[0] = (int)sVar1;
  sVar1 = FUN_004074b0(param_2,3);
  local_10 = (int)sVar1;
  FUN_00411000(local_24,local_1c);
  uStack_8 = 0x41038b;
  __chkesp();
  return;
}

