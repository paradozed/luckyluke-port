/* FUN_0041c670 @ 0041c670 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041c670(undefined4 param_1,void *param_2)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar6 = local_44;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = 0xcccccccc;
    puVar6 = puVar6 + 1;
  }
  sVar1 = FUN_004074b0(param_2,6);
  sVar2 = FUN_004074b0(param_2,5);
  sVar3 = FUN_004074b0(param_2,4);
  iVar5 = sVar3 * 100;
  sVar3 = FUN_004074b0(param_2,3);
  iVar4 = sVar3 * 100;
  sVar3 = FUN_004074b0(param_2,2);
  FUN_0041c3e0(sVar3 * 100,iVar4,iVar5,sVar2,sVar1);
  uStack_8 = 0x41c6ec;
  __chkesp();
  return;
}

