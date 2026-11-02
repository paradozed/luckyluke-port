/* FUN_00412f20 @ 00412f20 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00412f20(int param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_50 [16];
  short local_10;
  short local_c;
  int local_8;
  
  puVar3 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = FUN_00407580(param_1);
  local_c = FUN_004074b0(param_2,3);
  local_10 = FUN_004074b0(param_2,2);
  local_c = (short)(local_c * 0x100 + (local_c * 0x100 >> 0x1f & 0xffU) >> 8);
  if (DAT_004e85b8 != 1) {
    local_c = (short)((uint)(local_c * DAT_004be3cc) >> 8);
    local_10 = (short)((uint)(local_10 * DAT_004be3c8) >> 9);
  }
  sVar1 = FUN_004074b0(param_2,4);
  FUN_00411c90(**(int **)(local_8 + 8),(int)local_10,(int)local_c,(int)sVar1);
  local_8 = 0x412fd9;
  __chkesp();
  return;
}

