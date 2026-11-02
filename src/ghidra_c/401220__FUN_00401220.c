/* FUN_00401220 @ 00401220 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00401220(void *param_1,int param_2,undefined4 *param_3,int *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  int local_c;
  undefined4 local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_2 + -1;
  switch(param_2) {
  case 1:
    FUN_004016a0(param_1,param_3,param_4);
    break;
  case 2:
    FUN_00401550((int)param_1);
    break;
  case 3:
    FUN_00401f80(param_1,param_3,param_4);
    break;
  default:
    break;
  case 5:
    FUN_00401350((int)param_1);
    break;
  case 8:
    *(char *)((int)param_1 + 0xe9) = *(char *)((int)param_1 + 0xe9) + -1;
    break;
  case 9:
    FUN_00425f00((void *)((int)param_1 + 0xe8),param_3);
    break;
  case 0x10:
    FUN_00401a10(param_1,param_3);
  }
  local_8 = 0x401312;
  __chkesp();
  return;
}

