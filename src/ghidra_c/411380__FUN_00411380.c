/* FUN_00411380 @ 00411380 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00411380(int param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_4c [16];
  undefined2 local_c;
  int local_8;
  
  puVar3 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = FUN_00407580(param_1);
  local_c = FUN_004074b0(param_2,3);
  sVar1 = FUN_004074b0(param_2,2);
  if (sVar1 == 0) {
    *(ushort *)(local_8 + 0xe) = *(ushort *)(local_8 + 0xe) & 0xfffb;
  }
  else {
    *(ushort *)(local_8 + 0xe) = *(ushort *)(local_8 + 0xe) | 4;
  }
  local_8 = 0x4113f5;
  __chkesp();
  return;
}

