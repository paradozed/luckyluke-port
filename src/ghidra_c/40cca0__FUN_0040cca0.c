/* FUN_0040cca0 @ 0040cca0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040cca0(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_7c [16];
  int local_3c [6];
  int local_24 [6];
  int local_c;
  int local_8;
  
  puVar3 = local_7c;
  for (iVar2 = 0x1e; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = *(int *)(&DAT_004f1e40 + sVar1 * 4);
  sVar1 = FUN_004074b0(param_2,3);
  local_c = *(int *)(&DAT_004f1e40 + sVar1 * 4);
  FUN_0040da10(*(int **)(local_8 + 8),0,local_24);
  FUN_0040da10(*(int **)(local_c + 8),0,local_3c);
  FUN_004589e0(local_24,local_3c);
  local_8 = 0x40cd31;
  __chkesp();
  return;
}

