/* FUN_0040b320 @ 0040b320 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040b320(undefined4 param_1,void *param_2)

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
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = **(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  sVar1 = FUN_004081b0(local_8);
  local_c = (int)sVar1;
  sVar1 = FUN_004074b0(param_2,3);
  sVar2 = FUN_004074b0(param_2,4);
  if (local_c < (int)sVar1 + (int)sVar2) {
    sVar2 = 0;
    sVar1 = FUN_004074b0(param_2,4);
    FUN_004087d0(local_8,0,(short)local_c + sVar1,sVar2);
  }
  local_8 = 0x40b3c0;
  __chkesp();
  return;
}

