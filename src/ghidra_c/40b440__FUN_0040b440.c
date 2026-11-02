/* FUN_0040b440 @ 0040b440 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040b440(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_5c [16];
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_c;
  int local_8;
  
  puVar3 = local_5c;
  for (iVar2 = 0x16; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = **(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  local_c = **(int **)(*(int *)(DAT_004f2458 + 0x9c) + 8);
  local_1c = *(undefined4 *)(local_c + 0x90);
  local_18 = *(undefined4 *)(local_c + 0x94);
  local_14 = *(undefined4 *)(local_c + 0x98);
  FUN_00408d40(local_8,local_1c,local_18,local_14);
  local_8 = 0x40b4d4;
  __chkesp();
  return;
}

