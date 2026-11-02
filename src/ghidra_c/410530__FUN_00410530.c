/* FUN_00410530 @ 00410530 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00410530(int param_1,void *param_2)

{
  short sVar1;
  short sVar2;
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
  sVar1 = FUN_004074b0(param_2,3);
  local_c = (int)sVar1;
  if ((((DAT_004e85b8 == 0xf) && (*(short *)(local_8 + 0xc) == 0x17)) &&
      (*DAT_004f58a8 == 0x536f6674)) &&
     ((DAT_004f2584 != 0 && (local_c = 0x800 - local_c, local_c < 0)))) {
    local_c = 0;
  }
  sVar1 = FUN_004074b0(param_2,4);
  iVar3 = local_c;
  sVar2 = FUN_004074b0(param_2,2);
  FUN_00411bd0(**(int **)(local_8 + 8),sVar2,(short)iVar3,sVar1);
  local_8 = 0x4105e6;
  __chkesp();
  return;
}

