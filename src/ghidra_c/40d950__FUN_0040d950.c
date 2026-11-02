/* FUN_0040d950 @ 0040d950 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040d950(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 local_5c [16];
  int local_1c [4];
  int local_c;
  int local_8;
  
  puVar3 = local_5c;
  for (iVar1 = 0x16; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (param_2 == 1) {
    FUN_0047fbe0(param_1,local_1c);
  }
  else {
    FUN_0047fec0(param_1,(short)param_2,local_1c);
  }
  local_1c[0] = local_1c[0] + *(int *)(param_1 + 0x90);
  local_1c[1] = local_1c[1] + *(int *)(param_1 + 0x94);
  local_1c[2] = local_1c[2] + *(int *)(param_1 + 0x98);
  local_1c[3] = local_1c[3] + *(int *)(param_1 + 0x90);
  local_c = local_c + *(int *)(param_1 + 0x94);
  local_8 = local_8 + *(int *)(param_1 + 0x98);
  piVar2 = local_1c;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_3 = *piVar2;
    piVar2 = piVar2 + 1;
    param_3 = param_3 + 1;
  }
  local_8 = 0x40da09;
  __chkesp();
  return;
}

