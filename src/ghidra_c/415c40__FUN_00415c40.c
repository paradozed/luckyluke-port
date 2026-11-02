/* FUN_00415c40 @ 00415c40 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00415c40(int param_1,void *param_2)

{
  byte bVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  int iVar7;
  undefined4 *puVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  undefined2 uVar6;
  
  puVar8 = local_44;
  for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar8 = 0xcccccccc;
    puVar8 = puVar8 + 1;
  }
  uVar2 = FUN_004074b0(param_2,9);
  bVar11 = (byte)uVar2;
  uVar2 = FUN_004074b0(param_2,8);
  bVar10 = (byte)uVar2;
  uVar2 = FUN_004074b0(param_2,7);
  bVar9 = (byte)uVar2;
  uVar2 = FUN_004074b0(param_2,6);
  uVar3 = FUN_004074b0(param_2,5);
  uVar4 = FUN_004074b0(param_2,4);
  uVar5 = FUN_004074b0(param_2,3);
  uVar6 = FUN_004074b0(param_2,2);
  bVar1 = (byte)uVar6;
  iVar7 = FUN_00407580(param_1);
  FUN_00446d40(*(int *)(iVar7 + 8),bVar1,uVar5,uVar4,uVar3,uVar2,bVar9,bVar10,bVar11);
  uStack_8 = 0x415cd1;
  __chkesp();
  return;
}

