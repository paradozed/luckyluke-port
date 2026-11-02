/* FUN_00410410 @ 00410410 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00410410(int param_1,void *param_2)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_4c [16];
  int local_c;
  int local_8;
  
  puVar4 = local_4c;
  for (iVar3 = 0x12; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_8 = FUN_00407580(param_1);
  local_c = *(int *)(local_8 + 8);
  sVar1 = FUN_004074b0(param_2,2);
  *(int *)(local_c + 4) = (int)sVar1;
  sVar1 = FUN_004074b0(param_2,3);
  *(int *)(local_c + 8) = (int)sVar1;
  sVar1 = FUN_004074b0(param_2,4);
  *(int *)(local_c + 0xc) = (int)sVar1;
  uVar2 = FUN_004074b0(param_2,5);
  *(undefined2 *)(local_c + 0x14) = uVar2;
  local_8 = 0x410493;
  __chkesp();
  return;
}

