/* FUN_0041d680 @ 0041d680 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041d680(undefined4 param_1,void *param_2)

{
  short sVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar7 = local_44;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = 0xcccccccc;
    puVar7 = puVar7 + 1;
  }
  sVar1 = FUN_004074b0(param_2,7);
  uVar4 = (uint)sVar1;
  sVar1 = FUN_004074b0(param_2,6);
  sVar2 = FUN_004074b0(param_2,5);
  sVar3 = FUN_004074b0(param_2,4);
  iVar5 = sVar3 * 100;
  sVar3 = FUN_004074b0(param_2,3);
  iVar6 = sVar3 * 100;
  sVar3 = FUN_004074b0(param_2,2);
  FUN_0041d430(sVar3 * 100,iVar6,iVar5,sVar2,sVar1,uVar4);
  uStack_8 = 0x41d70a;
  __chkesp();
  return;
}

