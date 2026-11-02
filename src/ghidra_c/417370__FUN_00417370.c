/* FUN_00417370 @ 00417370 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00417370(undefined4 param_1,void *param_2)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar4 = local_44;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  sVar1 = FUN_004074b0(param_2,3);
  uVar2 = FUN_004074b0(param_2,2);
  FUN_0041f9f0((char)uVar2,sVar1);
  uStack_8 = 0x4173b3;
  __chkesp();
  return;
}

