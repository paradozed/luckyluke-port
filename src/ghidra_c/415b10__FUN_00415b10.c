/* FUN_00415b10 @ 00415b10 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00415b10(int param_1,void *param_2)

{
  byte bVar1;
  short sVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined1 uVar7;
  char cVar8;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar6 = local_44;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0xcccccccc;
    puVar6 = puVar6 + 1;
  }
  sVar2 = FUN_004074b0(param_2,6);
  uVar3 = FUN_004074b0(param_2,5);
  uVar4 = FUN_004074b0(param_2,4);
  cVar8 = (char)uVar4;
  uVar4 = FUN_004074b0(param_2,3);
  uVar7 = (undefined1)uVar4;
  uVar4 = FUN_004074b0(param_2,2);
  bVar1 = (byte)uVar4;
  iVar5 = FUN_00407580(param_1);
  FUN_00447350(*(int *)(iVar5 + 8),bVar1,uVar7,cVar8,uVar3,sVar2);
  uStack_8 = 0x415b80;
  __chkesp();
  return;
}

