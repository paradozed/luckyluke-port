/* FUN_0040ca80 @ 0040ca80 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040ca80(int param_1,void *param_2)

{
  short sVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar7 = local_48;
  for (iVar6 = 0x11; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar7 = 0xcccccccc;
    puVar7 = puVar7 + 1;
  }
  sVar1 = FUN_004074b0(param_2,6);
  if (sVar1 < 0) {
    sVar1 = sVar1 + 0xfff;
  }
  local_8 = CONCAT22(local_8._2_2_,sVar1);
  uVar2 = FUN_004074b0(param_2,5);
  uVar3 = FUN_004074b0(param_2,4);
  uVar4 = FUN_004074b0(param_2,3);
  uVar5 = FUN_004074b0(param_2,2);
  iVar6 = FUN_00407580(param_1);
  FUN_004471b0(*(int *)(iVar6 + 8),uVar5,uVar4,uVar3,uVar2,sVar1);
  local_8 = 0x40cb0d;
  __chkesp();
  return;
}

