/* FUN_0040a5d0 @ 0040a5d0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040a5d0(int param_1,void *param_2)

{
  short sVar1;
  uint uVar2;
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
  local_c = **(int **)(local_8 + 8);
  sVar1 = FUN_004074b0(param_2,3);
  uVar2 = (uint)sVar1;
  sVar1 = FUN_004074b0(param_2,2);
  FUN_00407700(local_c,**(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8),uVar2);
  local_8 = 0x40a63f;
  __chkesp();
  return;
}

