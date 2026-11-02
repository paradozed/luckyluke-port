/* FUN_00419f00 @ 00419f00 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00419f00(int param_1,void *param_2)

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
  local_8 = FUN_00407580(param_1);
  sVar1 = FUN_004074b0(param_2,2);
  local_c = *(int *)(&DAT_004f1e40 + sVar1 * 4);
  FUN_00419f60(local_8,local_c);
  local_8 = 0x419f57;
  __chkesp();
  return;
}

