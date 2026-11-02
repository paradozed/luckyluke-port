/* FUN_00415130 @ 00415130 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00415130(undefined4 param_1,void *param_2)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar4 = local_44;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  uVar2 = FUN_004074b0(param_2,5);
  uVar6 = (undefined1)uVar2;
  uVar2 = FUN_004074b0(param_2,4);
  uVar5 = (undefined1)uVar2;
  uVar2 = FUN_004074b0(param_2,3);
  uVar1 = (undefined1)uVar2;
  uVar2 = FUN_004074b0(param_2,2);
  FUN_00449460((char)uVar2,uVar1,uVar5,uVar6);
  uStack_8 = 0x415189;
  __chkesp();
  return;
}

