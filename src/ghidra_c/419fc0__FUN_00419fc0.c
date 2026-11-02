/* FUN_00419fc0 @ 00419fc0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00419fc0(int param_1,void *param_2)

{
  short sVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_4c [16];
  undefined4 *local_c;
  int local_8;
  
  puVar6 = local_4c;
  for (iVar5 = 0x12; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0xcccccccc;
    puVar6 = puVar6 + 1;
  }
  local_8 = FUN_00407580(param_1);
  sVar1 = FUN_004074b0(param_2,3);
  local_c = *(undefined4 **)(&DAT_004f1e40 + sVar1 * 4);
  uVar2 = FUN_004074b0(param_2,5);
  uVar3 = FUN_004074b0(param_2,2);
  iVar5 = local_8;
  uVar4 = FUN_004074b0(param_2,4);
  FUN_00419a50(local_c,uVar4,iVar5,uVar3,uVar2);
  local_8 = 0x41a03e;
  __chkesp();
  return;
}

