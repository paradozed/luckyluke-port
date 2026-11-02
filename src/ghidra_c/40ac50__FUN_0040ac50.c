/* FUN_0040ac50 @ 0040ac50 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040ac50(undefined4 param_1,void *param_2)

{
  short sVar1;
  ushort uVar2;
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
  FUN_00468c20(uVar2,sVar1);
  uStack_8 = 0x40ac97;
  __chkesp();
  return;
}

