/* FUN_0041a140 @ 0041a140 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041a140(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_4c [16];
  int local_c;
  int local_8;
  
  puVar3 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = *(int *)(&DAT_004f1e40 + sVar1 * 4);
  sVar1 = FUN_004074b0(param_2,3);
  local_c = *(int *)(&DAT_004f1e40 + sVar1 * 4);
  FUN_00419f60(local_8,local_c);
  local_8 = 0x41a1a3;
  __chkesp();
  return;
}

