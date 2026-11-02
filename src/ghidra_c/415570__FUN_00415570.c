/* FUN_00415570 @ 00415570 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00415570(undefined4 param_1,void *param_2)

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
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = *(int *)(&DAT_004f1e40 + sVar1 * 4);
  local_c = **(int **)(local_8 + 8);
  sVar1 = FUN_004074b0(param_2,3);
  if (sVar1 == 0) {
    *(undefined ***)(local_c + 0xd0) = &PTR_FUN_004c6494;
  }
  else {
    *(undefined ***)(local_c + 0xd0) = &PTR_FUN_004c6520;
  }
  local_8 = 0x4155e6;
  __chkesp();
  return;
}

