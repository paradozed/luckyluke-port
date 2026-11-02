/* FUN_0041b220 @ 0041b220 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041b220(int param_1,void *param_2)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_48 [16];
  int local_8;
  
  puVar5 = local_48;
  for (iVar4 = 0x11; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  iVar4 = FUN_00407580(param_1);
  local_8 = **(int **)(iVar4 + 8);
  sVar1 = FUN_004074b0(param_2,4);
  sVar2 = FUN_004074b0(param_2,3);
  sVar3 = FUN_004074b0(param_2,2);
  FUN_004192c0(local_8,sVar3,sVar2,sVar1);
  local_8 = 0x41b28b;
  __chkesp();
  return;
}

