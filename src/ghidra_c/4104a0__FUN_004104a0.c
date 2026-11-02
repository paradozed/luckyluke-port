/* FUN_004104a0 @ 004104a0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004104a0(int param_1,void *param_2)

{
  undefined2 uVar1;
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
  local_c = *(int *)(local_8 + 8);
  uVar1 = FUN_004074b0(param_2,2);
  *(char *)(local_c + 0x16) = (char)uVar1;
  local_8 = 0x4104e9;
  __chkesp();
  return;
}

