/* FUN_004193d0 @ 004193d0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004193d0(void *param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined4 local_58 [16];
  ushort *local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar3 = local_58;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,4);
  local_c = (int)sVar1;
  local_10 = FUN_00407580((int)param_1);
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = (int)sVar1;
  *(short *)(*(int *)(local_10 + 8) + 0x18) = sVar1;
  local_14 = **(int **)(local_10 + 8);
  local_18 = (ushort *)(DAT_004e8820 + *(int *)(DAT_004e8820 + 4 + local_8 * 4));
  if (local_c == -1) {
    local_c = *local_18 - 1;
  }
  uVar5 = 0;
  uVar4 = 0;
  iVar2 = local_c;
  sVar1 = FUN_004074b0(param_2,3);
  FUN_004850b0(local_14,(int)local_18,sVar1,(short)iVar2,uVar4,uVar5);
  FUN_00418f70(local_14,FUN_00419230,param_1);
  FUN_00418fe0(local_14,0);
  FUN_00417250(param_1,2,1);
  local_8 = 0x4194b4;
  __chkesp();
  return;
}

