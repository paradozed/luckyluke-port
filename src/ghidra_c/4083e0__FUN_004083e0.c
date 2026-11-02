/* FUN_004083e0 @ 004083e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004083e0(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  int local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = **(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  FUN_004081b0(local_8);
  local_8 = 0x40842d;
  __chkesp();
  return;
}

